.PHONY: qsort msort isort

qsort:
	gcc -o qsort.out qsort.c
	./qsort.out

msort:
	gcc -o msort.out msort.c
	./msort.out

isort:
	gcc -o isort.out isort.c
	./isort.out

clean:
	rm -f *.out