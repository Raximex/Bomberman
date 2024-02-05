compile:./main.cpp
	g++ -c ./main.cpp
	g++ -c ./src/Graphics/MainMenu.cpp
	g++ MainMenu.o main.o  -o app -lsfml-graphics -lsfml-window -lsfml-system

run:
	./app