#include <stdio.h>
#include<string.h>
int myStrlen( char str[] );
int myStrlen2( char str[] );
int main() {
   char s[100];
   gets("%s", s);   printf("%d\n", myStrlen(s) ); // 문자 길이 
   printf("%d\n", myStrlen2(s)); // 문자 중 digit의 개수
   return 0;
}
int myStrlen( char str[] ){
   int num=0,i;
   for(i=0; i<100;i++){
      if(str[i]!='\0')
      num++;
		 else if(str[i]!=' '){
			 num++;
		 }
      else
         break;
   }
   return num;
}
int myStrlen2( char str[] ){
   int num1=0,i;
   for(i=0; i<100; i++){
      if(str[i]>='0' && str[i]<='9')
         num1++;
      else if (str[i] == '\0')
         break;
   }
return num1;
}
