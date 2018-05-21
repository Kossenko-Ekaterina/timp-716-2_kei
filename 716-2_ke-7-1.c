#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int comb( int* arr, int n )
{
    int swap_count = 0;// количество перестановок
    double fakt = 1.2473309; // фактор уменьшения
    int step = n - 1;

    int i = 0, j = 0, temp = 0;

    while ( step >= 1 )
    {
        for ( i = 0; i + step < n; i++ )
        {
            if ( arr[i] > arr[i + step] )
            {
                temp = arr[i];
                arr[i] = arr[i + step];
                arr[i + step] = temp;
                swap_count++;
            }
        }
        step /= fakt;
    }

    // сортировка пузырьком
    for ( i = 0; i < n - 1; i++ )
    {
        bool swapped = false;
        for ( j = 0; j < n - i - 1; j++ )
        {
            if ( arr[j] > arr[j + 1] )
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                swap_count++;
            }
        }

        if ( !swapped ) break;
    }

    return swap_count;
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

    comb( arr, n );

    for( i = 0; i < n; i++ )
    {
        printf( "%d ", arr[i] );
    }
	printf( "\n" );
	
	return 0;
}
