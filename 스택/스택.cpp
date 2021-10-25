#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10
typedef int ELEMENT; //int ��ſ� ELEMENT�� �Ἥ ���� ����.
typedef struct Stack{
   ELEMENT buf[STACK_SIZE];
   int top;
}STACK; //����ü �����.

void createStack( STACK *s );	//������ ����� �Լ� 
int isFull( STACK *s );	//������ ���� á�� �� 
int isEmpty( STACK *s );	//������ ����� �� 
void Push( STACK *s, ELEMENT data );	//���ÿ� �߰� 
ELEMENT Pop( STACK *s );	//���ÿ��� ���� 

int main(){
   int menu;
   ELEMENT data ;
   STACK stack;
   
   createStack( &stack );
   do{
      printf("1:push, 2:pop, 0:exit : ");
      scanf("%d", &menu);
      switch( menu ){
         case 1 :	//1�� �Է��ϸ� ���ÿ� ������ �Է� 
            printf("������ �Է� : ");
            scanf("%d", &data);
            Push( &stack, data );
            break;
         case 2 :	//2�� �Է��ϸ� ������� �ִ� ������ ���� 
        data = Pop(&stack);
        if( data )
              printf("pop ������ : %d\n", data);
            break;
      case 0 :	//0 �Է½� ���� 
        break;
         default :
            printf("�߸��� �Է� �Դϴ�. \n");
            break;
      }
   }while( menu );
}

void createStack( STACK *s ){  // top �����͸� -1�� �ʱ�ȭ
   s->top=-1;
}
int isFull( STACK *s ){   // ������ ���� �� ������ true ����;
   return s->top+1==STACK_SIZE;
   
}
int isEmpty( STACK *s ){   // ������ ��� ������ true ����
   return s->top==-1;

}
void Push( STACK *s, ELEMENT data ){ //������ ���� �� ������ ���� ��� �� ����, �ƴϸ� push
   if(isFull(s)){
      printf("stack is full\n");
      return;
   }
   s->buf[++(s->top)] = data;	//push 
   
}
int Pop( STACK *s ){  //������ ���  ������ ���� ��� �� 0 ����, �ƴϸ� �� �� ������ ����
   if(isEmpty(s)){
      printf("stack is empty\n");
      return 0;
   }
   return s->buf[(s->top)--];	//�� �� ������ 
}
