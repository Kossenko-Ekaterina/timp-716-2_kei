#include <stdio.h>
#include <stdlib.h>

void ShellsSort( int* arr, int n )
{
	int i = 0, j = 0, k = 0, temp = 0;

	for( k = n/2; k > 0; k /= 2 )
    {
        for( i = k; i < n; i++ )
        {
            temp = arr[i];
            for( j = i; j >= k; j -= k)
            {
                if( temp < arr[j - k] )
                    arr[j] = arr[j - k];
                else
                    break;
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    int n = 0;
    scanf( "%d", &n );

    int arr[n];
    int i;
    for( i = 0; i < n; i++ )
    {
        scanf( "%d", &arr[i] );
    }

    ShellsSort( arr, n );

    for( i = 0; i < n; i++ )
    {
        printf( "%d ", arr[i] );
    }

	printf( "\n" );
	
	return 0;
}
