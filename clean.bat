::@echo off  

del .\*.lib
del .\*.tds

for /f "delims=" %%i in ('dir /b /a-d /s "*.obj"') do del %%i
pause