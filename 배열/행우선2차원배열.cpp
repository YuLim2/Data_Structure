#include<stdio.h>
int main(){
	int a[3][2];
	printf("%8X, %8X, %8X\n", &a[0][0], &a[1][0], &a[2][0]);    //�� ��ȭ�� �ּ� ��ȭ
	printf("%d\n", &a[1][0]-&a[0][0]);    //�� ���� ũ��
	return 0;
}
