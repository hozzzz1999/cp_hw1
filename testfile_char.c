#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#define TEST_DATA_CNT 1000000

int main(){
    FILE *fp;
    srand(time(0));
    fp = fopen("datatest2.txt","w+");
    char tmp;
    char text[200]={'\0'};
    for(register int cnt = 0; cnt < TEST_DATA_CNT; cnt++){
        for(register int i = 0; i < 100; i++){
            tmp = rand() % 26 + 97;
            text[i] = tmp;
        }
        printf("%s\n",text);
        fprintf(fp,"%s\n",text);
        memset(text,'\0',sizeof(text));
    }
    printf("Suecess!\n");
    
    fclose(fp);
    return 0;
}