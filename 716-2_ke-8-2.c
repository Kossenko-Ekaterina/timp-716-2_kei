#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int n;
    int* arr;
} heap;

int parent_index( int id )
{
    if( id == 0 )
        return -1;
    else
        return (id%2) ? (id/2) : (--id/2);
}

int child_index( int id )
{
    return 2*id + 1;
}

void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_up( heap* h, int p )
{
    int p_p = parent_index( p );

    if( p_p == -1 ) return;
    if( h->arr[p_p] > h->arr[p] )
    {
        swap( &h->arr[p_p], &h->arr[p] );
        bubble_up( h, p_p );
    }
}

void h_insert( heap* h, int x )
{
    if( h->n == 0 )
    {
        h->arr = (int*) malloc( sizeof(int)*(++h->n) );
    }
    else
    {
        h->arr = (int*) realloc( h->arr, sizeof(int)*(++h->n) );
    }
    h->arr[h->n-1] = x;

    bubble_up( h, h->n-1 );
}

void bubble_down( heap* h, int p )
{
    int c_p = child_index( p ), min_index = p, i;

    for( i = 0; i<=1; i++ )
    {
        if( c_p+i < h->n && h->arr[c_p+i] < h->arr[min_index] ) min_index = c_p+i;
    }

    if( min_index != p )
    {
        swap( &h->arr[p], &h->arr[min_index] );
        bubble_down( h, min_index );
    }
}

void extract_min( heap* h )
{
    if( h->n > 0 )
    {
        swap( &h->arr[0], &h->arr[h->n-1] );
        h->n--;
        bubble_down( h, 0 );
    }
}

int main()
{
    srand( time(NULL) );

    heap h;

    h.n = 0;
    h.arr = NULL;

    int i, x;

    int n;
    printf( "n = " ); scanf( "%d", &n );

    for( i = 0; i < n; i++ )
    {
        //scanf( "%d", &x );
        x = rand()%50;
        h_insert( &h, x );
    }

    while( h.n > 0 )
    {
        extract_min( &h );
    }

    for( i = 0; i < n; i++ )
    {
        printf( "%d ", h.arr[i] );
    }

    printf( "\n" );
    free( h.arr );

	return 0;
}
