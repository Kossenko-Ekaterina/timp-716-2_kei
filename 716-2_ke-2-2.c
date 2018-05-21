#include <stdio.h>

int main ( void )
{
	int N = 0, temp = 0;
	int P = 1;
	
	printf( "\nN = " );
	scanf( "%d", &N );

	if( N == 0 ) P = 0;
	int i;
	for( i = 0; i < N; i++ )
	{
		printf( "%d: ", i+1 );
		scanf( "%d", &temp );
		P *= temp - (i+1);
	}

	printf( "\nP = %d\n", P );

	return 0;
}
