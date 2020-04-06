install:
	g++ -c *.cpp
	g++ *.o -o a.out -lsfml-graphics -lsfml-window -lsfml-system
	rm *.o
