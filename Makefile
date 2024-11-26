.PHONY: test

test:
	gcc time_tester.c sorting_algorithms.c -o time_tester
	./time_tester

clean:
	rm -f *.out
