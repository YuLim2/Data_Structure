#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 10

typedef char ELEMENT;
typedef struct Stack{
   ELEMENT buf[STACK_SIZE];
   int top;
}STACK;

void createStack( STACK *s );	//스택을 만드는 함수 
int isFull( STACK *s );	//스택이 가득 찼을 때 
int isEmpty( STACK *s );	//스택이 비었을 때 
void Push( STACK *s, ELEMENT data );	//스택에 추가 
ELEMENT Pop( STACK *s );	//스택에서 제거 

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

void createStack( STACK *s ){  // top 포인터를 -1로 초기화
   s->top = -1;
}

int isFull( STACK *s ){   // 스택이 가득 차 있으면 true 리턴;
   return (s->top+1) == STACK_SIZE;
}

int isEmpty( STACK *s ){   // 스택이 비어 있으면 true 리턴
   return s->top == -1;
}

void Push( STACK *s, ELEMENT str){	 //스택이 가득 차 있으면 문구 출력 후 리턴, 아니면 push
      if( isFull(s)){
         printf("stack is full\n");
         return 0;
      }
      s->buf[++(s->top)] = str;	//push 
}

ELEMENT Pop(STACK *s){  //스택이 비어  있으면 문구 출력 후 0 리턴, 아니면 맨 위 데이터 리턴
      if( isEmpty(s)){
         printf("stack is empty\n");
         return 0;
      }
      return s->buf[(s->top)--];	//맨 위 데이터
}
