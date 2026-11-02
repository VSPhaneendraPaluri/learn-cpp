@echo off
setlocal
pushd "%~dp0"

if exist "%~dp0build" (
  echo Removing existing build directory...
  rmdir /s /q "%~dp0build"
  if errorlevel 1 (
    echo Failed to remove the build directory.
    popd
    exit /b 1
  )
) else (
  echo Build directory does not exist.
)

echo Cleanup completed successfully.
popd
endlocal
