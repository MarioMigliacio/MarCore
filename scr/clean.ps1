###################################################################################################
#                                                                                                 #
# Author: Mario Migliacio                                                                         #
# @file: clean.ps1                                                                                #
# \brief: Removes the build and last test artifacts from project                                  #
#                                                                                                 #
# \Expects: ..\build folder exists and was generated with CMakeLists.txt                          #
#                                                                                                 #
# \Params: NONE                                                                                   #
#                                                                                                 #
# \Success: The application's build folder, and last test output artifacts are removed            #
#           if Build directory existed, display its removal with GREEN prompt                     #
#           if Test output artifact existed, display its removal with GREEN prompt                #
#                                                                                                 #
# \Failure: Display that ..\build does not exist in RED prompt                                    #
#                                                                                                 #
###################################################################################################

# Note: The scriptDir, projectRoot, and buildDir allows this script to be invoked from anywhere. 
#       This allows the use of .\scr\build.ps1 from even the root directory, or inside the \scr directly.

# Get the directory of the current script
$scriptDir = Split-Path -Parent -Path $MyInvocation.MyCommand.Definition

# Define the project root and build directory
$projectRoot = (Resolve-Path "$scriptDir\..").Path
$buildDir = "$projectRoot\build"
$testDir = "$projectRoot\test_output"

# Clean any build artifact
if ((Test-Path -Path "../build")) 
{
    Remove-Item -Recurse -Force -Path $buildDir
    Write-Host "Build directory removed." -ForegroundColor Green
}

# Clean any test_output artifacts
if (Test-Path -Path $testDir)
{
    Remove-Item -Recurse -Force -Path $testDir
    Write-Host "Old Test output cleared." -ForegroundColor Green
}
