3#include<stdio.h>
#include<stdlib.h>
typedef int ELEMENT;
typedef struct node{	//NODE��� ����ü ����  
    ELEMENT data;
    struct node *next;
}NODE;
NODE *createNode( ELEMENT data );	
void printAll( NODE *ptr );�� 
int main(){
    NODE *head;

    head = createNode( 10 );
    printAll( head );      
}
NODE *createNode( ELEMENT data ){	//NODE ������ Ÿ���� node�� �����ϴ� �Լ� 
    NODE *new = (NODE *)malloc( sizeof(NODE) ); 	//�� ����� new�� �޸� �Ҵ� 
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
