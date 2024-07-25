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
$testDir = "$projectRoot\build\MC"
$outputFile = "$projectRoot\build\MC\Testing\Temporary\LastTest.log"
$dumpDir = "$projectRoot\test_output\"

function simpleTest
{
    # Preserve our calling directory, so running this script doesn't change our location in the shell.
    $originalDir = Get-Location

    # Change to the project root directory
    Set-Location -Path $testDir

    # Create the build/bin directory structure and place all the executables and libraries
    ctest -V -C Debug

    # Return to the original directory
    Set-Location -Path $originalDir
}

function copyFile
{
    # Create the dump directory if it does not exist
    if (-Not (Test-Path -Path $dumpDir))
    {
        New-Item -ItemType Directory -Path $dumpDir
    }

    # Check if the output file exists and copy it to the dump directory
    if (Test-Path -Path $outputFile)
    {
        $outputFileName = "LastTest.log"
        $newOutputFile = "$dumpDir$outputFileName"
        Copy-Item -Path $outputFile -Destination $newOutputFile
        Write-Host "See MarCore\test_output folder for recent test activity" -ForegroundColor Magenta
    }
    else
    {
        Write-Host "Unable to write Output file: $outputFile" -ForegroundColor Red
    }
}

simpleTest
copyFile