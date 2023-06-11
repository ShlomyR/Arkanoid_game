# the name of your executable
TARGET = main

# launches your target in terminal
RUN = ./$(TARGET)

# directory for your source files
SRC_DIR = src/sourcefiles
SRC_DIR_COMMAND = src/sourcefiles/Commands
SRC_DIR_PARSER = src/sourcefiles/Parser
SRC_DIR_INPUT_LOGIC = src/sourcefiles/InputLogic
SRC_DIR_MENU = src/sourcefiles/Menu
SRC_DIR_PLAYER_INTERACTIV_OBJ = src/sourcefiles/PlayerInteractivObjects
SRC_DIR_SCORE_LOGIC = src/sourcefiles/ScoreLogic
SRC_DIR_OPTIONS = src/sourcefiles/Options
SRC_DIR_DIFFICULTY = src/sourcefiles/Difficulty
SRC_DIR_VIDEO = src/sourcefiles/Video


# directory for your heder files
HEDER_DIR_SRC = src/hederfiles
HEDER_DIR_COMMANDS = src/hederfiles/Commands
HEDER_DIR_PARSER = src/hederfiles/Parser
HEDER_DIR_INTERFACES = src/hederfiles/Interfaces
HEDER_DIR_INPUT_LOGIC = src/hederfiles/InputLogic
HEDER_DIR_MENU = src/hederfiles/Menu
HEDER_DIR_PLAYER_INTERACTIV_OBJ = src/hederfiles/PlayerInteractivObjects
HEDER_DIR_SCORE_LOGIC = src/hederfiles/ScoreLogic
HEDER_DIR_OPTIONS = src/hederfiles/Options
HEDER_DIR_DIFFICULTY = src/hederfiles/Difficulty
HEDER_DIR_VIDEO = src/hederfiles/Video

# directory for your object files
BUILD_DIR_SRC = bin/src
BUILD_DIR_COMMANDS = bin/commands
BUILD_DIR_PARSER = bin/parser
BUILD_DIR_INPUT_LOGIC = bin/inputLogic
BUILD_DIR_MENU = bin/menu
BUILD_DIR_PLAYER_INTERACTIV_OBJ = bin/playerInteractivObjects
BUILD_DIR_SCORE_LOGIC = bin/scoreLogic
BUILD_DIR_OPTIONS = bin/options
BUILD_DIR_DIFFICULTY = bin/difficulty
BUILD_DIR_VIDEO = bin/video

# add more CompilerFLAGS as your project requires
CFLAGS = -std=c++17 -Wall -O2 -Wextra 

# add libraries for your project here
LDFLAGS =

# add library linker commands here (start with -l)
LOADLIBS = -lpthread -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lboost_filesystem

# add library search paths here (start with -L)
LDLIBS = 

# add include paths (start with -I)
INC = -I $(HEDER_DIR_SRC)
INC += -I $(HEDER_DIR_COMMANDS)
INC += -I $(HEDER_DIR_PARSER)
INC += -I $(HEDER_DIR_INTERFACES)
INC += -I $(HEDER_DIR_INPUT_LOGIC)
INC += -I $(HEDER_DIR_MENU)
INC += -I $(HEDER_DIR_PLAYER_INTERACTIV_OBJ)
INC += -I $(HEDER_DIR_SCORE_LOGIC)
INC += -I $(HEDER_DIR_OPTIONS)
INC += -I $(HEDER_DIR_DIFFICULTY)
INC += -I $(HEDER_DIR_VIDEO)

# finds all your objects that corrispond to your .cpp files, system agnostic version
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR_SRC)/%.o, $(wildcard $(SRC_DIR)/*.cpp))
OBJECTS += $(patsubst $(SRC_DIR_COMMAND)/%.cpp, $(BUILD_DIR_COMMANDS)/%.o, $(wildcard $(SRC_DIR_COMMAND)/*.cpp))
OBJECTS += $(patsubst $(SRC_DIR_PARSER)/%.cpp, $(BUILD_DIR_PARSER)/%.o, $(wildcard $(SRC_DIR_PARSER)/*.cpp))
OBJECTS += $(patsubst $(SRC_DIR_INPUT_LOGIC)/%.cpp, $(BUILD_DIR_INPUT_LOGIC)/%.o, $(wildcard $(SRC_DIR_INPUT_LOGIC)/*.cpp))
OBJECTS += $(patsubst $(SRC_DIR_MENU)/%.cpp, $(BUILD_DIR_MENU)/%.o, $(wildcard $(SRC_DIR_MENU)/*.cpp))
OBJECTS += $(patsubst $(SRC_DIR_PLAYER_INTERACTIV_OBJ)/%.cpp, $(BUILD_DIR_PLAYER_INTERACTIV_OBJ)/%.o, $(wildcard $(SRC_DIR_PLAYER_INTERACTIV_OBJ)/*.cpp))
OBJECTS += $(patsubst $(SRC_DIR_SCORE_LOGIC)/%.cpp, $(BUILD_DIR_SCORE_LOGIC)/%.o, $(wildcard $(SRC_DIR_SCORE_LOGIC)/*.cpp))
OBJECTS += $(patsubst $(SRC_DIR_OPTIONS)/%.cpp, $(BUILD_DIR_OPTIONS)/%.o, $(wildcard $(SRC_DIR_OPTIONS)/*.cpp))
OBJECTS += $(patsubst $(SRC_DIR_DIFFICULTY)/%.cpp, $(BUILD_DIR_DIFFICULTY)/%.o, $(wildcard $(SRC_DIR_DIFFICULTY)/*.cpp))
OBJECTS += $(patsubst $(SRC_DIR_VIDEO)/%.cpp, $(BUILD_DIR_VIDEO)/%.o, $(wildcard $(SRC_DIR_VIDEO)/*.cpp))
OBJECTS += main.cpp

.PHONY: all
# makes build directory, updates your objects, builds your executable
all: 
	mkdir -p $(BUILD_DIR_SRC)
	mkdir -p $(BUILD_DIR_COMMANDS)
	mkdir -p $(BUILD_DIR_PARSER)
	mkdir -p $(BUILD_DIR_INPUT_LOGIC)
	mkdir -p $(BUILD_DIR_MENU)
	mkdir -p $(BUILD_DIR_PLAYER_INTERACTIV_OBJ)
	mkdir -p $(BUILD_DIR_SCORE_LOGIC)
	mkdir -p $(BUILD_DIR_OPTIONS)
	mkdir -p $(BUILD_DIR_DIFFICULTY)
	mkdir -p $(BUILD_DIR_VIDEO)
	+$(MAKE) $(TARGET)

# updates your objects, builds your executable
$(TARGET): $(OBJECTS) $(HEDER_DIR_SRC)/*.hpp $(HEDER_DIR_COMMANDS)/*.hpp $(HEDER_DIR_PARSER)/*.hpp $(HEDER_DIR_INTERFACES)/*.hxx $(HEDER_DIR_INPUT_LOGIC)/*.hpp $(HEDER_DIR_MENU)/*.hpp $(HEDER_DIR_PLAYER_INTERACTIV_OBJ)/*.hpp $(HEDER_DIR_SCORE_LOGIC)/*.hpp $(HEDER_DIR_OPTIONS)/*.hpp $(HEDER_DIR_DIFFICULTY)/*.hpp $(HEDER_DIR_VIDEO)/*.hpp
	$(CXX) $(OBJECTS) $(CFLAGS) -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)

# builds your objects
$(BUILD_DIR_SRC)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)
$(BUILD_DIR_COMMANDS)/%.o: $(SRC_DIR_COMMAND)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)
$(BUILD_DIR_PARSER)/%.o: $(SRC_DIR_PARSER)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)
$(BUILD_DIR_INPUT_LOGIC)/%.o: $(SRC_DIR_INPUT_LOGIC)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)
$(BUILD_DIR_MENU)/%.o: $(SRC_DIR_MENU)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)
$(BUILD_DIR_PLAYER_INTERACTIV_OBJ)/%.o: $(SRC_DIR_PLAYER_INTERACTIV_OBJ)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)
$(BUILD_DIR_SCORE_LOGIC)/%.o: $(SRC_DIR_SCORE_LOGIC)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)
$(BUILD_DIR_OPTIONS)/%.o: $(SRC_DIR_OPTIONS)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)
$(BUILD_DIR_DIFFICULTY)/%.o: $(SRC_DIR_DIFFICULTY)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)
$(BUILD_DIR_VIDEO)/%.o: $(SRC_DIR_VIDEO)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)


# deletes your built objects and executable
.PHONY: clean
clean:
	-rm -rf $(BUILD_DIR_SRC) $(BUILD_DIR_COMMANDS) $(BUILD_DIR_PARSER) $(BUILD_DIR_INPUT_LOGIC) $(BUILD_DIR_MENU) $(BUILD_DIR_PLAYER_INTERACTIV_OBJ) $(BUILD_DIR_SCORE_LOGIC) $(BUILD_DIR_OPTIONS) $(BUILD_DIR_DIFFICULTY) $(BUILD_DIR_VIDEO) $(TARGET)

# makes build direcotry, updates your objects, builds your executable, launches your program
.PHONY: run
run: 
	+$(MAKE) all
	$(RUN)

# explains the only three options you should be using (unless you build more of your own)
.PHONY: help
help:
	@echo "make       - builds/updates everything, is ready to run with '$(RUN)' after completion"
	@echo "make clean - removes object file folder and executable"
	@echo "make run   - builds/updates everything, runs immediately"
	@echo "src: " $(OBJECTS)