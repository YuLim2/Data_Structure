#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10
typedef int ELEMENT; //int 대신에 ELEMENT를 써서 스택 쓰기.
typedef struct Stack{
   ELEMENT buf[STACK_SIZE];
   int top;
}STACK; //구조체 만들기.

void createStack( STACK *s );	//스택을 만드는 함수 
int isFull( STACK *s );	//스택이 가득 찼을 때 
int isEmpty( STACK *s );	//스택이 비었을 때 
void Push( STACK *s, ELEMENT data );	//스택에 추가 
ELEMENT Pop( STACK *s );	//스택에서 제거 

int main(){
   int menu;
   ELEMENT data ;
   STACK stack;
   
   createStack( &stack );
   do{
      printf("1:push, 2:pop, 0:exit : ");
      scanf("%d", &menu);
      switch( menu ){
         case 1 :	//1을 입력하면 스택에 데이터 입력 
            printf("데이터 입력 : ");
            scanf("%d", &data);
            Push( &stack, data );
            break;
         case 2 :	//2를 입력하면 톱오버에 있는 데이터 삭제 
        data = Pop(&stack);
        if( data )
              printf("pop 데이터 : %d\n", data);
            break;
      case 0 :	//0 입력시 종료 
        break;
         default :
            printf("잘못된 입력 입니다. \n");
            break;
      }
   }while( menu );
}

void createStack( STACK *s ){  // top 포인터를 -1로 초기화
   s->top=-1;
}
int isFull( STACK *s ){   // 스택이 가득 차 있으면 true 리턴;
   return s->top+1==STACK_SIZE;
   
}
int isEmpty( STACK *s ){   // 스택이 비어 있으면 true 리턴
   return s->top==-1;

}
void Push( STACK *s, ELEMENT data ){ //스택이 가득 차 있으면 문구 출력 후 리턴, 아니면 push
   if(isFull(s)){
      printf("stack is full\n");
      return;
   }
   s->buf[++(s->top)] = data;	//push 
   
}
int Pop( STACK *s ){  //스택이 비어  있으면 문구 출력 후 0 리턴, 아니면 맨 위 데이터 리턴
   if(isEmpty(s)){
      printf("stack is empty\n");
      return 0;
   }
   return s->buf[(s->top)--];	//맨 위 데이터 
}
