.PHONY : test, build
test:
	gcc main.c prompt.c fileinterpreter.c -o test.out
	./test
build:
	gcc main.c prompt.c fileinterpreter.c -o shell.out