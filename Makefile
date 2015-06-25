compile:
	g++ -std=c++11 -D_REENTRANT -pthread main.cpp -o main
verbose:
	g++ -v -std=c++11 -D_REENTRANT -pthread main.cpp -o main
