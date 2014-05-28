@ECHO OFF

setlocal enabledelayedexpansion

REM Set default mysql dir
set mysql=C:\Program Files (x86)\MySQL\MySQL Server 5.5\lib\libmysql.dll

REM  Check if we can find candle.exe on the path
where candle.exe >nul 2>&1


IF EXIST "%mysql%" (
	echo FOUND MYSQL
	copy "%mysql%" libmysql.dll
) ELSE (
	echo DID NOT FIND MYSQL
	REM prompt user for mysql dll location
	set /P umysql=Enter full libmysql.dll location: 
	
	IF NOT EXIST "!umysql!" (
		echo Incorrect mysql location "!umysql!" exiting
		
		goto ERROR
	) ELSE (
		copy "!umysql!" libmysql.dll
	)
)

IF NOT ERRORLEVEL 1 (
REM We found candle.exe, assume WiX toolset is installed, build the installer
candle SPARQL.wxs
light SPARQL.wixobj
) ELSE (
REM We could not find candle.exe, quit with exit code 1
echo "Could not find WiX toolset (http://wixtoolset.org/) on path!"
goto ERROR
)

ENDLOCAL 
Exit /B 0

:ERROR
ENDLOCAL 
Exit /B 1