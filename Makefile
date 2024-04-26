all: parser

parser.tab.c parser.tab.h:	parser.y
	bison -t -v -d parser.y

lex.yy.c: lex.l parser.tab.h
	flex lex.l

parser: lex.yy.c parser.tab.c parser.tab.h st.c st.h
	gcc -o st -c st.c
	gcc -o parser parser.tab.c lex.yy.c


clean:
	rm parser parser.tab.c lex.yy.c parser.tab.h parser.output

test: all
	cat example.c | ./parser
