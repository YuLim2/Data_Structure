3#include<stdio.h>
#include<stdlib.h>
typedef int ELEMENT;
typedef struct node{	//NODE라는 구조체 정의  
    ELEMENT data;
    struct node *next;
}NODE;
NODE *createNode( ELEMENT data );	
void printAll( NODE *ptr );ㄴ 
int main(){
    NODE *head;

    head = createNode( 10 );
    printAll( head );      
}
NODE *createNode( ELEMENT data ){	//NODE 데이터 타입의 node를 생성하는 함수 
    NODE *new = (NODE *)malloc( sizeof(NODE) ); 	//새 노드인 new에 메모리 할당 
    new->data = data;
    new->next = NULL;
	  return new;
}
void printAll( NODE *ptr ){
    while( ptr ){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
