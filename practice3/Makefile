##exec
palindrome: functions.o tree.o main.cpp
	g++ -Wall functions.o tree.o main.cpp -o palindrome

##functions code
functions.o: functions.cpp functions.h
	g++ -c -Wall functions.cpp -o functions.o

##tree
tree.o: tree.cpp tree.h
	g++ -c -Wall tree.cpp -o tree.o

##just for checking main method
main: main.cpp
	g++ -c -Wall main.cpp -o main.o

clean:
	rm -f *.o
	rm -f palindrome