#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

int get_pivot( int* A, int lo, int hi )
{
    return A[lo];
}

int partition( int* A, int lo, int hi )
{
    int pivot = A[lo];
    int i = lo - 1;
    int j = hi + 1;
    while( 1 )
    {
        do
        {
            i++;
        } while( A[i] < pivot );

        do
        {
            j--;
        } while( A[j] > pivot );

        if( i >= j ) return j;

        swap( &A[i], &A[j] );
    }
}


void quicksort( int* A, int lo, int hi )
{
    if( lo < hi )
    {
        int p = partition( A, lo, hi );
        quicksort( A, lo, p );
        quicksort( A, p+1, hi );
    }
}

int main()
{
    srand( time(NULL) );

    int* A = NULL;

    int n, i;
    printf( "n = " ); scanf( "%d", &n );

    A = (int*) malloc( sizeof(int)*n );

    for( i = 0; i < n; i++ )
    {
        //scanf( "%d", &x );
        A[i] = rand()%50;
        printf( "%d ", A[i] );
    }
    printf( "\n" );

    quicksort( A, 0, n-1 );

    for( i = 0; i < n; i++ )
    {
        //scanf( "%d", &x );
        printf( "%d ", A[i] );
    }
    printf( "\n" );

    for( i = 0; i < n-1; i++ )
    {
        //scanf( "%d", &x );
        if( A[i+1] < A[i] )
        {
            printf( "NO!" );
            break;
        }
    }

    free( A );

    return 0;
}
