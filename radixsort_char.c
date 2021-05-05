/*radix sort*/
#include "myheader.h"
char unsorted[TEST_DATA_CNT][200];
char tmp[26][TEST_DATA_CNT][200];

void RadixSort(){
	int order[26] = {0};
	int n;

    //length = 100
    for(n = 99; n >= 0; n--){
		int i;
		for(i = 0; i < TEST_DATA_CNT; i++){
			int alpha = (int)(unsorted[i][n] - 97);
			strcpy(tmp[alpha][order[alpha]], unsorted[i]);
			order[alpha]++;
		}
		int k = 0;
		for(i = 0; i < 26; i++){
			if(order[i] != 0){
                int j;
				for(j = 0; j < order[i]; j++, k++){
					strcpy(unsorted[k], tmp[i][j]);
				}
			}
			order[i] = 0;
		}
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
    RadixSort();
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