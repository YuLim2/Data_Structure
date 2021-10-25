#include<stdio.h>
int main(){
	int jumsu[2][4] = { { 80, 96, 83, 100 }, { 88, 100, 96, 98 }};    //배열 초기화 
	int i, j;
	int row=2, col=4;
	for( i = 0 ; i < row ; i++ ){    //출력 
		for( j = 0 ; j < col ; j ++ )
			printf( "%5d", jumsu[i][j] );
		printf("\n");
	}
}
