CC=gcc
LOG=liblog.o
TEST=test

${TEST}:${LOG}
	${CC} test.c -o test ./${LOG}

${LOG}:
	${CC} -shared -fPIC -o ${LOG} log.c

clean:
	rm *.o test
