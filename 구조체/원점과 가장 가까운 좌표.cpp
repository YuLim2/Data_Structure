#include <stdio.h>
#include <math.h>
#define N 5
typedef struct point{	//point라는 구조체 정의 
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
   printf("원점에서 가장 가까운 좌표 : (%.0f, %.0f)", p[found].x, p[found].y);
   return 0;
}
void inputPoint( POINT *p, int n){	//점 입력 받기 
   for(int i=0; i<n; i++){
      printf("%d 번째  x y 좌표 입력 : ", i+1);
      scanf("%lf %lf",&p[i].x, &p[i].y);
   }
}
   
void outputPoint( POINT *p, int n){	//있는 점 출력 
   for(int i=0; i<n; i++){
      printf("%d 번째 좌표: (%.0f, %.0f)\n", i+1, p[i].x, p[i].y);
   }
   
}
int distance( POINT *p, int n){	//거리 구해서 제일 가까운 점 찾는 함수 
   double res[n];
   double min;
   min=sqrt(p[0].x*p[0].x+p[0].y*p[0].y);
   for(int i=1; i<n; i++){
      res[i]=sqrt(p[i].x*p[i].x+p[i].y*p[i].y);	//길이 구하기 
      if(min>res[i])	//최솟값 찾기 
         min=res[i];
   }
   for(int i=0; i<n; i++){
      if(res[i]==min){
         return i;
      }
   }
   return 0;
}
