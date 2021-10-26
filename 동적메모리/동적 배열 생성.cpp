#include<stdio.h>
#include<stdlib.h>	//필요한 헤더 파일 
int main(){
    int *ptr, i;
    
    ptr = (int *)malloc( sizeof(int)*5 );	//동적 메모리 할당 
   
    for( i=0; i<5; i++ ) {
        ptr[i] = i*10;
        printf("%8X => %d\n", &ptr[i], ptr[i]);	//주소와 값 출력 
    }
    free(ptr);	//할당한 메모리 해제 
   
    return 0;
}
