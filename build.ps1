$file="small"
cl "$file.cpp" /c /O1 /GS- /Oi- 
link /ALIGN:512 /FILEALIGN:0x8 /NODEFAULTLIB /ENTRY:main /MERGE:.rdata=.text "$file.obj" Advapi32.lib user32.lib kernel32.lib