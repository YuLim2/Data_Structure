#include <stdio.h>
int main() {
	int a[3][4] = {0};
	for( int i ; i < 3 ; i ++ )
		printf( "%8X\n", a[i] ) ;
	return 0;
}
