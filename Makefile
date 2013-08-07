CC=g++
CFLAGS=-c -DLINUX -I. -LSDL/lib -LSDL_IMAGE/lib -LSDL_TTF/lib -LSDL_MIXER/lib
LDFLAGS=-lSDL -lSDL_gfx -lSDL_image -lSDL_ttf -lSDL_mixer
SOURCES=Main.cpp MD5.cpp credits.cpp diamond.cpp enemy.cpp functions_common.cpp game_logic.cpp high_scores.cpp load_screen.cpp main_player.cpp sprite_cut.cpp stone.cpp timer.cpp variables.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=NinjaP

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJECTS) $(EXECUTABLE)
