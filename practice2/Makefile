##exec
palindrome: SortedList.o functions.o main.cpp
	g++ -Wall SortedList.o functions.o main.cpp -o palindrome

##functions code
functions.o: functions.cpp
	g++ -c -Wall functions.cpp -o functions.o

##just for checking main method
main: main.cpp
	g++ -c -Wall main.cpp -o main.o

##SortedList
SortedList.o: SortedList.cpp
	g++ -c -Wall SortedList.cpp -o SortedList.o

##debugging list
listTester: listTester.cpp SortedList.o
	g++ -Wall SortedList.o listTester.cpp -o tester

clean:
	rm -f *.o
	rm -f palindrome