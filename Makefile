.PHONY: qsort msort isort ssort bsort selsort hsort gisort

qsort:
	gcc -o qsort.out qsort.c
	./qsort.out

msort:
	gcc -o msort.out msort.c
	./msort.out

isort:
	gcc -o isort.out isort.c
	./isort.out

ssort:
	gcc -o ssort.out ssort.c
	./ssort.out

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