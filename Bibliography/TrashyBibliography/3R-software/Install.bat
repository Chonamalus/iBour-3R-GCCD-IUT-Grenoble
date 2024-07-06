@ECHO OFF

del "setup.log"


ECHO ********************************
ECHO Copie des DLL non enregistrables
ECHO ********************************

ECHO ******************************** >> "setup.log"
ECHO Copie des DLL non enregistrables >> "setup.log"
ECHO ******************************** >> "setup.log"
if %PROCESSOR_ARCHITECTURE%==x86 GOTO CopieNonEnregistrable32

:CopieNonEnregistrable64
ECHO Install 64 bits
xcopy "C:\3R\Commons\Library\Non enregistrable\*.*" %windir%"\sysWOW64" /C /Y >>"setup.log"
GOTO FinCopieNonEnregistrable

:CopieNonEnregistrable32
ECHO Install 32 bits
xcopy "C:\3R\Commons\Library\Non enregistrable\*.*" %windir%"\system32" /C /Y >>"setup.log"
GOTO FinCopieNonEnregistrable

:FinCopieNonEnregistrable





ECHO -
ECHO ********************************
ECHO affectation des droits
ECHO ********************************
ECHO >> "setup.log"
ECHO ******************************** >> "setup.log"
ECHO Affectation des droits >> "setup.log"
ECHO ******************************** >> "setup.log"
echo o|cacls "C:\3R" /T /G "Tout le monde":F >>"setup.log"


ECHO _
ECHO ********************************
ECHO Inscription dans la base de registre des composants VB
ECHO ********************************
ECHO >> "setup.log"
ECHO ******************************** >> "setup.log"
ECHO Inscription dans la base de registre des composants VB
ECHO ******************************** >> "setup.log"
ECHO REG IMPORT "C:\3R\registre\Vbctrls.reg" >> "setup.log"
ECHO REG IMPORT "C:\3R\registre\vb6controls.reg" >> "setup.log"




ECHO -
ECHO ********************************
ECHO Enregistrement des DLL et OCX
ECHO ********************************
ECHO >> "setup.log"
ECHO ******************************** >> "setup.log"
ECHO Enregistrement des DLL et OCX >> "setup.log"
ECHO ******************************** >> "setup.log"
call "C:\3R\Commons\Library\Enregistre.bat"





ECHO -
ECHO ********************************
ECHO Traduction des r‚pertoires
ECHO ********************************
ECHO >> "setup.log"
ECHO ******************************** >> "setup.log"
ECHO Traduction des r‚pertoires >> "setup.log"
ECHO ******************************** >> "setup.log"
call "C:\3R\Translate folder\Folder translator.exe"
ECHO "Traduction terminees" >> "setup.log"





ECHO -
ECHO ********************************
ECHO Autorisation des macros dans EXCEL
ECHO ********************************
ECHO >> "setup.log"
ECHO ******************************** >> "setup.log"
ECHO Autorisation des macros dans EXCEL >> "setup.log"
ECHO ******************************** >> "setup.log"
for /f "tokens=4" %%a in ('reg query "HKEY_CLASSES_ROOT\Excel.Application\CurVer" /ve') do set UserNm=%%a
IF %UserNm%==Excel.Application.14 GOTO AUTORISE_EXCEL_2010
IF %UserNm%==Excel.Application.15 GOTO AUTORISE_EXCEL_2013
IF %UserNm%==Excel.Application.11 GOTO AUTORISE_EXCEL_2003

ECHO seule la version Excel 2013 est g‚r‚e
pause

GOTO AUTORISE_FLXGRD

:AUTORISE_EXCEL_2003
REG IMPORT "C:\3R\registre\Autorisation macro Excel\Autorisation Excel 2003.reg" >> "setup.log"
GOTO AUTORISE_FLXGRD

:AUTORISE_EXCEL_2010
REG IMPORT "C:\3R\registre\Autorisation macro Excel\Autorisation Excel 2010.reg" >> "setup.log"
GOTO AUTORISE_FLXGRD

:AUTORISE_EXCEL_2013
REG IMPORT "C:\3R\registre\Autorisation macro Excel\Autorisation Excel 2013.reg" >> "setup.log"
GOTO AUTORISE_FLXGRD





:AUTORISE_FLXGRD
ECHO -
ECHO ********************************
ECHO Autorisation du flexgrid
ECHO ********************************
ECHO >> "setup.log"
ECHO ******************************** >> "setup.log"
ECHO Autorisation du flexgrid >> "setup.log"
ECHO ******************************** >> "setup.log"
if %PROCESSOR_ARCHITECTURE%==x86 GOTO install32

:install64
ECHO Install 64 bits
ECHO REG IMPORT "C:\3R\registre\Flxgrd 64.reg" >> "setup.log"
GOTO Fin

:install32
ECHO Install 32 bits
ECHO REG IMPORT "C:\3R\registre\Flxgrd 32.reg" >> "setup.log"
GOTO Fin


:Fin


pause


@echo Enregistrement termin‚...

