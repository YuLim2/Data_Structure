#include<stdio.h>
#include<string.h>

typedef struct Person{	//Person�̶�� ����ü ���� 
	char name[10];
	int age;
}PERSON;	//Person = PERSON 

void inputData( PERSON *p );	//Person�ڷ��� p�� �ּ� 
void outputData( PERSON *p );

int main(){
	PERSON p;
  
	inputData( &p );
  outputData( &p );
	
	return 0;
}
void inputData( PERSON *p ){
  scanf("%s", p->name );	//�����ͷ� ����� ���� 
  scanf("%d", &(p->age) );
}
void outputData( PERSON *p ){
  printf("%s, %d\n", p->name, p->age);
}
