listtest: linkedList.c
	gcc linkedList.c -o listtest

run: listtest
	./listtest
