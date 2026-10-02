using System.IO;
using System.Reflection;

namespace ProjectAgentGateV.Services;

/// <summary>Loads the ONNX asset stored in the application assembly.</summary>
public static class EmbeddedOnnxModel
{
    public const string ResourceName = "ProjectAgentGateV.Assets.fpga_net.onnx";
    public const string ReportDescription = "Embedded ONNX resource · fpga_net.onnx";

    public static byte[] Load()
    {
        Assembly assembly = typeof(EmbeddedOnnxModel).Assembly;
        using Stream resource = assembly.GetManifestResourceStream(ResourceName)
            ?? throw new InvalidDataException("The embedded inference model is missing from this application build.");

        if (resource.Length <= 0 || resource.Length > int.MaxValue)
            throw new InvalidDataException("The embedded inference model has an invalid size.");

        var modelBytes = new byte[(int)resource.Length];
        int offset = 0;
        while (offset < modelBytes.Length)
        {
            int read = resource.Read(modelBytes, offset, modelBytes.Length - offset);
            if (read == 0) throw new EndOfStreamException("The embedded inference model ended unexpectedly.");
            offset += read;
        }

        return modelBytes;
    }
}
