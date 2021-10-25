// 동적 배열 생성
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr, i;
    
    ptr = (int *)malloc( sizeof(int)*5 );
   
    for( i=0; i<5; i++ ) {
        ptr[i] = i*10;
        printf("%8X => %d\n", &ptr[i], ptr[i]);
    }
    free(ptr);
   
    return 0;
}
