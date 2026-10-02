[CmdletBinding()]
param(
    [ValidateSet('win-x64', 'win-arm64')]
    [string] $RuntimeIdentifier = 'win-x64',

    [ValidateSet('Release', 'Debug')]
    [string] $Configuration = 'Release'
)

$ErrorActionPreference = 'Stop'
$projectPath = Join-Path $PSScriptRoot 'src\ProjectAgentGateV\ProjectAgentGateV.csproj'
$embeddedModel = Join-Path $PSScriptRoot 'src\ProjectAgentGateV\Assets\fpga_net.onnx'
$publishDirectory = Join-Path $PSScriptRoot "dist\Project-AgentGate-V\$RuntimeIdentifier"

if (-not (Test-Path -LiteralPath $projectPath -PathType Leaf)) {
    throw "Project file not found: $projectPath"
}
if (-not (Test-Path -LiteralPath $embeddedModel -PathType Leaf)) {
    throw "Embedded model asset not found: $embeddedModel. Export the trained checkpoint to this ONNX file before publishing."
}

Write-Host "Publishing Project-AgentGate-V ($RuntimeIdentifier, $Configuration)..."
# This is a single-file app. Remove old loose assemblies/native runtime files and
# the previous side-by-side model from folder-based publishes, while preserving
# the benchmark_reports directory and any user-selected datasets elsewhere.
if (Test-Path -LiteralPath $publishDirectory -PathType Container) {
    Get-ChildItem -LiteralPath $publishDirectory -File -Filter '*.dll' | Remove-Item -Force
    $obsoleteModel = Join-Path $publishDirectory 'fpga_net.onnx'
    if (Test-Path -LiteralPath $obsoleteModel -PathType Leaf) { Remove-Item -LiteralPath $obsoleteModel -Force }

    $obsoleteDataset = Join-Path $publishDirectory 'default_dataset'
    if (Test-Path -LiteralPath $obsoleteDataset -PathType Container) {
        $workspaceRoot = [System.IO.Path]::GetFullPath($PSScriptRoot).TrimEnd([System.IO.Path]::DirectorySeparatorChar) + [System.IO.Path]::DirectorySeparatorChar
        $resolvedDataset = (Resolve-Path -LiteralPath $obsoleteDataset -ErrorAction Stop).Path
        if (-not $resolvedDataset.StartsWith($workspaceRoot, [System.StringComparison]::OrdinalIgnoreCase)) {
            throw "Refusing to remove a dataset outside the application workspace: $resolvedDataset"
        }
        Remove-Item -LiteralPath $resolvedDataset -Recurse -Force
    }
}
& dotnet publish $projectPath `
    --configuration $Configuration `
    --runtime $RuntimeIdentifier `
    --self-contained true `
    --output $publishDirectory `
    -p:PublishSingleFile=true `
    -p:PublishTrimmed=false `
    -p:IncludeNativeLibrariesForSelfExtract=true `
    -p:IncludeAllContentForSelfExtract=false
if ($LASTEXITCODE -ne 0) {
    throw "dotnet publish failed with exit code $LASTEXITCODE"
}

if (Test-Path -LiteralPath (Join-Path $publishDirectory 'fpga_net.onnx') -PathType Leaf) {
    throw 'The model unexpectedly published as a loose file. Check the EmbeddedResource configuration.'
}

Write-Host "Embedded model: $embeddedModel ($((Get-Item -LiteralPath $embeddedModel).Length.ToString('N0')) bytes)"
Write-Host "Single-file publish complete: $publishDirectory"
