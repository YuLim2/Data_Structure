#include<stdio.h>
#include<stdlib.h>	//�ʿ��� ��� ���� 
int main(){
    int *ptr, i;
    
    ptr = (int *)malloc( sizeof(int)*5 );	//���� �޸� �Ҵ� 
   
    for( i=0; i<5; i++ ) {
        ptr[i] = i*10;
        printf("%8X => %d\n", &ptr[i], ptr[i]);	//�ּҿ� �� ��� 
    }
    free(ptr);	//�Ҵ��� �޸� ���� 
   
    return 0;
}
