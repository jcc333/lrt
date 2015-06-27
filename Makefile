compile:
	g++ -std=c++11 -D_REENTRANT -pthread main.cpp -o main -ferror-limit=200
lex:
	cd lex && flex falcon.l && cd ..
yacc:
	cd yacc && yacc falcon.y && cd ..
clean:
	rm flex/lex.yy.c && rm yacc/
