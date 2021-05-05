/*Merge sort*/
#include "myheader.h"
char tmp_1[TEST_DATA_CNT][128];
char tmp_2[TEST_DATA_CNT][128];
char unsorted[TEST_DATA_CNT][200];

void Merge(int front, int mid, int end){
	int lenA = mid - front + 1;
	int lenB = end - (mid + 1) + 1;
	int i, j, k;

    //複製data到兩個tmp陣列
    for(i = 0; i < lenA; i++)
        strcpy(tmp_1[i], unsorted[front + i]);
	for(i = 0; i < lenB; i++)
        strcpy(tmp_2[i], unsorted[mid + 1 + i]);
	i = 0;
	j = 0;
	k = front;
	//while array tmp_1 and tmp_2 haven't finished scanning
	while(i < lenA && j < lenB){
		if(strcmp(tmp_1[i], tmp_2[j]) < 0){
			strcpy(unsorted[k], tmp_1[i]);
			i++;
		}
		else{
			strcpy(unsorted[k], tmp_2[j]);
			j++;
		}
		k++;
	}
	//Copy the remaining elements into unsorted[], if tmp_1 are any
	while(i < lenA){
		strcpy(unsorted[k], tmp_1[i]);
		i++;
		k++;
	}
	//Copy the remaining elements into unsorted[], if tmp_2 are any
	while(j < lenB){
		strcpy(unsorted[k], tmp_2[j]);
		j++;
		k++;
	}
}

void MergeSort(int front, int end){
	if(front < end){					
		int mid = (front + end) / 2;
		MergeSort(front, mid);
		MergeSort(mid + 1,end);
		Merge(front, mid, end);
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
        fscanf(fp, "%s",unsorted[cnt]);
    }
    printf("排序前：\n");
    gettimeofday(&start, NULL); //將要測試的函式放在兩個gettimeofday（開始和結束）內
    MergeSort(0, TEST_DATA_CNT-1);
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