#include <stdio.h>
#include <stdlib.h>	//rand() �Լ� ���̺귯�� 

void genRandom( int a[][5], int r );
void outputArray( int a[][5], int r);
float averageScore( int *row, int size );
int main() {
	
	int score[4][5], i ;	//4�� ���� 5���� ���� �ο�  
	genRandom( score, 4 );	  //���� ���� �Լ� 
	outputArray( score, 4 );	//���� ��� 
	
	for( i = 0 ; i < 4 ; i ++ ){
		printf("���� %d : %.2f\n", i+1, averageScore( score[i], 5) );	//��� ��� 
	}
	
	return 0;
} 
void genRandom( int a[][5], int r ){
	int i, j;
	for( i = 0 ; i < r ; i ++ )
		for( j = 0 ; j < 5 ; j ++ )
			a[i][j] = rand()%10+1;	//ū ���� 10���� �������� �� ������ 
		}
void outputArray( int a[][5], int r){
	int i, j;
	for( i = 0 ; i < r ; i ++ ){
		for( j = 0 ; j < 5 ; j ++ )
			printf("%5d", a[i][j] );	//�迭 ��� 
		printf("\n");
	}
}
float averageScore( int *row, int size ){
	int max = 0, min = 11, sum =0, average, i;
	
	for( i = 0; i < size; i++){
		if(row[i] > max) max = row[i];	//max ���� 
		else if(row[i] < min) min = row[i];	//min ���� 
		sum += row[i];	//row[i]�� �� ���ϱ� 
	}
	sum = sum - (max+min);	//sum���� �ִ�, �ּڰ� ����            
	return sum/3.0;		//�ִ�, �ּڰ� ������ 3������ ��� 
}
