// �������� ����ü �����ϱ�
#include<stdio.h>
#include<stdlib.h>
typedef int ELEMENT;
typedef struct node{	//NODE��� ����ü ���� 
    ELEMENT data;
    struct node *next;
}NODE;

int main(){
    NODE *n1;	//�����͸� ������ ���� �Ҵ� 
    NODE *n2;
    NODE *ptr;

    n1 = (NODE *)malloc( sizeof(NODE) );	//�޸� �Ҵ� 
    n2 = (NODE *)malloc( sizeof(NODE) );

    n1->data = 10;
    n1->next = n2;

    n2->data = 20;
    n2->next = NULL;

    ptr = n1;
    while( ptr ){	//NULL�� �� ���� 
        printf("%d\n", ptr->data);	//ptr�� data ��� 
        ptr = ptr->next;	//ptr�� �������� �ѱ�� 
    }
}
