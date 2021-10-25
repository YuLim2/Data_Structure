#include <stdio.h>
#include <math.h>
#define N 5
typedef struct point{	//point��� ����ü ���� 
   double  x,  y;
}POINT;

void inputPoint( POINT *p, int n );
void outputPoint( POINT *p, int n );
int distance( POINT *p, int n);

int main() {
   
   POINT p[5];
   int n=5;
   int found;
   inputPoint(p,n);
   outputPoint(p,n);
   found=distance(p,n);
   printf("�������� ���� ����� ��ǥ : (%.0f, %.0f)", p[found].x, p[found].y);
   return 0;
}
void inputPoint( POINT *p, int n){	//�� �Է� �ޱ� 
   for(int i=0; i<n; i++){
      printf("%d ��°  x y ��ǥ �Է� : ", i+1);
      scanf("%lf %lf",&p[i].x, &p[i].y);
   }
}
   
void outputPoint( POINT *p, int n){	//�ִ� �� ��� 
   for(int i=0; i<n; i++){
      printf("%d ��° ��ǥ: (%.0f, %.0f)\n", i+1, p[i].x, p[i].y);
   }
   
}
int distance( POINT *p, int n){	//�Ÿ� ���ؼ� ���� ����� �� ã�� �Լ� 
   double res[n];
   double min;
   min=sqrt(p[0].x*p[0].x+p[0].y*p[0].y);
   for(int i=1; i<n; i++){
      res[i]=sqrt(p[i].x*p[i].x+p[i].y*p[i].y);	//���� ���ϱ� 
      if(min>res[i])	//�ּڰ� ã�� 
         min=res[i];
   }
   for(int i=0; i<n; i++){
      if(res[i]==min){
         return i;
      }
   }
   return 0;
}
