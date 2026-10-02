[CmdletBinding()]
param([ValidateRange(1, 1000)][int]$ImagesPerClass = 20)

$ErrorActionPreference = 'Stop'
$source = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..\model_training\dataset'))
$destination = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\src\ProjectAgentGateV\Assets\default_dataset'))
$classes = @('(', ')', '+', '-', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '=', 'X', 'forward_slash', 'times', 'y')
$extensions = @('.png', '.jpg', '.jpeg', '.bmp', '.gif', '.tif', '.tiff')

if (-not (Test-Path -LiteralPath $source -PathType Container)) { throw "Source dataset is missing: $source" }
if (Test-Path -LiteralPath $destination) { throw "Default sample already exists; remove it before regenerating: $destination" }
foreach ($class in $classes) {
    $sourceClass = Join-Path $source $class
    if (-not (Test-Path -LiteralPath $sourceClass -PathType Container)) { throw "Missing source class: $sourceClass" }
}

New-Item -ItemType Directory -Path $destination | Out-Null
$total = 0
foreach ($class in $classes) {
    $sourceClass = Join-Path $source $class
    $targetClass = Join-Path $destination $class
    New-Item -ItemType Directory -Path $targetClass | Out-Null
    $files = @(Get-ChildItem -LiteralPath $sourceClass -File | Where-Object { $extensions -contains $_.Extension.ToLowerInvariant() } | Sort-Object Name)
    if ($files.Count -lt $ImagesPerClass) { throw "Class '$class' has only $($files.Count) images; $ImagesPerClass requested." }
    $stride = [Math]::Max(1, [int][Math]::Floor($files.Count / $ImagesPerClass))
    for ($index = 0; $index -lt $ImagesPerClass; $index++) {
        $sourceFile = $files[[Math]::Min($index * $stride, $files.Count - 1)]
        Copy-Item -LiteralPath $sourceFile.FullName -Destination (Join-Path $targetClass $sourceFile.Name)
        $total++
    }
}

Write-Output "Bundled $total images across $($classes.Count) classes: $destination"
