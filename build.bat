rd /s /q build
cmake -B build -G "Visual Studio 17 2022" -A x64
start build\msvc_dll_example.sln
