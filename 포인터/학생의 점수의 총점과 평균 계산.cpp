#include <stdio.h>
void inputArray( int a[][4], int row );    //4���� �Է¹޴� �迭 
int totArray( int *a, int size);	

int main(){
  int score[3][4];	//3���� 4���� ���� 
  int i, j;
  int tot;	//���� 
  double avg;	//��� 
  
  printf("�л� 3��, ���� �� ������ ������ �Է��ϼ���\n");
  inputArray( score, 3);
  
  for( i = 0 ; i < 3 ; i ++ ){
    tot = totArray( score[i], 4 );	//����� 4���� 
    avg = tot / 4. ;
    printf("���� : %.d, ��� : %.2lf\n", tot, avg);
  }
  return 0;
}
void inputArray( int a[][4], int row ){
  int i, j;
  for( i = 0 ; i < row; i ++ )	//�� �� 3��
    for( j = 0 ; j < 4; j ++ )	//���� �� 4���� 
      scanf("%d", &a[i][j]);	//����� ������ ���� �Է� 
}
int totArray( int *a, int size){	//�Լ��� �������ڸ� �迭�� �����ͷ� 
  int i, tot=0;
  for( i = 0 ; i < size ; i ++ )	//���� ������ 
    tot += a[i];
  return tot;
}
