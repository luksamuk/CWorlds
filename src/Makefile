DEBUG_FLAGS = -g -Wall -DDEBUG
RELEASE_FLAGS = -O3 -Wall
BIN_FOLDER = ../bin
OBJ_FOLDER = ../obj

CXX = g++ --std=c++11

DEPENDANCY_FLAGS = -lSDL2 -lGL


EXECUTABLE_NAME = cworlds

SWLIB_OBJECTS = $(OBJ_FOLDER)/sonicworlds.o \
				$(OBJ_FOLDER)/commontypes.o



all: debug

release: CXX += $(RELEASE_FLAGS)
release: binary


debug: CXX += $(DEBUG_FLAGS)
debug: binary

binary: $(SWLIB_OBJECTS) main.cpp
	$(CXX) $(SWLIB_OBJECTS) main.cpp -L$(BIN_FOLDER) -o $(BIN_FOLDER)/$(EXECUTABLE_NAME) $(DEPENDANCY_FLAGS)

$(OBJ_FOLDER)/sonicworlds.o: SonicWorlds.cpp
	$(CXX) -c SonicWorlds.cpp -o $(OBJ_FOLDER)/sonicworlds.o

$(OBJ_FOLDER)/commontypes.o: SW_CommonTypes.cpp
	$(CXX) -c SW_CommonTypes.cpp -o $(OBJ_FOLDER)/commontypes.o

clean:
	rm -rf $(OBJ_FOLDER)/*.o
