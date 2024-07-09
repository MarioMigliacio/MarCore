###################################################################################################
#                                                                                                 #
# Author: Mario Migliacio                                                                         #
# @file: run.ps1                                                                                  #
# \brief: Most simplistic form of run test executable                                             #
#                                                                                                 #
# \Expects: ..\build folder exists and was generated with CMakeLists.txt                          #
#                                                                                                 #
# \Params: -d [DISPLAY] Display simple test results in terminal and output to _output file        #
#          -v [VERBOSE] View detailed test results in terminal and output to _verbose file        #
#                                                                                                 #
# \Success: Runs the executable application                                                       #
#           Display Run status in MAGENTA prompt                                                  #
#                                                                                                 #
# \Failure: Display that ..\build does not exist in RED prompt                                    #
#                                                                                                 #
###################################################################################################

param (
    [switch]$d,
    [switch]$v
)

# Note: The scriptDir, projectRoot, and exeDir allows this script to be invoked from anywhere. 
#       This allows the use of .\scr\run.ps1 from even the root directory, or inside the \scr directly.

# Get the directory of the current script
$scriptDir = Split-Path -Parent -Path $MyInvocation.MyCommand.Definition

# Define the project root and executable directory
$projectRoot = (Resolve-Path "$scriptDir\..").Path
$exeDir = "$projectRoot\build\bin\Debug"

# Define the executable path
$exePath = "$exeDir\MC_test.exe"

# Define the output file path and the dump directory
$outputFile = "$exeDir\last_test_output.txt"
$dumpDir = "$projectRoot\test_output\"

function simpleRun
{
    # Check if the executable exists
    if (-Not (Test-Path -Path $exePath))
    {
        Write-Host "Executable not found: $exePath"
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

function copyOutputFile
{
    # Create the dump directory if it does not exist
    if (-Not (Test-Path -Path $dumpDir))
    {
        New-Item -ItemType Directory -Path $dumpDir
    }

    # Check if the output file exists and copy it to the dump directory
    if (Test-Path -Path $outputFile)
    {
        $outputFileName = [System.IO.Path]::GetFileNameWithoutExtension($outputFile)
        $outputFileExtension = [System.IO.Path]::GetExtension($outputFile)
        $newOutputFile = "$dumpDir$outputFileName$outputFileExtension"
        Copy-Item -Path $outputFile -Destination $newOutputFile
        Write-Host "Output file copied to: $newOutputFile" -ForegroundColor Green
    }
    else
    {
        Write-Host "Unable to write Output file: $outputFile" -ForegroundColor Red
    }
}

function simpleDisplay
{
    $testResults = Get-Content $outputFile
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

function verboseDisplay
{
    # Initialize a hashtable to store test results grouped by test name
    $testResults = @{}
    $verboseOutputFile = "$dumpDir\last_test_output_verbose.txt"

    # Read the file line by line
    $lines = Get-Content -Path $outputFile

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
    $outFile = $verboseOutputFile
    Set-Content -Path $outFile -Value $summary
}


simpleRun
copyOutputFile

# If -d flag, display some console statistics
if ($d)
{
    simpleDisplay
}

# If -v flag, write the verbose output statistics
if ($v)
{
    verboseDisplay
}
