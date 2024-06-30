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

$buildDir = Join-Path -Path $PSScriptRoot -ChildPath "..\build"
$oldTest = "../test/dump/last_test_output.txt"
$verboseTest = "../test/dump/last_test_output_verbose.txt"
$hint = "Use { .\build.ps1 }"

if ((Test-Path -Path "../build")) 
{
    Remove-Item -Recurse -Force -Path $buildDir
    Write-Host "Build directory removed." -ForegroundColor Green

    # brief: if the build existed, we might have ran tests, clear any old output as well
    if (Test-Path -Path $oldTest)
    {
        Remove-Item -Force -Path $oldTest
        Write-Host "Old Test output cleared." -ForegroundColor Green
    }
    if (Test-Path -Path $verboseTest)
    {
        Remove-Item -Force -Path $verboseTest
        Write-Host "Old Verbose Test output cleared." -ForegroundColor Green
    }
}
else
{
    Write-Host "Build directory does not exist. $hint" -ForegroundColor Red
    exit 1
}