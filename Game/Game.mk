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
Date                   :=13/10/2017
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
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/Submissions_Background.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_Player.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_SplashScreen.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_gameTest.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_playerMovement.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_Position.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_Enemy.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_enemyMovement.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_Playing.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Submissions_enemyBulletMovement.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_enemyBullet.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_playerbullet.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_playerBulletMovement.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_GameOver.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_boundRect.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_Controls.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submissions_gameSettings.cpp$(ObjectSuffix) 



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

$(IntermediateDirectory)/Submissions_Player.cpp$(ObjectSuffix): Submissions/Player.cpp $(IntermediateDirectory)/Submissions_Player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_Player.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_Player.cpp$(DependSuffix): Submissions/Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_Player.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_Player.cpp$(DependSuffix) -MM Submissions/Player.cpp

$(IntermediateDirectory)/Submissions_Player.cpp$(PreprocessSuffix): Submissions/Player.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_Player.cpp$(PreprocessSuffix) Submissions/Player.cpp

$(IntermediateDirectory)/Submissions_SplashScreen.cpp$(ObjectSuffix): Submissions/SplashScreen.cpp $(IntermediateDirectory)/Submissions_SplashScreen.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/SplashScreen.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_SplashScreen.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_SplashScreen.cpp$(DependSuffix): Submissions/SplashScreen.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_SplashScreen.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_SplashScreen.cpp$(DependSuffix) -MM Submissions/SplashScreen.cpp

$(IntermediateDirectory)/Submissions_SplashScreen.cpp$(PreprocessSuffix): Submissions/SplashScreen.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_SplashScreen.cpp$(PreprocessSuffix) Submissions/SplashScreen.cpp

$(IntermediateDirectory)/Submissions_gameTest.cpp$(ObjectSuffix): Submissions/gameTest.cpp $(IntermediateDirectory)/Submissions_gameTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/gameTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_gameTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_gameTest.cpp$(DependSuffix): Submissions/gameTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_gameTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_gameTest.cpp$(DependSuffix) -MM Submissions/gameTest.cpp

$(IntermediateDirectory)/Submissions_gameTest.cpp$(PreprocessSuffix): Submissions/gameTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_gameTest.cpp$(PreprocessSuffix) Submissions/gameTest.cpp

$(IntermediateDirectory)/Submissions_playerMovement.cpp$(ObjectSuffix): Submissions/playerMovement.cpp $(IntermediateDirectory)/Submissions_playerMovement.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/playerMovement.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_playerMovement.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_playerMovement.cpp$(DependSuffix): Submissions/playerMovement.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_playerMovement.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_playerMovement.cpp$(DependSuffix) -MM Submissions/playerMovement.cpp

$(IntermediateDirectory)/Submissions_playerMovement.cpp$(PreprocessSuffix): Submissions/playerMovement.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_playerMovement.cpp$(PreprocessSuffix) Submissions/playerMovement.cpp

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

$(IntermediateDirectory)/Submissions_Playing.cpp$(ObjectSuffix): Submissions/Playing.cpp $(IntermediateDirectory)/Submissions_Playing.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/Playing.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_Playing.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_Playing.cpp$(DependSuffix): Submissions/Playing.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_Playing.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_Playing.cpp$(DependSuffix) -MM Submissions/Playing.cpp

$(IntermediateDirectory)/Submissions_Playing.cpp$(PreprocessSuffix): Submissions/Playing.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_Playing.cpp$(PreprocessSuffix) Submissions/Playing.cpp

$(IntermediateDirectory)/Submissions_enemyBulletMovement.cpp$(ObjectSuffix): Submissions/enemyBulletMovement.cpp $(IntermediateDirectory)/Submissions_enemyBulletMovement.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/enemyBulletMovement.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_enemyBulletMovement.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_enemyBulletMovement.cpp$(DependSuffix): Submissions/enemyBulletMovement.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_enemyBulletMovement.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_enemyBulletMovement.cpp$(DependSuffix) -MM Submissions/enemyBulletMovement.cpp

$(IntermediateDirectory)/Submissions_enemyBulletMovement.cpp$(PreprocessSuffix): Submissions/enemyBulletMovement.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_enemyBulletMovement.cpp$(PreprocessSuffix) Submissions/enemyBulletMovement.cpp

$(IntermediateDirectory)/Submissions_enemyBullet.cpp$(ObjectSuffix): Submissions/enemyBullet.cpp $(IntermediateDirectory)/Submissions_enemyBullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/enemyBullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_enemyBullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_enemyBullet.cpp$(DependSuffix): Submissions/enemyBullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_enemyBullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_enemyBullet.cpp$(DependSuffix) -MM Submissions/enemyBullet.cpp

$(IntermediateDirectory)/Submissions_enemyBullet.cpp$(PreprocessSuffix): Submissions/enemyBullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_enemyBullet.cpp$(PreprocessSuffix) Submissions/enemyBullet.cpp

$(IntermediateDirectory)/Submissions_playerbullet.cpp$(ObjectSuffix): Submissions/playerbullet.cpp $(IntermediateDirectory)/Submissions_playerbullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/playerbullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_playerbullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_playerbullet.cpp$(DependSuffix): Submissions/playerbullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_playerbullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_playerbullet.cpp$(DependSuffix) -MM Submissions/playerbullet.cpp

$(IntermediateDirectory)/Submissions_playerbullet.cpp$(PreprocessSuffix): Submissions/playerbullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_playerbullet.cpp$(PreprocessSuffix) Submissions/playerbullet.cpp

$(IntermediateDirectory)/Submissions_playerBulletMovement.cpp$(ObjectSuffix): Submissions/playerBulletMovement.cpp $(IntermediateDirectory)/Submissions_playerBulletMovement.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/playerBulletMovement.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_playerBulletMovement.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_playerBulletMovement.cpp$(DependSuffix): Submissions/playerBulletMovement.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_playerBulletMovement.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_playerBulletMovement.cpp$(DependSuffix) -MM Submissions/playerBulletMovement.cpp

$(IntermediateDirectory)/Submissions_playerBulletMovement.cpp$(PreprocessSuffix): Submissions/playerBulletMovement.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_playerBulletMovement.cpp$(PreprocessSuffix) Submissions/playerBulletMovement.cpp

$(IntermediateDirectory)/Submissions_GameOver.cpp$(ObjectSuffix): Submissions/GameOver.cpp $(IntermediateDirectory)/Submissions_GameOver.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/GameOver.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_GameOver.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_GameOver.cpp$(DependSuffix): Submissions/GameOver.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_GameOver.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_GameOver.cpp$(DependSuffix) -MM Submissions/GameOver.cpp

$(IntermediateDirectory)/Submissions_GameOver.cpp$(PreprocessSuffix): Submissions/GameOver.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_GameOver.cpp$(PreprocessSuffix) Submissions/GameOver.cpp

$(IntermediateDirectory)/Submissions_boundRect.cpp$(ObjectSuffix): Submissions/boundRect.cpp $(IntermediateDirectory)/Submissions_boundRect.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/boundRect.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_boundRect.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_boundRect.cpp$(DependSuffix): Submissions/boundRect.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_boundRect.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_boundRect.cpp$(DependSuffix) -MM Submissions/boundRect.cpp

$(IntermediateDirectory)/Submissions_boundRect.cpp$(PreprocessSuffix): Submissions/boundRect.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_boundRect.cpp$(PreprocessSuffix) Submissions/boundRect.cpp

$(IntermediateDirectory)/Submissions_Controls.cpp$(ObjectSuffix): Submissions/Controls.cpp $(IntermediateDirectory)/Submissions_Controls.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/Controls.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_Controls.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_Controls.cpp$(DependSuffix): Submissions/Controls.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_Controls.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_Controls.cpp$(DependSuffix) -MM Submissions/Controls.cpp

$(IntermediateDirectory)/Submissions_Controls.cpp$(PreprocessSuffix): Submissions/Controls.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_Controls.cpp$(PreprocessSuffix) Submissions/Controls.cpp

$(IntermediateDirectory)/Submissions_gameSettings.cpp$(ObjectSuffix): Submissions/gameSettings.cpp $(IntermediateDirectory)/Submissions_gameSettings.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thabiso Magwaza/Desktop/Electrical Engineering Undergrad/Third Year/SecondSemester/ELEN3009/Project/softwarePorject2/Game/Submissions/gameSettings.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submissions_gameSettings.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submissions_gameSettings.cpp$(DependSuffix): Submissions/gameSettings.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submissions_gameSettings.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submissions_gameSettings.cpp$(DependSuffix) -MM Submissions/gameSettings.cpp

$(IntermediateDirectory)/Submissions_gameSettings.cpp$(PreprocessSuffix): Submissions/gameSettings.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submissions_gameSettings.cpp$(PreprocessSuffix) Submissions/gameSettings.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


