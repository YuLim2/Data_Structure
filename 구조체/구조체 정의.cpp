#include<stdio.h>
#include<string.h>
struct Person{	//Person이라는 구조체 정의 
	char name[10];
	int age;
};
int main(){
	struct Person p;	//Person이라는 자료형의 p 선언 
	scanf("%s", p.name);
	scanf("%d", &p.age);
	
	printf("%s, %d\n", p.name, p.age);
	return 0;
}
