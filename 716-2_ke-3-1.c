#include <stdio.h>

typedef struct node
{
	int value;
	struct node* next;
	struct node* prev;
} node;

typedef struct list
{
	struct node* head;
	struct node* tail;
	struct node* current; // текущий элемент
} list;

// инициализация списка
void init_list( list* lst )
{
	lst->head = NULL;
	lst->tail = NULL;
	lst->current = NULL;

	return;
}

// удаление списка
int destroy( list* lst )
{
	node* temp_ptr = NULL;
	while( lst->head != NULL )
	{
		node* temp_ptr = lst->head->next;
		free( lst->head );
		lst->head = temp_ptr;
	}

	return 0;
}

// проверка списка на пустоту
int isEmpty( list* lst )
{
	return lst->head == NULL;
}

// поиск элемента по значению, вернуть NULL, если элемент не найден
node* find( list* lst, int value )
{
	node* temp_ptr = lst->head;
	while( temp_ptr != NULL )
	{
		if( temp_ptr->value == value )
		{
			return temp_ptr;
		}
		temp_ptr = temp_ptr->next;
	}
	return NULL;
}

// вставка элемента после текущего
int append( list* lst, int value )
{
	node* new_node = (node*) malloc( sizeof(node) );

	new_node->value = value;

	if( isEmpty( lst ) == 1 )
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		lst->head = new_node;
		lst->tail = new_node;
		lst->current = new_node;
		return 0;
	}

	if( lst->current->next == NULL ) //если текущий является последним
	{
	    lst->current->next = new_node;
		new_node->next = NULL;
		lst->tail = new_node;
	}
	else
	{
		new_node->next = lst->current->next;
		lst->current->next->prev = new_node;
		lst->current->next = new_node;
	}
	new_node->prev = lst->current;
	lst->current = new_node;

	return 0;
}

// вставка элемента перед текущим
int prepend( list* lst, int value )
{
	node* new_node = (node*) malloc( sizeof(node) );

	new_node->value = value;

	if( isEmpty( lst ) == 1 )
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		lst->head = new_node;
		lst->tail = new_node;
		lst->current = new_node;
		return 0;
	}

	new_node->next = lst->current;
	if( lst->current->prev == NULL ) //если текущий является первым
	{
	    lst->current->prev = new_node;
		new_node->prev = NULL;
		lst->head = new_node;
	}
	else
	{
		new_node->prev = lst->current->prev;
		lst->current->prev->next = new_node;
		lst->current->prev = new_node;
	}
	lst->current = new_node;

	return 0;
}

// удаление текущего элемента
int remove_node( list* lst )
{
	if( isEmpty( lst ) == 1 || lst->current == NULL )
	{
		return 0;
	}

	if( lst->current->next == NULL ) //если удаляется правый крайний
    {
        lst->tail = lst->tail->prev;
    }
	if( lst->current->prev == NULL ) //если удаляется левый крайний
    {
        lst->head = lst->head->next;
    }
    if( lst->current->prev != NULL ) lst->current->prev->next = lst->current->next;
    if( lst->current->next != NULL ) lst->current->next->prev = lst->current->prev;

	node* temp_node = lst->current;
	if( lst->current->next != NULL ) //смещение current вправо если возможно, иначе - влево
    {
        lst->current = lst->current->next;
    }
    else
    {
        lst->current = lst->current->prev;
    }

	free( temp_node );

	return 0;
}

// вывод списка в stdout в прямом порядке через пробел
int print_list( list* lst )
{
    if( isEmpty( lst ) == 1 )
	{
	    printf( "List is empty!\n" );
		return 0;
	}

	node* temp_node = lst->head;
	while( temp_node != NULL )
	{
		printf( "%d ", temp_node->value );
		temp_node = temp_node->next;
	}
	printf( "\n" );

	return 0;
}

void move_current( list* lst, int k )
{
    lst->current = lst->head;
    for( ; k > 1; k-- )
    {
        lst->current = lst->current->next;
    }

    return;
}

int main( void )
{
	list list_A;
	init_list( &list_A );

	int N = 0, temp = 0, temp1 = 0;

	scanf( "%d", &N );
	int i;
	for( i = 0; i < N; i++ )
	{
		scanf( "%d", &temp );
		append( &list_A, temp );
	}

	scanf( "%d", &temp );
	move_current( &list_A, temp );
	remove_node( &list_A );
	print_list( &list_A );

	scanf( "%d", &temp );
	list_A.current = find( &list_A, temp );
	remove_node( &list_A );
	print_list( &list_A );

	scanf( "%d %d", &temp, &temp1 );
	move_current( &list_A, temp );
	append( &list_A, temp1 );
	print_list( &list_A );

	scanf( "%d %d", &temp, &temp1 );
	move_current( &list_A, temp );
	prepend( &list_A, temp1 );
	print_list( &list_A );

	return 0;
}

