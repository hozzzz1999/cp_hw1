/*quick sort*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>
#define TEST_DATA_CNT 1000000
char unsorted[TEST_DATA_CNT][200];

void swap(char *a, char *b){
	char tmp[200];
	strcpy(tmp, a);
	strcpy(a, b);
	strcpy(b, tmp);
}

int partition(int left, int right) { 
	int i = left - 1, j;

	i = left - 1;
	for(j = left; j < right; j++){
		if(strcmp(unsorted[j], unsorted[right]) <= 0){
			i++;
			swap(unsorted[i], unsorted[j]);
		}
	}
	swap(unsorted[i+1], unsorted[right]);
    return i+1; 
} 

void QuickSort(int left, int right) { 
	if(left < right) { 
		int pivot = partition(left, right); 
		QuickSort(left, pivot - 1); 
		QuickSort(pivot + 1, right); 
	} 
} 

int main(){
    FILE *fp;
    struct timeval start;
    struct timeval end;

    if((fp = fopen("datatest2.txt","r+")) == NULL){
        perror("open file fail!\n");
        exit(1);
    }
    for(register int cnt = 0; cnt < TEST_DATA_CNT; cnt++){
        fscanf(fp, "%s", unsorted[cnt]);
    }
    printf("排序前：\n");
    gettimeofday(&start, NULL); //將要測試的函式放在兩個gettimeofday（開始和結束）內
    QuickSort(0, TEST_DATA_CNT-1);
    gettimeofday(&end, NULL);

    printf("排序後：\n");
    for (register int i = 0; i < TEST_DATA_CNT; i++){
        printf("%s\n", unsorted[i]);
    }
    unsigned long times;
    times = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
    printf("sorting time is %ld\n", times);
    return 0;
}