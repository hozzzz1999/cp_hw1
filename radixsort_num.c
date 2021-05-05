/*radix sort*/
#include "myheader.h"

// Function to get the largest element from an array
int getMax(int *array, int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int *array, int size, int place) {
  int output[size]; // output array
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < size; i++)
        array[i] = output[i];
}

// Main function to implement radix sort
void RadixSort(int *array, int size) {
  // Get maximum element
  int max = getMax(array, size);
  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

int main(){
    FILE *fp;
    struct timeval start;
    struct timeval end;

    if((fp = fopen("datatest1.txt","r+")) == NULL){
        perror("open file fail!\n");
        exit(1);
    }
    int unsorted[TEST_DATA_CNT];
    for(register int cnt = 0; cnt < TEST_DATA_CNT; cnt++){
        fscanf(fp, "%d", &unsorted[cnt]);
    }
    printf("排序前：\n");
    gettimeofday(&start, NULL); //將要測試的函式放在兩個gettimeofday（開始和結束）內
    RadixSort(unsorted, TEST_DATA_CNT);
    gettimeofday(&end, NULL);

    printf("排序後：\n");
    for (register int i = 0; i < TEST_DATA_CNT; i++){
        printf("%d\n", unsorted[i]);
    }
    unsigned long times;
    times = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
    printf("sorting time is %ld\n", times);
    return 0;
}