install:
	g++ -c *.cpp
	g++ *.o -o snake -lsfml-graphics -lsfml-window -lsfml-system
	rm *.o
