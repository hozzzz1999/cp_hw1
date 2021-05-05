/*Merge sort*/
#include "myheader.h"
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

int partition(int number[], int left, int right) { 
    int i = left - 1; 
    int j;
    for(j = left; j < right; j++) { 
        if(number[j] <= number[right]) { 
            i++; 
            SWAP(number[i], number[j]); 
        } 
    } 
    SWAP(number[i+1], number[right]); 
    return i+1; 
} 

void QuickSort(int number[], int left, int right) { 
    if(left < right) { 
        int pivot = partition(number, left, right); 
        QuickSort(number, left, pivot-1); 
        QuickSort(number, pivot+1, right); 
    } 
} 

int main()
{
    FILE *fp;
    struct timeval start;
    struct timeval end;

    if((fp = fopen("datatest1.txt","r+")) == NULL){
        perror("open file fail!\n");
        exit(1);
    }
    int unsorted[TEST_DATA_CNT];
    for(register int cnt = 0; cnt < TEST_DATA_CNT; cnt++){
        fscanf(fp, "%d",&unsorted[cnt]);
    }
    printf("排序前：\n");
    gettimeofday(&start, NULL); //將要測試的函式放在兩個gettimeofday（開始和結束）內
    QuickSort(unsorted, 0, TEST_DATA_CNT-1);
    gettimeofday(&end, NULL);

    printf("排序後：\n");
    for(register int i = 0; i < TEST_DATA_CNT; i++)
    {
        printf("%d\n", unsorted[i]);
    }
    unsigned long times;
    times = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
    printf("sorting time is %ld\n", times);
    return 0;
}