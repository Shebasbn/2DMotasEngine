build:
	g++ -Wall -std=c++17 -I"./libs/" src/*.cpp src/Game/*.cpp src/Logger/*.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua5.3 -o MotasEngine

run:
	./MotasEngine

clean:
	rm MotasEngine
