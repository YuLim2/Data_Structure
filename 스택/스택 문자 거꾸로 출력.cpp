#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 10

typedef char ELEMENT;
typedef struct Stack{
   ELEMENT buf[STACK_SIZE];
   int top;
}STACK;

void createStack( STACK *s );	//������ ����� �Լ� 
int isFull( STACK *s );	//������ ���� á�� �� 
int isEmpty( STACK *s );	//������ ����� �� 
void Push( STACK *s, ELEMENT data );	//���ÿ� �߰� 
ELEMENT Pop( STACK *s );	//���ÿ��� ���� 

int main(){
   int menu, i = 0, bul = 1;
   ELEMENT data ;
   STACK stack;
   ELEMENT str[100] = {};
   
   createStack( &stack );
 
   scanf ("%s", str);
   
   while (!isFull(&stack)) {
      Push(&stack, str[i]);
      i += 1;
   }
   while (!isEmpty(&stack)){
      printf ("%c", Pop(&stack));
   }
}

void createStack( STACK *s ){  // top �����͸� -1�� �ʱ�ȭ
   s->top = -1;
}

int isFull( STACK *s ){   // ������ ���� �� ������ true ����;
   return (s->top+1) == STACK_SIZE;
}

int isEmpty( STACK *s ){   // ������ ��� ������ true ����
   return s->top == -1;
}

void Push( STACK *s, ELEMENT str){	 //������ ���� �� ������ ���� ��� �� ����, �ƴϸ� push
      if( isFull(s)){
         printf("stack is full\n");
         return 0;
      }
      s->buf[++(s->top)] = str;	//push 
}

ELEMENT Pop(STACK *s){  //������ ���  ������ ���� ��� �� 0 ����, �ƴϸ� �� �� ������ ����
      if( isEmpty(s)){
         printf("stack is empty\n");
         return 0;
      }
      return s->buf[(s->top)--];	//�� �� ������
}
