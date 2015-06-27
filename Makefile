compile:
	g++ -std=c++11 -D_REENTRANT -pthread main.cpp -o main
verbose:
	g++ -v -std=c++11 -D_REENTRANT -pthread main.cpp -o main
lex:
	cd lex && flex falcon.l && cd ..
yacc:
	cd yacc && yacc falcon.y && cd ..
clean:
	rm flex/lex.yy.c && rm yacc/
