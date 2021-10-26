// 동적으로 구조체 생성하기
#include<stdio.h>
#include<stdlib.h>
typedef int ELEMENT;
typedef struct node{	//NODE라는 구조체 정의 
    ELEMENT data;
    struct node *next;
}NODE;

int main(){
    NODE *n1;	//포인터를 선언한 동적 할당 
    NODE *n2;
    NODE *ptr;

    n1 = (NODE *)malloc( sizeof(NODE) );	//메모리 할당 
    n2 = (NODE *)malloc( sizeof(NODE) );

    n1->data = 10;
    n1->next = n2;

    n2->data = 20;
    n2->next = NULL;

    ptr = n1;
    while( ptr ){	//NULL에 갈 동안 
        printf("%d\n", ptr->data);	//ptr의 data 출력 
        ptr = ptr->next;	//ptr은 다음으로 넘기기 
    }
}
