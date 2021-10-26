#include <stdio.h>
#include <stdlib.h>

int main(){
	int *ptr ;	//포인터로 선언 
	
	ptr = malloc(sizeof(int));	//동적 메모리 할당  
	
	*ptr = 10 ;
	
	printf("%8X, %d\n", ptr, *ptr );	//주소, 값 출력 
	
	return 0;
}
