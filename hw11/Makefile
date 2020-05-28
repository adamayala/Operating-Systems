
test: blist
	for t in test*.sh; do ./$$t; echo $$?; done

blist: blist.c
	gcc -o blist blist.c

clean:
	rm -f blist *~
