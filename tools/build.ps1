# Create the build directory if it doesn't exist
if (-Not (Test-Path -Path "../build")) 
{
    New-Item -ItemType Directory -Path "../build"
}

# Preserve our calling directory, so running this script doesn't change our location in the shell.
$currDirectory = Get-Location

# Navigate to the build directory
Set-Location -Path "../build"

# Run CMake and build the project
cmake ..
cmake --build .

# Optionally, run the project (uncomment if needed)
# Start-Process -NoNewWindow "./bin/mario_core"

# Restore the directory which we called from
Set-Location -Path $currDirectory
