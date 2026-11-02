@echo off
setlocal
pushd "%~dp0"
if errorlevel 1 exit /b 1

where cmake >nul 2>nul
if errorlevel 1 (
  echo CMake was not found. Install CMake and ensure it is on PATH.
  popd
  exit /b 1
)

where py >nul 2>nul
if errorlevel 1 (
  echo Python Launcher was not found. Install Python and ensure py is on PATH.
  popd
  exit /b 1
)

set "BUILD_DIR=%~dp0build"
set "ROOT_DIR=%CD%"
set "CONAN_EXE=%BUILD_DIR%\tools\conan-env\Scripts\conan.exe"
set "CONAN_HOME=%BUILD_DIR%\conan-home"
if not exist "%CONAN_EXE%" (
  echo Creating a local Conan 2 environment...
  py -3 -m venv "%BUILD_DIR%\tools\conan-env"
  if errorlevel 1 (
    echo Failed to create the local Conan environment.
    popd
    exit /b 1
  )

  "%BUILD_DIR%\tools\conan-env\Scripts\python.exe" -m pip install --disable-pip-version-check "conan>=2,<3"
  if errorlevel 1 (
    echo Failed to install Conan 2 into the local build environment.
    popd
    exit /b 1
  )
)

if not exist "%CONAN_EXE%" (
  echo Conan was not installed in the local build environment.
  popd
  exit /b 1
)

set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "%VSWHERE%" (
  echo Visual Studio Installer vswhere.exe was not found.
  popd
  exit /b 1
)

set "VS_PATH="
for /f "usebackq tokens=*" %%I in (`"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "VS_PATH=%%I"
if not defined VS_PATH (
  echo No Visual Studio installation with the C++ x64 tools was found.
  popd
  exit /b 1
)

set "VCVARS=%VS_PATH%\VC\Auxiliary\Build\vcvarsall.bat"
if not exist "%VCVARS%" (
  echo Visual Studio compiler setup was not found at "%VCVARS%".
  popd
  exit /b 1
)

call "%VCVARS%" x64
if errorlevel 1 (
  echo Failed to initialize the Visual Studio C++ toolchain.
  popd
  exit /b 1
)

call "%CONAN_EXE%" profile detect --exist-ok
if errorlevel 1 (
  echo Failed to detect the Conan default profile.
  popd
  exit /b 1
)

call "%CONAN_EXE%" install "%ROOT_DIR%" --output-folder "%BUILD_DIR%\conan" --build=missing -s:h build_type=Release -s:b build_type=Release -c:h tools.cmake.cmaketoolchain:generator="NMake Makefiles" -c:b tools.cmake.cmaketoolchain:generator="NMake Makefiles"
if errorlevel 1 (
  echo Conan dependency installation failed.
  popd
  exit /b 1
)

cmake -S "%ROOT_DIR%" -B "%BUILD_DIR%\cmake" -G "NMake Makefiles" -DCMAKE_TOOLCHAIN_FILE="%BUILD_DIR%\conan\conan_toolchain.cmake" -DCMAKE_BUILD_TYPE=Release
if errorlevel 1 (
  echo CMake configure failed. Check the Conan dependency setup and compiler installation.
  echo If this build directory uses another CMake generator, run clean.bat and retry.
  popd
  exit /b 1
)

cmake --build "%BUILD_DIR%\cmake" --config Release
if errorlevel 1 (
  echo Build failed.
  popd
  exit /b 1
)

echo Build completed successfully.
popd
endlocal
