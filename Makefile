compile:
	g++ -std=c++11 -D_REENTRANT -pthread main.cpp -o main -ferror-limit=200
