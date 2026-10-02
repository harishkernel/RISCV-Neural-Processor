using ProjectAgentGateV.Models;
using System.IO;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;

namespace ProjectAgentGateV.Services;

public static class DatasetService
{
    public static readonly string[] ClassNames =
    ["(", ")", "+", "-", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "=", "X", "forward_slash", "times", "y"];

    private static readonly HashSet<string> SupportedExtensions = new(StringComparer.OrdinalIgnoreCase)
        { ".png", ".jpg", ".jpeg", ".bmp", ".gif", ".tif", ".tiff" };

    public static int ValidateRoot(string root, CancellationToken cancellationToken)
    {
        var result = InspectRoot(root, cancellationToken);
        if (!result.IsReady)
            throw new InvalidDataException($"The selected folder is missing supported images in these required classes: {string.Join(", ", result.MissingOrEmptyClasses)}. Select the dataset root containing all 19 class folders directly.");
        return result.ImageCount;
    }

    public static DatasetValidation InspectRoot(string root, CancellationToken cancellationToken)
    {
        if (!Directory.Exists(root)) throw new DirectoryNotFoundException($"The selected folder does not exist: {root}");

        var totalImages = 0;
        var populatedClasses = 0;
        var missing = new List<string>();
        foreach (var className in ClassNames)
        {
            cancellationToken.ThrowIfCancellationRequested();
            var classPath = Path.Combine(root, className);
            if (!Directory.Exists(classPath))
            {
                missing.Add(className);
                continue;
            }

            var classImages = 0;
            foreach (var file in Directory.EnumerateFiles(classPath, "*", SearchOption.AllDirectories))
            {
                cancellationToken.ThrowIfCancellationRequested();
                if (SupportedExtensions.Contains(Path.GetExtension(file))) classImages++;
            }
            if (classImages == 0) missing.Add(className);
            else populatedClasses++;
            totalImages += classImages;
        }

        return new DatasetValidation(Path.GetFullPath(root), populatedClasses, ClassNames.Length, totalImages, missing);
    }

    public static IReadOnlyList<DatasetImage> Enumerate(string root, CancellationToken cancellationToken)
    {
        if (!Directory.Exists(root)) throw new DirectoryNotFoundException($"Dataset folder not found: {root}");
        var images = new List<DatasetImage>();
        foreach (var className in ClassNames)
        {
            cancellationToken.ThrowIfCancellationRequested();
            var classPath = Path.Combine(root, className);
            if (!Directory.Exists(classPath)) throw new InvalidDataException($"The dataset is missing the '{className}' class folder.");
            var classIndex = Array.IndexOf(ClassNames, className);
            foreach (var file in Directory.EnumerateFiles(classPath, "*", SearchOption.AllDirectories))
            {
                cancellationToken.ThrowIfCancellationRequested();
                if (SupportedExtensions.Contains(Path.GetExtension(file))) images.Add(new DatasetImage(file, classIndex));
            }
        }
        if (images.Count == 0) throw new InvalidDataException("No supported image files were found in the 19 class folders.");
        return images;
    }

    public static float[] Preprocess(string imagePath)
    {
        using var source = new Bitmap(imagePath);
        using var resized = new Bitmap(28, 28, PixelFormat.Format24bppRgb);
        using (var graphics = Graphics.FromImage(resized))
        {
            graphics.Clear(Color.White);
            graphics.CompositingQuality = CompositingQuality.HighQuality;
            graphics.InterpolationMode = InterpolationMode.HighQualityBicubic;
            graphics.PixelOffsetMode = PixelOffsetMode.HighQuality;
            graphics.SmoothingMode = SmoothingMode.HighQuality;
            graphics.DrawImage(source, new Rectangle(0, 0, 28, 28));
        }

        var rect = new Rectangle(0, 0, 28, 28);
        var bits = resized.LockBits(rect, ImageLockMode.ReadOnly, PixelFormat.Format24bppRgb);
        try
        {
            int stride = Math.Abs(bits.Stride);
            var bytes = new byte[stride * 28];
            Marshal.Copy(bits.Scan0, bytes, 0, bytes.Length);
            var pixels = new float[28 * 28];
            double mean = 0;
            for (int y = 0; y < 28; y++)
            {
                int row = bits.Stride >= 0 ? y * stride : (27 - y) * stride;
                for (int x = 0; x < 28; x++)
                {
                    int offset = row + x * 3;
                    double gray = (bytes[offset + 2] * 0.299 + bytes[offset + 1] * 0.587 + bytes[offset] * 0.114) / 255d;
                    pixels[y * 28 + x] = (float)gray;
                    mean += gray;
                }
            }
            mean /= pixels.Length;
            if (mean < 0.5)
                for (int i = 0; i < pixels.Length; i++) pixels[i] = 1f - pixels[i];
            return pixels;
        }
        finally { resized.UnlockBits(bits); }
    }
}
