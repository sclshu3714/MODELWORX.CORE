call "E:\Software\OCC\OpenCASCADE7.4.0\env.bat" %1 %2 %3
if not ["%CASDEB%"] == [""] call "E:\Software\OCC\OpenCASCADE7.4.0\msvc.bat" %VCVER% win%ARCH% %CASDEB% %MODELWORX.sln
if ["%CASDEB%"] == [""] call "E:\Software\OCC\OpenCASCADE7.4.0\msvc.bat" %VCVER% win%ARCH% "" %MODELWORX.sln
