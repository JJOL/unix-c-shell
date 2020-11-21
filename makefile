.PHONY : test, build
test:
	gcc main.c prompt.c fileinterpreter.c common/kernel.c common/utils.c -o test.out
	./test
build:
	gcc main.c prompt.c fileinterpreter.c common/kernel.c common/utils.c -o shell.out