CC=g++
CFLAGS=-c -I. -LSDL
LDFLAGS=-lSDL -lSDL_gfx
SOURCES=Main.cpp RenderingEngine.cpp Tetrominos.cpp Grid.cpp Logic.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tetris

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJECTS) $(EXECUTABLE)
