Add-Type -AssemblyName System.Drawing
$ErrorActionPreference = 'Stop'

$assetDirectory = Join-Path $PSScriptRoot '..\src\ProjectAgentGateV\Assets'
$sheetPath = [System.IO.Path]::GetFullPath((Join-Path $assetDirectory 'and-gate-spritesheet.png'))
$sheet = [System.Drawing.Bitmap]::new($sheetPath)
$large = [System.Drawing.Bitmap]::new(512, 512, [System.Drawing.Imaging.PixelFormat]::Format32bppArgb)
$graphics = [System.Drawing.Graphics]::FromImage($large)
$graphics.Clear([System.Drawing.Color]::Transparent)
$graphics.InterpolationMode = [System.Drawing.Drawing2D.InterpolationMode]::NearestNeighbor
$graphics.PixelOffsetMode = [System.Drawing.Drawing2D.PixelOffsetMode]::Half
$graphics.DrawImage($sheet, [System.Drawing.Rectangle]::new(32, 32, 448, 448), [System.Drawing.Rectangle]::new(0, 0, 32, 32), [System.Drawing.GraphicsUnit]::Pixel)

$previewPath = [System.IO.Path]::GetFullPath((Join-Path $assetDirectory 'Project-AgentGate-V.png'))
$large.Save($previewPath, [System.Drawing.Imaging.ImageFormat]::Png)

$sizes = @(256, 128, 64, 48, 32, 16)
$pngs = [System.Collections.Generic.List[byte[]]]::new()
foreach ($size in $sizes) {
    $small = [System.Drawing.Bitmap]::new($size, $size, [System.Drawing.Imaging.PixelFormat]::Format32bppArgb)
    $smallGraphics = [System.Drawing.Graphics]::FromImage($small)
    $smallGraphics.Clear([System.Drawing.Color]::Transparent)
    $smallGraphics.InterpolationMode = [System.Drawing.Drawing2D.InterpolationMode]::NearestNeighbor
    $smallGraphics.PixelOffsetMode = [System.Drawing.Drawing2D.PixelOffsetMode]::Half
    $inset = [int][Math]::Round($size / 16.0)
    $smallGraphics.DrawImage($large, [System.Drawing.Rectangle]::new($inset, $inset, $size - 2 * $inset, $size - 2 * $inset))
    $buffer = [System.IO.MemoryStream]::new()
    $small.Save($buffer, [System.Drawing.Imaging.ImageFormat]::Png)
    $pngs.Add($buffer.ToArray())
    $buffer.Dispose()
    $smallGraphics.Dispose()
    $small.Dispose()
}

$iconPath = [System.IO.Path]::GetFullPath((Join-Path $assetDirectory 'Project-AgentGate-V.ico'))
$stream = [System.IO.File]::Create($iconPath)
$writer = [System.IO.BinaryWriter]::new($stream)
$writer.Write([UInt16]0)
$writer.Write([UInt16]1)
$writer.Write([UInt16]$sizes.Count)
$offset = 6 + 16 * $sizes.Count
for ($i = 0; $i -lt $sizes.Count; $i++) {
    $size = $sizes[$i]
    $bytes = $pngs[$i]
    $dim = if ($size -eq 256) { 0 } else { $size }
    $writer.Write([Byte]$dim)
    $writer.Write([Byte]$dim)
    $writer.Write([Byte]0)
    $writer.Write([Byte]0)
    $writer.Write([UInt16]1)
    $writer.Write([UInt16]32)
    $writer.Write([UInt32]$bytes.Length)
    $writer.Write([UInt32]$offset)
    $offset += $bytes.Length
}
foreach ($bytes in $pngs) { $writer.Write([Byte[]]$bytes) }
$writer.Dispose()
$stream.Dispose()
$graphics.Dispose()
$large.Dispose()
$sheet.Dispose()
Write-Output "Wrote $iconPath"
Write-Output "Wrote $previewPath"
