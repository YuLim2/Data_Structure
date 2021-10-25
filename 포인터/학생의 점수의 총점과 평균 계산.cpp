#include <stdio.h>
void inputArray( int a[][4], int row );    //4열을 입력받는 배열 
int totArray( int *a, int size);	

int main(){
  int score[3][4];	//3명의 4과목 점수 
  int i, j;
  int tot;	//총합 
  double avg;	//평균 
  
  printf("학생 3명, 각각 네 과목의 점수를 입력하세요\n");
  inputArray( score, 3);
  
  for( i = 0 ; i < 3 ; i ++ ){
    tot = totArray( score[i], 4 );	//사람당 4과목 
    avg = tot / 4. ;
    printf("총점 : %.d, 평균 : %.2lf\n", tot, avg);
  }
  return 0;
}
void inputArray( int a[][4], int row ){
  int i, j;
  for( i = 0 ; i < row; i ++ )	//명 수 3명
    for( j = 0 ; j < 4; j ++ )	//과목 수 4과목 
      scanf("%d", &a[i][j]);	//사람당 과목의 점수 입력 
}
int totArray( int *a, int size){	//함수의 전달인자를 배열의 포인터로 
  int i, tot=0;
  for( i = 0 ; i < size ; i ++ )	//행의 데이터 
    tot += a[i];
  return tot;
}
