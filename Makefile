
CXX = g++
CXXFLAGS = -Wall -std=c++17 `sdl2-config --cflags --libs` -lSDL2_ttf

SRC = main.cpp \
      utils/setup/setup.cpp \
      gui/utils/gui/gui.cpp \
      gui/components/button/button.cpp \
      gui/components/topbar/topbar.cpp \
      gui/components/slider/slider.cpp \
      gui/utils/text/textRenderer.cpp

HDR = gui/utils/gui/gui.h \
      utils/setup/setup.h \
      gui/utils/Component.h \
      gui/components/button/button.h \
      gui/components/topbar/topbar.h \
      gui/components/slider/slider.h \
      gui/utils/text/textRenderer.h

OBJ = $(SRC:.cpp=.o)
BIN = main

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(OBJ) -o $(BIN) $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(BIN)

