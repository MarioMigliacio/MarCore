###################################################################################################
#                                                                                                 #
# Author: Mario Migliacio                                                                         #
# @file: build.ps1                                                                                #
# \brief: Build convenience script, allows for additional flags to customize the build process    #
#                                                                                                 #
# \Expects: No expectations are made prior to executing build.ps1                                 #
#                                                                                                 #
# \Params: -r [RUN] run the application after build                                               #
#          -c [CLEAN] clean the application before build                                          #
#          -t [TEST] compile an output test file for after build                                  #
#                                                                                                 #
# \Success: The application has been built                                                        #
#           Display build status in MAGENTA prompt                                                #
#                                                                                                 #
# \Failure: Display that ..\build does not exist in RED prompt                                    #
#                                                                                                 #
###################################################################################################

param (
    [switch]$r,
    [switch]$c,
    [switch]$t
)

function createBuildDir
{
    # MUST: Create the build directory if it doesn't exist
    if (-Not (Test-Path -Path "../build")) 
    {
        New-Item -ItemType Directory -Path "../build"
    }
}

function simpleBuild
{
    # Preserve our calling directory, so running this script doesn't change our location in the shell.
    $currDirectory = Get-Location

    # Navigate to the build directory
    Set-Location -Path "../build"

    # Run CMake and build the project
    cmake ..
    cmake --build .

    # Restore the directory which we called from
    Set-Location -Path $currDirectory
}

function cleanBuild
{
    . ./clean.ps1
}

function runBuild
{
    . ./run.ps1
}

function testOutput
{
    . ./test.ps1
}

# Locically number 1 to run.
if ($c)
{
    cleanBuild
}

# Actual build.
try
{
    Write-Host "Standard Build Started." -ForegroundColor Magenta
    createBuildDir
    simpleBuild
    Write-Host "Standard Build Concluded." -ForegroundColor Magenta
}
catch
{
    Write-Host "Build Failed." -ForegroundColor Red
    exit 1
}

# Logically number 2 to run.
if ($t)
{
    testOutput
}

# Run if requested after build.
if ($r)
{
    runBuild
}