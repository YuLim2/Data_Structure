#include<stdio.h>
#include<string.h>
struct Person{	//Person�̶�� ����ü ���� 
	char name[10];
	int age;
};
int main(){
	struct Person p;	//Person�̶�� �ڷ����� p ���� 
	scanf("%s", p.name);
	scanf("%d", &p.age);
	
	printf("%s, %d\n", p.name, p.age);
	return 0;
}
