###################################################################################################
#                                                                                                 #
# Author: Mario Migliacio                                                                         #
# @file: test.ps1                                                                                 #
# \brief: Compiles an output test file for viewing                                                #
#                                                                                                 #
# \Expects: ..\build folder exists and was generated with CMakeLists.txt                          #
#                                                                                                 #
# \Params: -d [DISPLAY] Display simple test results in terminal and output to _output file        #
#          -v [VERBOSE] View detailed test results in terminal and output to _verbose file        #
#                                                                                                 #
# \Success: The application produces a test output file for viewing                               #
#           if DISPLAY requested, show test results in COLOR prompt and _output file              #
#           if VERBOSE requested, display advanced test statistics in terminal and _verbose file  #
#                                                                                                 #
# \Failure: Display that ..\build does not exist in RED prompt                                    #
#                                                                                                 #
###################################################################################################

param (
    [switch]$d,
    [switch]$v
)

$testDump = "../test/dump/last_test_output.txt"
$verboseDump = "../test/dump/last_test_output_verbose.txt"
$hint = "See { /test/dump/last_test_output.txt } for manual results."

# The bare minimum action for .\test.ps1: 
if ((Test-Path -Path "../build")) 
{
    ../build/bin/Debug/mario_core_test
    Write-Host "Test output has been logged. $hint" -ForegroundColor Green
} 
else 
{
    Write-Host "Build directory does not exist." -ForegroundColor Red
}

function verboseDisplay
{
    # Initialize a hashtable to store test results grouped by test name
    $testResults = @{}

    # Read the file line by line
    $lines = Get-Content -Path $testDump

    # Iterate through each line in the file
    foreach ($line in $lines)
    {
        $name = $line.SubString(0, $line.IndexOf(":"))
        if ($line -match "PASSED")
        {
            $result = "PASSED"
        }
        elseif ($line -match "FAILED")
        {
            $result = "FAILED"
        }

        # Initialize the hashtable for this test name
        if (-not $testResults.ContainsKey($name))
        {
            $testResults[$name] = @{
                Passed = 0
                Failed = 0
            }
        }

        if ($result -eq "PASSED")
        {
            $testResults[$name].Passed++
        }
        elseif ($result -eq "FAILED")
        {
            $testResults[$name].Failed++
        }
    }

    # Initialize counters for the overall summary
    $totalPassed = 0
    $totalFailed = 0

    # Build the summary
    $summary =  "Test Results Summary:`n"
    $summary += "---------------------`n"

    foreach ($name in $testResults.Keys)
    {
        $passed = $testResults[$name].Passed
        $failed = $testResults[$name].Failed
        $total = $passed + $failed
        $passPercentage = if ($total -ne 0) { [math]::Round(($passed / $total) * 100, 2) } else { 0 }
        $failPercentage = if ($total -ne 0) { [math]::Round(($failed / $total) * 100, 2) } else { 0 }

        $summary += "Test: $name`n"
        $summary += "  Total: $total`n"
        $summary += "  Passed: $passed ($passPercentage`%)`n"
        $summary += "  Failed: $failed ($failPercentage`%)`n"

        if ($passPercentage -eq 100)
        {
            $summary += "  All tests for $name passed!`n"
        }
        elseif ($passPercentage -ge 50)
        {
            $summary += "  More than half of the tests for $name passed.`n"
        }
        else
        {
            $summary += "  Less than half of the tests for $name passed.`n"
        }

        $summary += "`n"

        # Update the overall counters
        $totalPassed += $passed
        $totalFailed += $failed
    }

    # Add overall summary
    $totalTests = $totalPassed + $totalFailed
    $overallPassPercentage = if ($totalTests -ne 0) { [math]::Round(($totalPassed / $totalTests) * 100, 2) } else { 0 }
    $overallFailPercentage = if ($totalTests -ne 0) { [math]::Round(($totalFailed / $totalTests) * 100, 2) } else { 0 }

    $summary += "Overall Test Results Summary:`n"
    $summary += "-----------------------------`n"
    $summary += "Total Tests: $totalTests`n"
    $summary += "Passed: $totalPassed ($overallPassPercentage`%)`n"
    $summary += "Failed: $totalFailed ($overallFailPercentage`%)`n"

    if ($overallPassPercentage -eq 100)
    {
        $summary += "All tests passed!`n"
    }
    elseif ($overallPassPercentage -ge 50)
    {
        $summary += "More than half of the tests passed.`n"
    }
    else
    {
        $summary += "Less than half of the tests passed.`n"
    }

    # Write the verbose summary to console
    Write-Host $summary -ForegroundColor Yellow

    # Also write the summary to file
    $outFile = $verboseDump
    Set-Content -Path $outFile -Value $summary
}

function simpleDisplay 
{
    $testResults = Get-Content $testDump
    $passed = 0
    $failed = 0

    foreach ($line in $testResults)
    {
        if ($line -match "PASSED")
        {
            $passed++
        } 
        elseif ($line -match "FAILED")
        {
            $failed++
        }
    }

    $total = $passed + $failed

    if ($total -gt 0)
    {
        $passPercentage = [math]::Round(($passed / $total) * 100, 2)
        $failPercentage = [math]::Round(($failed / $total) * 100, 2)

        Write-Host ("Total Assertions: " + $total)

        if ($passPercentage -eq 100)
        {
            Write-Host "All tests passed!" -ForegroundColor Green
        }
        else
        {
            Write-Host ("Passed: " + $passed + " (" + $passPercentage + "%)") -ForegroundColor Green
            Write-Host ("Failed: " + $failed + " (" + $failPercentage + "%)") -ForegroundColor Yellow
        }
    } 
    else
    {
        Write-Host "No tests found." -ForegroundColor Magenta
    }
}

if ($d)
{
    simpleDisplay
}

if ($v)
{
    verboseDisplay
}