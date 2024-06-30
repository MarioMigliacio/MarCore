###################################################################################################
#                                                                                                 #
# Author: Mario Migliacio                                                                         #
# @file: run.ps1                                                                                  #
# \brief: Most simplistic form of run exe                                                         #
#                                                                                                 #
# \Expects: ..\build folder exists and was generated with CMakeLists.txt                          #
#                                                                                                 #
# \Params: NONE                                                                                   #
#                                                                                                 #
# \Success: Runs the executable application                                                       #
#           Display Run status in MAGENTA prompt                                                  #
#                                                                                                 #
# \Failure: Display that ..\build does not exist in RED prompt                                    #
#                                                                                                 #
###################################################################################################

$buildDir = Join-Path -Path $PSScriptRoot -ChildPath "..\build"
$hint = "Use { .\build.ps1 }"

try
{
    Write-Host "Build and Run Started." -ForegroundColor Magenta
    ../build/bin/Debug/mario_core
    Write-Host "Build and Run Concluded." -ForegroundColor Magenta
}
catch
{
    Write-Host "Build directory does not exist. $hint" -ForegroundColor Red
    exit 1
}