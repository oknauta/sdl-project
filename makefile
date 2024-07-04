build:
	g++ $(SOURCE) -o $(OUTPUT) $(LIBRARIES)

SOURCE = ./src/*.cpp
OUTPUT = app.out
LIBRARIES = -l SDL2 -l SDL2_image