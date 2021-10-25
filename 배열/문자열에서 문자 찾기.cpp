#include <stdio.h>
int main(void) {
  char s[10] ;
  int i=0, p=-1 ;
  scanf("%s", s);  
  while( s[i] != '\0' ){
    if( s[i] == 'A'){
      p = i;
      break;
    }
    i++ ;
  }
  if( p != -1 ) printf("%d¹øÂ°\n", p+1);
  else printf("not found\n");
  return 0;
}
