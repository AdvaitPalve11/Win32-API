# Define the root directory to start the search
$rootDir = Get-Item -Path . -ErrorAction SilentlyContinue | Select-Object -ExpandProperty FullName

# Check if the root directory was found
if (-not $rootDir) {
    Write-Host "Error: Could not determine the current directory. Please run this script from within your project folder."
    exit 1
}

Write-Host "Searching for and deleting .exe files in: $rootDir"

# Find and delete .exe files recursively
Get-ChildItem -Path $rootDir -Include "*.exe" -Recurse -Force | ForEach-Object {
    Write-Host "Deleting: $($_.FullName)"
    Remove-Item -Path $_.FullName -Force
}

Write-Host "Deletion process complete."