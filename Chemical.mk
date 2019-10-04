##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Chemical
ConfigurationName      :=Debug
WorkspacePath          :="/home/mohamed/Documents/Chemical Reaction"
ProjectPath            :="/home/mohamed/Documents/Chemical Reaction/Chemical"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=mohamed
Date                   :=04/10/19
CodeLitePath           :=/home/mohamed/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
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
ObjectsFileList        :="Chemical.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/usr/include/gtest 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/src/googletest/googletest $(LibraryPathSwitch)"target_link_libraries(NodeTest ${GTEST_BOTH_LIBRARIES})" 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/chemicalnetwork.cpp$(ObjectSuffix) $(IntermediateDirectory)/tools.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/readdata.cpp$(ObjectSuffix) $(IntermediateDirectory)/node.cpp$(ObjectSuffix) $(IntermediateDirectory)/reaction.cpp$(ObjectSuffix) $(IntermediateDirectory)/molecule.cpp$(ObjectSuffix) $(IntermediateDirectory)/circuitfind.cpp$(ObjectSuffix) $(IntermediateDirectory)/generategraph.cpp$(ObjectSuffix) 



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/chemicalnetwork.cpp$(ObjectSuffix): chemicalnetwork.cpp $(IntermediateDirectory)/chemicalnetwork.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mohamed/Documents/Chemical Reaction/Chemical/chemicalnetwork.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/chemicalnetwork.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/chemicalnetwork.cpp$(DependSuffix): chemicalnetwork.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/chemicalnetwork.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/chemicalnetwork.cpp$(DependSuffix) -MM chemicalnetwork.cpp

$(IntermediateDirectory)/chemicalnetwork.cpp$(PreprocessSuffix): chemicalnetwork.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/chemicalnetwork.cpp$(PreprocessSuffix) chemicalnetwork.cpp

$(IntermediateDirectory)/tools.cpp$(ObjectSuffix): tools.cpp $(IntermediateDirectory)/tools.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mohamed/Documents/Chemical Reaction/Chemical/tools.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tools.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tools.cpp$(DependSuffix): tools.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tools.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tools.cpp$(DependSuffix) -MM tools.cpp

$(IntermediateDirectory)/tools.cpp$(PreprocessSuffix): tools.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tools.cpp$(PreprocessSuffix) tools.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mohamed/Documents/Chemical Reaction/Chemical/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/readdata.cpp$(ObjectSuffix): readdata.cpp $(IntermediateDirectory)/readdata.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mohamed/Documents/Chemical Reaction/Chemical/readdata.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/readdata.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/readdata.cpp$(DependSuffix): readdata.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/readdata.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/readdata.cpp$(DependSuffix) -MM readdata.cpp

$(IntermediateDirectory)/readdata.cpp$(PreprocessSuffix): readdata.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/readdata.cpp$(PreprocessSuffix) readdata.cpp

$(IntermediateDirectory)/node.cpp$(ObjectSuffix): node.cpp $(IntermediateDirectory)/node.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mohamed/Documents/Chemical Reaction/Chemical/node.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/node.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/node.cpp$(DependSuffix): node.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/node.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/node.cpp$(DependSuffix) -MM node.cpp

$(IntermediateDirectory)/node.cpp$(PreprocessSuffix): node.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/node.cpp$(PreprocessSuffix) node.cpp

$(IntermediateDirectory)/reaction.cpp$(ObjectSuffix): reaction.cpp $(IntermediateDirectory)/reaction.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mohamed/Documents/Chemical Reaction/Chemical/reaction.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/reaction.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/reaction.cpp$(DependSuffix): reaction.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/reaction.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/reaction.cpp$(DependSuffix) -MM reaction.cpp

$(IntermediateDirectory)/reaction.cpp$(PreprocessSuffix): reaction.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/reaction.cpp$(PreprocessSuffix) reaction.cpp

$(IntermediateDirectory)/molecule.cpp$(ObjectSuffix): molecule.cpp $(IntermediateDirectory)/molecule.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mohamed/Documents/Chemical Reaction/Chemical/molecule.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/molecule.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/molecule.cpp$(DependSuffix): molecule.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/molecule.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/molecule.cpp$(DependSuffix) -MM molecule.cpp

$(IntermediateDirectory)/molecule.cpp$(PreprocessSuffix): molecule.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/molecule.cpp$(PreprocessSuffix) molecule.cpp

$(IntermediateDirectory)/circuitfind.cpp$(ObjectSuffix): circuitfind.cpp $(IntermediateDirectory)/circuitfind.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mohamed/Documents/Chemical Reaction/Chemical/circuitfind.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/circuitfind.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/circuitfind.cpp$(DependSuffix): circuitfind.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/circuitfind.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/circuitfind.cpp$(DependSuffix) -MM circuitfind.cpp

$(IntermediateDirectory)/circuitfind.cpp$(PreprocessSuffix): circuitfind.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/circuitfind.cpp$(PreprocessSuffix) circuitfind.cpp

$(IntermediateDirectory)/generategraph.cpp$(ObjectSuffix): generategraph.cpp $(IntermediateDirectory)/generategraph.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mohamed/Documents/Chemical Reaction/Chemical/generategraph.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/generategraph.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/generategraph.cpp$(DependSuffix): generategraph.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/generategraph.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/generategraph.cpp$(DependSuffix) -MM generategraph.cpp

$(IntermediateDirectory)/generategraph.cpp$(PreprocessSuffix): generategraph.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/generategraph.cpp$(PreprocessSuffix) generategraph.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


