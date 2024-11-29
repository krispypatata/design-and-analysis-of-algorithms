.PHONY: test

test:
	gcc time_tester.c sorting_algorithms.c -o time_tester.out
	./time_tester.out

clean:
	rm -f *.out
