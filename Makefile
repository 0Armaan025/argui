CXX = g++
CXXFLAGS = -Wall -std=c++17 `sdl2-config --cflags --libs` -lSDL2_ttf
SRC = main.cpp \
			setup.cpp \
      gui/gui.cpp \
      gui/components/button.cpp \
      gui/utils/textRenderer.cpp
HDR = gui/gui.h \
			setup.h \
			gui/utils/Component.h \
      gui/components/button.h \
      gui/utils/textRenderer.h
OBJ = $(SRC:.cpp=.o)
BIN = main

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(OBJ) -o $(BIN) $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(BIN)
