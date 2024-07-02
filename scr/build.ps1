###################################################################################################
#                                                                                                 #
# Author: Mario Migliacio                                                                         #
# @file: build.ps1                                                                                #
# \brief: Build convenience script, allows for additional flags to customize the build process    #
#                                                                                                 #
# \Expects: No expectations are made prior to executing build.ps1                                 #
#                                                                                                 #
# \Params: -c [CLEAN] clean the application before build                                          #
#          -r [RUN] run the application after build                                               #
#                                                                                                 #
# \Success: The application has been built                                                        #
#           Display build status in MAGENTA prompt                                                #
#                                                                                                 #
# \Failure: Display that ..\build does not exist in RED prompt                                    #
#                                                                                                 #
###################################################################################################

param (
    [switch]$c,
    [switch]$r
)

# Note: The scriptDir, projectRoot, and buildDir allows this script to be invoked from anywhere. 
#       This allows the use of .\scr\build.ps1 from even the root directory, or inside the \scr directly.

# Get the directory of the current script
$scriptDir = Split-Path -Parent -Path $MyInvocation.MyCommand.Definition

# Define the project root and build directory
$projectRoot = (Resolve-Path "$scriptDir\..").Path
$buildDir = "$projectRoot\build"

function createBuildDir
{
    # MUST: Create the build directory if it doesn't exist
    if (-Not (Test-Path -Path $buildDir)) 
    {
        New-Item -ItemType Directory -Path $buildDir
    }
}

function simpleBuild
{
    # Preserve our calling directory, so running this script doesn't change our location in the shell.
    $originalDir = Get-Location

    # Change to the project root directory
    Set-Location -Path $projectRoot

    # Create the build/bin directory structure and place all the executables and libraries
    cmake -S . -B $buildDir
    cmake --build $buildDir

    # Return to the original directory
    Set-Location -Path $originalDir
}

function cleanBuild
{
    $cleanPath = "$scriptDir\clean.ps1"
    & $cleanPath
    Write-Host "Clean Finished.. Rebuilding project." -ForegroundColor Magenta
}

function runBuild
{
    $runPath = "$scriptDir\run.ps1"
    $flag = $true
    & $runPath -d:$flag 
    Write-Host "Standard Run Finished." -ForegroundColor Magenta
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

# If we want to do a simple test run, execute it now.
if ($r)
{
    runBuild
}
