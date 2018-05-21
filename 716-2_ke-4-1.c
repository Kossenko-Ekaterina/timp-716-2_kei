#include <stdio.h>

typedef struct node
{
	int value;
	struct node* next;
	struct node* prev;
} node;

typedef struct queue
{
	int size;
	struct node* head;
	struct node* tail;

} queue;

void init_queue( queue* q )
{
    q->tail = q->head = NULL;
    q->size=0;
	
	return;
}

int isEmpty(  queue* q )
{
	return q->head == NULL;     
}

int push(  queue* q, int value )
{
    node* new_node = (node*) malloc( sizeof(node) );

	new_node->value = value;
	new_node->next = NULL;

	if( isEmpty( q ) == 1 )
	{
		q->head = new_node;
		q->tail = new_node;
		q->head->prev = NULL;
	}
    else
	{
		q->tail->next = new_node;
	    new_node->prev = q->tail;
		q->tail = new_node;
	}
	
	q->size++;
	
	return 0;
}

int pop( queue* q )
{
	if( isEmpty( q ) == 1 ) 
	{
		printf( "Очередь пуста!\n" );
	}
	else
	{
		q->head=q->head->next;
		free( q->head->prev );
		q->head->prev = NULL;
		q->size--;
	}
	
	return 0;
}

int size( queue* q )
{
	return q->size;
}

int top( queue* q )
{
	if( isEmpty( q ) == 1 )
	{
		printf( "Очередь пуста!\n" );
		return 0;
	}
	else
	{
		return q->head->value;
	}
}

int back ( queue* q )
{
	if( isEmpty( q ) == 1 )
	{
		printf( "Очередь пуста!\n" );
		return 0;
	}
	else
	{
		return q->tail->value;
	}
}

void view( queue* q )
{
	if( isEmpty( q ) == 1 )
	{
		printf( "Очередь пуста!\n" );
	}
	else
	{
		node* ptr = q->head;
		while( ptr != NULL )
		{
			printf( "%d ", ptr->value );
			ptr = ptr->next;
		}
		printf( "\n" );
	}
	
	return;
}

void delete_queue( queue* q );

void delete_queue( queue* q )
{
	if( isEmpty( q ) == 0 )
	{
		node* ptr = q->head;
		while( ptr->next != NULL )
		{
			ptr = ptr->next;
			free( ptr->prev );
		}
		free( ptr );
	}
	
	return;
}

int main( void )
{
	queue queue_A;
	init_queue( &queue_A );

	int N = 0, temp = 0;

	scanf( "%d", &N );
	int i;
	for( i = 0; i < N; i++ )
	{
		scanf( "%d", &temp );
		push( &queue_A, temp );
	}
	
	view( &queue_A );
	
	printf( "top: %d\n", top( &queue_A ) );
	
	printf( "back: %d\n", back( &queue_A ) );
	
	pop( &queue_A );
	printf( "top after pop: %d\n", top( &queue_A ) );
	
	delete_queue( &queue_A );
	printf( "Queue deleted!\nBye!\n" );
	
	
	return 0;
}
