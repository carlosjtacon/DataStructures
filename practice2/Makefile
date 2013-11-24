practice1: stack.o queue.o functions.o main.cpp
	g++ -Wall stack.o queue.o functions.o main.cpp -o practice1

stack.o: stack.cpp
	g++ -c -Wall stack.cpp -o stack.o

queue.o: queue.cpp
	g++ -c -Wall queue.cpp -o queue.o

functions.o: functions.cpp
	g++ -c -Wall functions.cpp -o functions.o

##just for checking main method
justmain: main.cpp
	g++ -c -Wall main.cpp -o justmain.o

clean:
	rm -f *.o
	rm -f tester
	rm -f practice1

clena:
	rm -f *.o
	rm -f tester
	rm -f practice1