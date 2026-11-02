@echo off
setlocal
pushd "%~dp0"
if errorlevel 1 exit /b 1

set "BIN_DIR=%~dp0build\cmake\bin"
if not exist "%BIN_DIR%\*.exe" (
  echo No built executables found in "%BIN_DIR%".
  echo Run build.bat first.
  popd
  exit /b 1
)

for %%F in ("%BIN_DIR%\*.exe") do call :run_executable "%%~fF"
if errorlevel 1 (
  echo An executable failed.
  popd
  exit /b 1
)

echo All built executables completed successfully.
popd
endlocal
exit /b 0

:run_executable
echo.
echo Running %~nx1
"%~1"
exit /b %errorlevel%
