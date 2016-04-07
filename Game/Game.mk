##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Game
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Gabriele/Documents/GitHub/Codelite
ProjectPath            :=C:/Users/Gabriele/Documents/GitHub/Codelite/Game/Game
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Gabriele
Date                   :=07/04/2016
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/tools/msys64/mingw64/bin/g++.exe -static -static-libgcc -static-libstdc++
SharedObjectLinkerName :=C:/tools/msys64/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Game.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/tools/msys64/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/tools/msys64/mingw64/bin/ar.exe rcu
CXX      := C:/tools/msys64/mingw64/bin/g++.exe
CC       := C:/tools/msys64/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/tools/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/coordinate.cpp$(ObjectSuffix) $(IntermediateDirectory)/Giocatore.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Stanza.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/coordinate.cpp$(ObjectSuffix): coordinate.cpp $(IntermediateDirectory)/coordinate.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gabriele/Documents/GitHub/Codelite/Game/Game/coordinate.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/coordinate.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/coordinate.cpp$(DependSuffix): coordinate.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/coordinate.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/coordinate.cpp$(DependSuffix) -MM "coordinate.cpp"

$(IntermediateDirectory)/coordinate.cpp$(PreprocessSuffix): coordinate.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/coordinate.cpp$(PreprocessSuffix) "coordinate.cpp"

$(IntermediateDirectory)/Giocatore.cpp$(ObjectSuffix): Giocatore.cpp $(IntermediateDirectory)/Giocatore.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gabriele/Documents/GitHub/Codelite/Game/Game/Giocatore.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Giocatore.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Giocatore.cpp$(DependSuffix): Giocatore.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Giocatore.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Giocatore.cpp$(DependSuffix) -MM "Giocatore.cpp"

$(IntermediateDirectory)/Giocatore.cpp$(PreprocessSuffix): Giocatore.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Giocatore.cpp$(PreprocessSuffix) "Giocatore.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gabriele/Documents/GitHub/Codelite/Game/Game/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Stanza.cpp$(ObjectSuffix): Stanza.cpp $(IntermediateDirectory)/Stanza.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gabriele/Documents/GitHub/Codelite/Game/Game/Stanza.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Stanza.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Stanza.cpp$(DependSuffix): Stanza.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Stanza.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Stanza.cpp$(DependSuffix) -MM "Stanza.cpp"

$(IntermediateDirectory)/Stanza.cpp$(PreprocessSuffix): Stanza.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Stanza.cpp$(PreprocessSuffix) "Stanza.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


