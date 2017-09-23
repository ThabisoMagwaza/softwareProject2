##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Game
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/Thabiso Magwaza/Documents/C++"
ProjectPath            :="C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Thabiso Magwaza
Date                   :=23/09/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
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
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)"C:\Users\Thabiso Magwaza\Desktop\ProgramSetups\win-64\sfml\include" $(IncludeSwitch)"C:\Users\Thabiso Magwaza\Documents\doctest-master\doctest-master\doctest" 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-audio $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-audio" "sfml-graphics" "sfml-window" "sfml-system" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)"C:\Users\Thabiso Magwaza\Desktop\ProgramSetups\win-64\sfml\lib" 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe --std=gnu++14
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/Submissions_Background.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_Movement.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_Player.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_source.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_SplashScreen.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_playerMovement.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_playerSFML.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_Position.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_Enemy.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Submissions_enemyMovement.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_enemySFML.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_Playing.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/Submissions_Background.cpp$(ObjectSuffix): Submissions/Background.cpp $(IntermediateDirectory)/Submissions_Background.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/Background.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_Background.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_Background.cpp$(DependSuffix): Submissions/Background.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_Background.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_Background.cpp$(DependSuffix) -MM Submissions/Background.cpp

$(IntermediateDirectory)/Submissions_Background.cpp$(PreprocessSuffix): Submissions/Background.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_Background.cpp$(PreprocessSuffix) Submissions/Background.cpp

$(IntermediateDirectory)/Submissions_Game.cpp$(ObjectSuffix): Submissions/Game.cpp $(IntermediateDirectory)/Submissions_Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_Game.cpp$(DependSuffix): Submissions/Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_Game.cpp$(DependSuffix) -MM Submissions/Game.cpp

$(IntermediateDirectory)/Submissions_Game.cpp$(PreprocessSuffix): Submissions/Game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_Game.cpp$(PreprocessSuffix) Submissions/Game.cpp

$(IntermediateDirectory)/Submissions_Movement.cpp$(ObjectSuffix): Submissions/Movement.cpp $(IntermediateDirectory)/Submissions_Movement.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/Movement.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_Movement.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_Movement.cpp$(DependSuffix): Submissions/Movement.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_Movement.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_Movement.cpp$(DependSuffix) -MM Submissions/Movement.cpp

$(IntermediateDirectory)/Submissions_Movement.cpp$(PreprocessSuffix): Submissions/Movement.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_Movement.cpp$(PreprocessSuffix) Submissions/Movement.cpp

$(IntermediateDirectory)/Submissions_Player.cpp$(ObjectSuffix): Submissions/Player.cpp $(IntermediateDirectory)/Submissions_Player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_Player.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_Player.cpp$(DependSuffix): Submissions/Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_Player.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_Player.cpp$(DependSuffix) -MM Submissions/Player.cpp

$(IntermediateDirectory)/Submissions_Player.cpp$(PreprocessSuffix): Submissions/Player.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_Player.cpp$(PreprocessSuffix) Submissions/Player.cpp

$(IntermediateDirectory)/Submissions_source.cpp$(ObjectSuffix): Submissions/source.cpp $(IntermediateDirectory)/Submissions_source.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/source.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_source.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_source.cpp$(DependSuffix): Submissions/source.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_source.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_source.cpp$(DependSuffix) -MM Submissions/source.cpp

$(IntermediateDirectory)/Submissions_source.cpp$(PreprocessSuffix): Submissions/source.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_source.cpp$(PreprocessSuffix) Submissions/source.cpp

$(IntermediateDirectory)/Submissions_SplashScreen.cpp$(ObjectSuffix): Submissions/SplashScreen.cpp $(IntermediateDirectory)/Submissions_SplashScreen.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/SplashScreen.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_SplashScreen.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_SplashScreen.cpp$(DependSuffix): Submissions/SplashScreen.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_SplashScreen.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_SplashScreen.cpp$(DependSuffix) -MM Submissions/SplashScreen.cpp

$(IntermediateDirectory)/Submissions_SplashScreen.cpp$(PreprocessSuffix): Submissions/SplashScreen.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_SplashScreen.cpp$(PreprocessSuffix) Submissions/SplashScreen.cpp

$(IntermediateDirectory)/Submissions_playerMovement.cpp$(ObjectSuffix): Submissions/playerMovement.cpp $(IntermediateDirectory)/Submissions_playerMovement.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/playerMovement.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_playerMovement.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_playerMovement.cpp$(DependSuffix): Submissions/playerMovement.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_playerMovement.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_playerMovement.cpp$(DependSuffix) -MM Submissions/playerMovement.cpp

$(IntermediateDirectory)/Submissions_playerMovement.cpp$(PreprocessSuffix): Submissions/playerMovement.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_playerMovement.cpp$(PreprocessSuffix) Submissions/playerMovement.cpp

$(IntermediateDirectory)/Submissions_playerSFML.cpp$(ObjectSuffix): Submissions/playerSFML.cpp $(IntermediateDirectory)/Submissions_playerSFML.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/playerSFML.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_playerSFML.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_playerSFML.cpp$(DependSuffix): Submissions/playerSFML.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_playerSFML.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_playerSFML.cpp$(DependSuffix) -MM Submissions/playerSFML.cpp

$(IntermediateDirectory)/Submissions_playerSFML.cpp$(PreprocessSuffix): Submissions/playerSFML.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_playerSFML.cpp$(PreprocessSuffix) Submissions/playerSFML.cpp

$(IntermediateDirectory)/Submissions_Position.cpp$(ObjectSuffix): Submissions/Position.cpp $(IntermediateDirectory)/Submissions_Position.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/Position.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_Position.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_Position.cpp$(DependSuffix): Submissions/Position.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_Position.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_Position.cpp$(DependSuffix) -MM Submissions/Position.cpp

$(IntermediateDirectory)/Submissions_Position.cpp$(PreprocessSuffix): Submissions/Position.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_Position.cpp$(PreprocessSuffix) Submissions/Position.cpp

$(IntermediateDirectory)/Submissions_Enemy.cpp$(ObjectSuffix): Submissions/Enemy.cpp $(IntermediateDirectory)/Submissions_Enemy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/Enemy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_Enemy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_Enemy.cpp$(DependSuffix): Submissions/Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_Enemy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_Enemy.cpp$(DependSuffix) -MM Submissions/Enemy.cpp

$(IntermediateDirectory)/Submissions_Enemy.cpp$(PreprocessSuffix): Submissions/Enemy.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_Enemy.cpp$(PreprocessSuffix) Submissions/Enemy.cpp

$(IntermediateDirectory)/Submissions_enemyMovement.cpp$(ObjectSuffix): Submissions/enemyMovement.cpp $(IntermediateDirectory)/Submissions_enemyMovement.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/enemyMovement.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_enemyMovement.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_enemyMovement.cpp$(DependSuffix): Submissions/enemyMovement.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_enemyMovement.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_enemyMovement.cpp$(DependSuffix) -MM Submissions/enemyMovement.cpp

$(IntermediateDirectory)/Submissions_enemyMovement.cpp$(PreprocessSuffix): Submissions/enemyMovement.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_enemyMovement.cpp$(PreprocessSuffix) Submissions/enemyMovement.cpp

$(IntermediateDirectory)/Submissions_enemySFML.cpp$(ObjectSuffix): Submissions/enemySFML.cpp $(IntermediateDirectory)/Submissions_enemySFML.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/enemySFML.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_enemySFML.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_enemySFML.cpp$(DependSuffix): Submissions/enemySFML.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_enemySFML.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_enemySFML.cpp$(DependSuffix) -MM Submissions/enemySFML.cpp

$(IntermediateDirectory)/Submissions_enemySFML.cpp$(PreprocessSuffix): Submissions/enemySFML.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_enemySFML.cpp$(PreprocessSuffix) Submissions/enemySFML.cpp

$(IntermediateDirectory)/Submissions_Playing.cpp$(ObjectSuffix): Submissions/Playing.cpp $(IntermediateDirectory)/Submissions_Playing.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/Playing.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_Playing.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_Playing.cpp$(DependSuffix): Submissions/Playing.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_Playing.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_Playing.cpp$(DependSuffix) -MM Submissions/Playing.cpp

$(IntermediateDirectory)/Submissions_Playing.cpp$(PreprocessSuffix): Submissions/Playing.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_Playing.cpp$(PreprocessSuffix) Submissions/Playing.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


