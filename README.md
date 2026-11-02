# learn-cpp
learn c++ using gtest, gmock

## Build and test

Install CMake, Python, and Visual Studio with the C++ x64 tools. `build.bat`
detects the installed Visual Studio toolchain and initializes it automatically.
On the first build, it creates a local Python environment, installs Conan 2
there, and detects a Conan profile if one does not already exist:

- `build.bat` installs/resolves Conan dependencies and builds every C++ target.
- `run.bat` runs all already-built executables from `build/cmake/bin`; it does
  not build or configure the project.
- `clean.bat` removes the generated `build` directory.

The GTest dependency includes GMock. Conan builds the dependency from source when
no compatible binary package is available. The Conan environment and build
outputs are kept under `build`.
