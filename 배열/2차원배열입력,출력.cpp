#include<stdio.h>
void inputArray( int a[][3], int r);    //3���� 2���� �迭, r�� �Է�
void outputArray( int a[][3], int r);
int main(){
	int array[4][3];
	int row = 4;
	
	inputArray( array, row );
	outputArray( array, row );
}
void inputArray( int a[][3], int r){
	int i, j;
	for(i=0; i <r; i ++)
		for( j=0; j<3; j++)
			scanf("%d", &a[i][j]);    //[4][3]�� �Է�
}
void outputArray( int a[][3], int r){
	int i, j;
	for(i=0; i <r; i ++){
		for( j=0; j<3; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
}
