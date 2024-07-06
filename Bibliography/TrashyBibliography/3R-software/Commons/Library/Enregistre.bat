@ECHO OFF

del "C:\3R\Commons\Library\setup.log"

ECHO Enregistrement des OCX et DLL des Windows

regit "C:\3R\Commons\Library\Comct232.ocx" >> Setup.log
regit "C:\3R\Commons\Library\Comctl32.ocx" >> Setup.log
regit "C:\3R\Commons\Library\Comdlg32.ocx" >> Setup.log
regit "C:\3R\Commons\Library\Dao360.dll" >> Setup.log
regit "C:\3R\Commons\Library\Dbgrid32.ocx" >> Setup.log
regit "C:\3R\Commons\Library\Dblist32.ocx" >> Setup.log
regit "C:\3R\Commons\Library\Gauge32.ocx" >> Setup.log
regit "C:\3R\Commons\Library\HHOpen.ocx" >> Setup.log
regit "C:\3R\Commons\Library\mscomm32.ocx" >> Setup.log
regit "C:\3R\Commons\Library\Msflxgrd.ocx" >> Setup.log
regit "C:\3R\Commons\Library\msmask32.ocx" >> Setup.log
regit "C:\3R\Commons\Library\scrrun.dll" >> Setup.log
regit "C:\3R\Commons\Library\TABCTL32.ocx" >> Setup.log
regit "C:\3R\Commons\Library\Threed32.ocx" >> Setup.log



ECHO Enregistrement des OCX et DLL de Quantx et CoRRRe IV

regit "C:\3R\Commons\Library\RRR_ActiveX 3R.ocx" >> Setup.log
regit "C:\3R\Commons\Library\RRR_ActiveX Quantium.ocx" >> Setup.log
regit "C:\3R\Commons\Library\RRR_Feuille_de_service.ocx" >> Setup.log

regit "C:\3R\Commons\Library\RRR_Asservissement.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_BaseDeRegistre.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_Bati.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_Classes generale.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_Cycles.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_Conversions.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_Erreur.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_EspionCycle.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_LiaisonSerie.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_LiaisonTable_QuantX.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_Localisation.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_LocalisationFicResult.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_Math.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_ModBus.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_MsgBox.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_OperationsFichiers.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_Parametre.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_Produit.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_Sauvegarde.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_Securite.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_Spider8.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_Timer.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_Traduction.dll" >> Setup.log
regit "C:\3R\Commons\Library\RRR_WindowsOperation.dll" >> Setup.log
regit "C:\3R\Commons\Library\MetEnForme.dll" >> Setup.log


@echo Enregistrement termin‚...

