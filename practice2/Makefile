palindrome: functions.o main.cpp
	g++ -Wall functions.o main.cpp -o palindrome

##functions code
functions.o: functions.cpp
	g++ -c -Wall functions.cpp -o functions.o

##just for checking main method
main: main.cpp
	g++ -c -Wall main.cpp -o main.o

clean:
	rm -f *.o
	rm -f tester
	rm -f practice1