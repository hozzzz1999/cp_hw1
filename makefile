all: quicksort_num.c quicksort_char.c mergesort_num.c mergesort_char.c radixsort_char.c radixsort_num.c myheader.h
	gcc quicksort_num.c -o quick1
	gcc quicksort_char.c -o quick2
	gcc mergesort_num.c -o merge1
	gcc mergesort_char.c -o merge2
	gcc -mcmodel=large  radixsort_num.c -o radix1
	gcc -mcmodel=large  radixsort_char.c -o radix2   
clean:
	rm quick1 quick2 merge1 merge2 radix1 radix2
