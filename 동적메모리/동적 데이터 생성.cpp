#include <stdio.h>
#include <stdlib.h>

int main(){
	int *ptr ;	//�����ͷ� ���� 
	
	ptr = malloc(sizeof(int));	//���� �޸� �Ҵ�  
	
	*ptr = 10 ;
	
	printf("%8X, %d\n", ptr, *ptr );	//�ּ�, �� ��� 
	
	return 0;
}
