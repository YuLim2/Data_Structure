#include<stdio.h>
#include<string.h>

typedef struct Person{	//Person이라는 구조체 정의 
	char name[10];
	int age;
}PERSON;	//Person = PERSON 

void inputData( PERSON *p );	//Person자료형 p의 주소 
void outputData( PERSON *p );

int main(){
	PERSON p;
  
	inputData( &p );
  outputData( &p );
	
	return 0;
}
void inputData( PERSON *p ){
  scanf("%s", p->name );	//포인터로 멤버에 접근 
  scanf("%d", &(p->age) );
}
void outputData( PERSON *p ){
  printf("%s, %d\n", p->name, p->age);
}
