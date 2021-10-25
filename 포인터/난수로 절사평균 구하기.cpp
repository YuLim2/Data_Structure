#include <stdio.h>
#include <stdlib.h>	//rand() 함수 라이브러리 

void genRandom( int a[][5], int r );
void outputArray( int a[][5], int r);
float averageScore( int *row, int size );
int main() {
	
	int score[4][5], i ;	//4명에 대해 5명이 점수 부여  
	genRandom( score, 4 );	  //난수 생성 함수 
	outputArray( score, 4 );	//점수 출력 
	
	for( i = 0 ; i < 4 ; i ++ ){
		printf("선수 %d : %.2f\n", i+1, averageScore( score[i], 5) );	//평균 출력 
	}
	
	return 0;
} 
void genRandom( int a[][5], int r ){
	int i, j;
	for( i = 0 ; i < r ; i ++ )
		for( j = 0 ; j < 5 ; j ++ )
			a[i][j] = rand()%10+1;	//큰 수를 10으로 나누었을 때 나머지 
		}
void outputArray( int a[][5], int r){
	int i, j;
	for( i = 0 ; i < r ; i ++ ){
		for( j = 0 ; j < 5 ; j ++ )
			printf("%5d", a[i][j] );	//배열 출력 
		printf("\n");
	}
}
float averageScore( int *row, int size ){
	int max = 0, min = 11, sum =0, average, i;
	
	for( i = 0; i < size; i++){
		if(row[i] > max) max = row[i];	//max 설정 
		else if(row[i] < min) min = row[i];	//min 설정 
		sum += row[i];	//row[i]값 다 더하기 
	}
	sum = sum - (max+min);	//sum에서 최댓값, 최솟값 빼기            
	return sum/3.0;		//최댓값, 최솟값 제외한 3가지의 평균 
}
