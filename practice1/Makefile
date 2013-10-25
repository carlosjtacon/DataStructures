practice1: stack.o queue.o palindrom.o
	g++ -Wall stack.o queue.o palindrom.o -o practice1

tester: stack.o tester.c
	g++ -Wall stack.o tester.c -o tester

stack.o: stack.cpp
	g++ -c -Wall stack.cpp -o stack.o

queue.o: queue.cpp
	g++ -c -Wall queue.cpp -o queue.o

palindrom.o: palindrom.cpp
	g++ -c -Wall palindrom.cpp -o palindrom.o

clean:
	rm -f *.o
	rm -f tester
	rm -f practice1
