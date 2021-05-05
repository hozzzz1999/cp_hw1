/*Merge sort*/
#include "myheader.h"

void Merge(int num[], int front, int mid, int end)
{
    int leftindex = front;
    int rightindex = mid + 1;
    int tempnumlength = end - front + 1;
    int tempnum[tempnumlength];
    int tempindex = 0;

    while ((leftindex <= mid) && (rightindex <= end)){
        if (num[leftindex] <= num[rightindex]){
            tempnum[tempindex] = num[leftindex];
            leftindex++;
        }
        else{
            tempnum[tempindex] = num[rightindex];
            rightindex++;
        }
        tempindex++;
    }
    if (leftindex > mid){
        while (rightindex <= end){
            tempnum[tempindex] = num[rightindex];
            rightindex++;
            tempindex++;
        }
    }
    else{
        while (leftindex <= mid){
            tempnum[tempindex] = num[leftindex];
            leftindex++;
            tempindex++;
        }
    }
    leftindex = front;
    for (tempindex = 0; tempindex < tempnumlength; tempindex++){
        num[leftindex] = tempnum[tempindex];
        leftindex++;
    }
}

void MergeSort(int num[], int front, int end){
    if (front < end){
        int mid = (front + end) / 2;
        MergeSort(num, front, mid);
        MergeSort(num, mid + 1, end);
        Merge(num, front, mid, end);
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
    MergeSort(unsorted, 0, TEST_DATA_CNT-1);
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