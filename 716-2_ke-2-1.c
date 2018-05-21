#include <stdio.h>

int main ( void )
{
	int N = 0, temp = 0;
	int SUM = 0;

	printf( "\nN = " );
	scanf( "%d", &N );

	int i;
	for( i = 0; i < N; i++ )
	{
		printf( "%d: ", i+1 );
		scanf( "%d", &temp );
		SUM += temp;
	}

	printf( "\nSUM = %d\n", SUM );

	return 0;
}
