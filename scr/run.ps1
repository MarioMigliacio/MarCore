###################################################################################################
#  TEMPORARILY DEPRECATED BUT NOT REMOVED                                                         #
# Author: Mario Migliacio                                                                         #
# @file: run.ps1                                                                                  #
# \brief: Most simplistic form of run test executable                                             #
#                                                                                                 #
# \Expects: ..\build folder exists and was generated with CMakeLists.txt                          #
#                                                                                                 #
# \Success: Runs the executable application                                                       #
#           Display Ran modules in MAGENTA prompt                                                 #
#           Test results in GREEN if assertions all pass                                          #
#           Test results in RED or YELLOW if test fails/ Total tests < 100%                       #
#    A test_output folder containing summary, and verbose output are generated on ./run.ps1       #
#                                                                                                 #
# \Failure: Display that ..\build does not exist in RED prompt                                    #
#                                                                                                 #
###################################################################################################

# Note: The scriptDir, projectRoot, and exeDir allows this script to be invoked from anywhere. 
#       This allows the use of .\scr\run.ps1 from even the root directory, or inside the \scr directly.

# Get the directory of the current script
$scriptDir = Split-Path -Parent -Path $MyInvocation.MyCommand.Definition

# Define the project root and executable directory
$projectRoot = (Resolve-Path "$scriptDir\..").Path
$exeDir = "$projectRoot\build\bin\Debug"

# Define the executable path
$exePath = "$exeDir\MC_tests.exe"

# Define the output file path and the dump directory
$outputFile = "$exeDir\last_test_output.txt"
$dumpDir = "$projectRoot\test_output\"

function Run-TestExecutable
{
    # Check if the executable exists
    if (-Not (Test-Path -Path $exePath))
    {
        Write-Host "Executable not found: $exePath" -ForegroundColor Red
        exit 1
    }

    # Preserve our calling directory, so running this script doesn't change our location in the shell.
    $originalDir = Get-Location

    # Change to the executable directory
    Set-Location -Path $exeDir

    # Run the executable
    & $exePath

    # Return to the original directory
    Set-Location -Path $originalDir
}

function Run-CopyFileOutput
{
    # Create the dump directory if it does not exist
    if (-Not (Test-Path -Path $dumpDir))
    {
        New-Item -ItemType Directory -Path $dumpDir
    }

    # Check if the output file exists and copy it to the dump directory
    if (Test-Path -Path $outputFile)
    {
        $outputFileName = "last_test_output_verbose.txt"
        $outputFileExtension = [System.IO.Path]::GetExtension($outputFile)
        $newOutputFile = "$dumpDir$outputFileName$outputFileExtension"
        Copy-Item -Path $outputFile -Destination $newOutputFile
        Write-Host "See MarCore\test_output folder for recent test activity" -ForegroundColor Magenta
    }
    else
    {
        Write-Host "Unable to write Output file: $outputFile" -ForegroundColor Red
    }
}

function Run-TestStatistics
{
    # Initialize a hashtable to store test results grouped by test name
    $testResults = @{}
    $module_pattern = "\b[\w\-\.]+\.c\b"
    $summaryFile = "$dumpDir\last_test_output_summary.txt"

    # Read the file line by line
    $lines = Get-Content -Path $outputFile

    foreach ($line in $lines)
    {
        # Regex pattern refers to the <mc>_<test>_<module>_<name>.c pattern PRIMARY KEY
        if ($line -match $module_pattern)
        {
            $currentModule = $Matches[0]
            if (-not $testResults.ContainsKey($currentModule))
            {
                $testResults[$currentModule] = @{}
            }
        }

        # get the Name of the test from the line up to  the first ':'
        $testName = $line.SubString(0, $line.IndexOf(":"))

        # get the PASS or FAIL status from the line
        if ($line -match "PASSED")
        {
            $testResult = "PASSED"
        }
        elseif ($line -match "FAILED")
        {
            $testResult = "FAILED"
        }
        
        if (-not $testResults[$currentModule].ContainsKey($testName))
        {
            $testResults[$currentModule][$testName] = @{
                PASSED = 0
                FAILED = 0
            }
        }

        $testResults[$currentModule][$testName][$testResult]++
    }

    # Initialize counters
    $totalTests = 0
    $totalPassed = 0
    $totalFailed = 0

    $summary = ""   # for file summary

    # Output the organized test results
    foreach ($moduleName in $testResults.Keys)
    {
        Write-Host "Module: $moduleName" -ForegroundColor Magenta   # direct to console
        $summary += "Module: $moduleName`n"                         # for file summary
        $moduleResults = $testResults[$moduleName]
        $modulePassed = 0
        $moduleFailed = 0

        foreach ($testName in $moduleResults.Keys)
        {
            $testStats = $moduleResults[$testName]
            $testPassed = $testStats.PASSED
            $testFailed = $testStats.FAILED
            $modulePassed += $testPassed
            $moduleFailed += $testFailed
            
            if ($testFailed -eq 0)
            {
                Write-Host ("`tTest: {0} - Passed: {1}, Failed: {2}" -f $testName, $testPassed, $testFailed) -ForegroundColor Green    # direct to console
            }
            else
            {
                Write-Host ("`tTest: {0} - Passed: {1}, Failed: {2}" -f $testName, $testPassed, $testFailed) -ForegroundColor Yellow    # direct to console
            }
            $summary += ("`tTest: {0} - Passed: {1}, Failed: {2}`n" -f $testName, $testPassed, $testFailed) # for file summary
        }

        $moduleTotal = $modulePassed + $moduleFailed

        if ($moduleFailed -eq 0)
        {
            Write-Host ("`tModule Summary: {0} Tests, {1} Passed, {2} Failed" -f $moduleTotal, $modulePassed, $moduleFailed) -ForegroundColor Green    # direct to console
        }
        else
        {
            Write-Host ("`tModule Summary: {0} Tests, {1} Passed, {2} Failed" -f $moduleTotal, $modulePassed, $moduleFailed) -ForegroundColor Yellow   # direct to console
        }
        $summary += ("`tModule Summary: {0} Tests, {1} Passed, {2} Failed`n`n" -f $moduleTotal, $modulePassed, $moduleFailed)   # for file summary
        Write-Host ""   # direct to console

        # Update overall counters
        $totalPassed += $modulePassed
        $totalFailed += $moduleFailed
        $totalTests += $moduleTotal
    }

    # Output overall summary
    $passRate = [math]::Round(($totalPassed / $totalTests) * 100, 2)
    $failRate = [math]::Round(($totalFailed / $totalTests) * 100, 2)
    Write-Host "Overall Summary:" -ForegroundColor Magenta                                          # direct to console
    Write-Host ("`tTotal Tests: {0}" -f $totalTests) -ForegroundColor Magenta                       # direct to console
    $summary += "Overall Summary:`n"                                        # for file summary
    $summary += ("`tTotal Tests: {0}`n" -f $totalTests)                     # for file summary
    
    if ($totalFailed -eq 0)
    {
        Write-Host ("`tTotal Passed: {0} ({1}%)" -f $totalPassed, $passRate) -ForegroundColor Green    # direct to console
        Write-Host ("`tTotal Failed: {0} ({1}%)" -f $totalFailed, $failRate) -ForegroundColor Green    # direct to console
    }
    else
    {
        Write-Host ("`tTotal Passed: {0} ({1}%)" -f $totalPassed, $passRate) -ForegroundColor Yellow   # direct to console
        Write-Host ("`tTotal Failed: {0} ({1}%)" -f $totalFailed, $failRate) -ForegroundColor Red   # direct to console
    }

    $summary += ("`tTotal Passed: {0} ({1}%)`n" -f $totalPassed, $passRate)    # for file summary
    $summary += ("`tTotal Failed: {0} ({1}%)`n" -f $totalFailed, $failRate)    # for file summary

    # Conditional coloring based on pass rate
    if ($passRate -eq 100)
    {
        Write-Host "All tests passed!" -ForegroundColor Green   # direct to console
        $summary += "All tests passed!"                       # for file summary

    }
    elseif ($passRate -ge 50)
    {
        Write-Host "More than half of the tests passed." -ForegroundColor Yellow    # direct to console
        $summary += "More than half of the tests passed."                         # for file summary
    }
    else
    {
        Write-Host "Less than half of the tests passed." -ForegroundColor Red   # direct to console
        $summary += "Less than half of the tests passed."                     # for file summary
    }

    # Also write the summary to file
    $outFile = $summaryFile
    Set-Content -Path $outFile -Value $summary
}

Run-TestExecutable
Run-CopyFileOutput
Run-TestStatistics
