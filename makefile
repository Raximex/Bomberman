compile:./main.cpp
	g++ -c ./main.cpp
	g++ -c ./src/Graphics/MainMenu.cpp
	g++ -c ./src/Graphics/Graphics.cpp
	g++ Graphics.o MainMenu.o main.o  -o app -lsfml-graphics -lsfml-window -lsfml-system

run:
	./app