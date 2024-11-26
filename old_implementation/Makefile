.PHONY: qsort msort isort shsort bsort selsort hsort gisort

test:
	gcc time_tester.c sorting_algorithms.c -o time_tester
	./time_tester

qsort:
	gcc -o qsort.out qsort.c
	./qsort.out

msort:
	gcc -o msort.out msort.c
	./msort.out

isort:
	gcc -o isort.out isort.c
	./isort.out

short:
	gcc -o short.out short.c
	./short.out

bsort:
	gcc -o bsort.out bsort.c
	./bsort.out

selsort:
	gcc -o selsort.out selsort.c
	./selsort.out

hsort:
	gcc -o hsort.out hsort.c
	./hsort.out

gisort:
	gcc -o gisort.out gisort.c
	./gisort.out

clean:
	rm -f *.out