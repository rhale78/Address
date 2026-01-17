# Microsoft Developer Studio Generated NMAKE File, Based on address.dsp
!IF "$(CFG)" == ""
CFG=address - Win32 Debug
!MESSAGE No configuration specified. Defaulting to address - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "address - Win32 Release" && "$(CFG)" != "address - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "address.mak" CFG="address - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "address - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "address - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "address - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\address.exe"


CLEAN :
	-@erase "$(INTDIR)\address.obj"
	-@erase "$(INTDIR)\BST.obj"
	-@erase "$(INTDIR)\person.obj"
	-@erase "$(INTDIR)\prog4.obj"
	-@erase "$(INTDIR)\string.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\address.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\address.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\address.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\address.pdb" /machine:I386 /out:"$(OUTDIR)\address.exe" 
LINK32_OBJS= \
	"$(INTDIR)\address.obj" \
	"$(INTDIR)\BST.obj" \
	"$(INTDIR)\person.obj" \
	"$(INTDIR)\prog4.obj" \
	"$(INTDIR)\string.obj"

"$(OUTDIR)\address.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "address - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\address.exe" "$(OUTDIR)\address.bsc"


CLEAN :
	-@erase "$(INTDIR)\address.obj"
	-@erase "$(INTDIR)\address.sbr"
	-@erase "$(INTDIR)\BST.obj"
	-@erase "$(INTDIR)\BST.sbr"
	-@erase "$(INTDIR)\person.obj"
	-@erase "$(INTDIR)\person.sbr"
	-@erase "$(INTDIR)\prog4.obj"
	-@erase "$(INTDIR)\prog4.sbr"
	-@erase "$(INTDIR)\string.obj"
	-@erase "$(INTDIR)\string.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\address.bsc"
	-@erase "$(OUTDIR)\address.exe"
	-@erase "$(OUTDIR)\address.ilk"
	-@erase "$(OUTDIR)\address.map"
	-@erase "$(OUTDIR)\address.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /Gi /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FAcs /Fa"$(INTDIR)\\" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\address.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\address.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\address.sbr" \
	"$(INTDIR)\BST.sbr" \
	"$(INTDIR)\person.sbr" \
	"$(INTDIR)\prog4.sbr" \
	"$(INTDIR)\string.sbr"

"$(OUTDIR)\address.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /profile /map:"$(INTDIR)\address.map" /debug /machine:I386 /out:"$(OUTDIR)\address.exe" 
LINK32_OBJS= \
	"$(INTDIR)\address.obj" \
	"$(INTDIR)\BST.obj" \
	"$(INTDIR)\person.obj" \
	"$(INTDIR)\prog4.obj" \
	"$(INTDIR)\string.obj"

"$(OUTDIR)\address.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("address.dep")
!INCLUDE "address.dep"
!ELSE 
!MESSAGE Warning: cannot find "address.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "address - Win32 Release" || "$(CFG)" == "address - Win32 Debug"
SOURCE=.\address.cpp

!IF  "$(CFG)" == "address - Win32 Release"


"$(INTDIR)\address.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "address - Win32 Debug"


"$(INTDIR)\address.obj"	"$(INTDIR)\address.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\BST.cpp

!IF  "$(CFG)" == "address - Win32 Release"


"$(INTDIR)\BST.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "address - Win32 Debug"


"$(INTDIR)\BST.obj"	"$(INTDIR)\BST.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\person.cpp

!IF  "$(CFG)" == "address - Win32 Release"


"$(INTDIR)\person.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "address - Win32 Debug"


"$(INTDIR)\person.obj"	"$(INTDIR)\person.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\prog4.cpp

!IF  "$(CFG)" == "address - Win32 Release"


"$(INTDIR)\prog4.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "address - Win32 Debug"


"$(INTDIR)\prog4.obj"	"$(INTDIR)\prog4.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\string.cpp

!IF  "$(CFG)" == "address - Win32 Release"


"$(INTDIR)\string.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "address - Win32 Debug"


"$(INTDIR)\string.obj"	"$(INTDIR)\string.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

