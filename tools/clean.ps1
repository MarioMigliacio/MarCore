# Path to the build directory
$buildDir = Join-Path -Path $PSScriptRoot -ChildPath "..\build"

# Check if the build directory exists
if (Test-Path -Path $buildDir) 
{

    Remove-Item -Recurse -Force -Path $buildDir
    Write-Output "Build directory removed."
} 
else 
{
    Write-Output "Build directory does not exist."
}