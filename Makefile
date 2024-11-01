.PHONY: qsort msort isort

qsort:
	gcc -o qsort qsort.c
	./qsort

msort:
	gcc -o msort msort.c
	./msort

isort:
	gcc -o isort isort.c
	./isort