:: the ninja generator will use the default target platform of the 'Visual Studio Tools Command Prompt' it runs in.

:: make environment local because vcvarsall.bat polutes it
setlocal
set Path=%PATH%

set SRC=%cd%
set COM_BUILD="C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat"
set PRO_BUILD="C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Auxiliary\Build\vcvarsall.bat"
set ENT_BUILD="C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvarsall.bat"

if exist %COM_BUILD% (
  call %COM_BUILD% x64
) 

if exist %PRO_BUILD% (
  call %PRO_BUILD% x64
) 

if exist %ENT_BUILD% (
  call %ENT_BUILD% x64
) 

cmake -B build -DCMAKE_INSTALL_PREFIX=install -DCMAKE_BUILD_TYPE=Release -G Ninja %SRC%

