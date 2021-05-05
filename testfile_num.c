#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define TEST_DATA_CNT 1000000

int main(){
    FILE *fp;
    srand(time(0));
    
    int *number = malloc(sizeof(int) * TEST_DATA_CNT);
    for(int cnt = 0; cnt < TEST_DATA_CNT; cnt++){
        number[cnt] = rand() % 100000 + 1;
        printf("%d\n", number[cnt]);
    }
    if((fp = fopen("datatest1.txt","w+")) == NULL){
        perror("open file fail!\n");
        exit(1);
    }
    else{
        printf("suecess!\n");
        for(int cnt = 0; cnt < TEST_DATA_CNT; cnt++){
            //fwrite(number[cnt], sizeof(number[cnt]), 1, fp);
            fprintf(fp, "%d\n",number[cnt]);
        }
    }
    fclose(fp);
    return 0;
}