#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	int value;

	struct node* left;
	struct node* right;
} node;

typedef node* Tree;

typedef struct queue
{
	int n; //количество элементов в очереди
	node** data; //массив данных
} queue;

void delete_queue( queue** Q_ptr )
{
	if( (*Q_ptr)->data == NULL )
	{
		free( (*Q_ptr)->data );
	}
}

void push( node** new_elem, queue** Q_ptr )
{
	if( (*Q_ptr)->n == 0 )
	{
		(*Q_ptr)->data = (node**) malloc( sizeof(node*) * ++((*Q_ptr)->n) );
	}
	else
	{
		(*Q_ptr)->data = (node**) realloc( (*Q_ptr)->data, sizeof(node*) * ++((*Q_ptr)->n) );
	}

	(*Q_ptr)->data[((*Q_ptr)->n)-1] = (*new_elem);

	return;
}

node* pop( queue** Q_ptr )
{
	node* key = (*Q_ptr)->data[0];

	if( (*Q_ptr)->n == 1 )
	{
		free( (*Q_ptr)->data );
		(*Q_ptr)->data = NULL;
	}

	int i = 0;
	for( ; i < ((*Q_ptr)->n)-1; i++ )
	{
		(*Q_ptr)->data[i] = (*Q_ptr)->data[i+1];
	}
	(*Q_ptr)->data = (node**) realloc( (*Q_ptr)->data, sizeof(node*) * --((*Q_ptr)->n) );

	return key;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void add_node( int new_key, int new_value, Tree* tree_ptr )
{
	node* new_node_ptr = (node*) malloc( sizeof(node) );

	new_node_ptr->key = new_key;
	new_node_ptr->value = new_value;
	new_node_ptr->left = NULL;
	new_node_ptr->right = NULL;

	if( (*tree_ptr) == NULL ) // Если дерево пустое
	{
		(*tree_ptr) = new_node_ptr;
	}
	else // Иначе ищем нужное место
	{
		node** temp_node_ptr = tree_ptr;

		while( (*temp_node_ptr) != NULL )
		{
			if( new_node_ptr->key > (*temp_node_ptr)->key )
			{
				temp_node_ptr = &(*temp_node_ptr)->right;
			}
			else
			{
				temp_node_ptr = &(*temp_node_ptr)->left;
			}
		}

		(*temp_node_ptr) = new_node_ptr;
	}

	return;
}

void delete_tree( Tree* tree_ptr )
{
	if( (*tree_ptr) == NULL ) return; // Если поддерево пустое

	if( (*tree_ptr)->left != NULL ) delete_tree( &(*tree_ptr)->left ); //Если не пустая левая ветка

	if( (*tree_ptr)->right != NULL ) delete_tree( &(*tree_ptr)->right ); //Если не пустая правая

	if( (*tree_ptr)->left == NULL && (*tree_ptr)->right == NULL ) //В принципе это условие и ненужно
	{
		free( (*tree_ptr) ); (*tree_ptr) = NULL;
	}

	return;
}

void print_tree( Tree* tree_ptr, int qTab, char tag )
{
	if( (*tree_ptr) != NULL )
	{
		print_tree( &(*tree_ptr)->right, qTab+1, '/' );

		int i = 0;
		for( ; i < qTab; i++ )
		{
			printf( "\t" );
		}
		printf( "%c(%d,%d)\n", tag, (*tree_ptr)->key, (*tree_ptr)->value );

		print_tree( &(*tree_ptr)->left, qTab+1, '\\' );
	}

	return;
}

void func( Tree* tree )
{
	queue* Q = (queue*) malloc( sizeof(queue) );
	Q->n = 0;
	Q->data = NULL;

	push( tree, &Q );
	while( Q->n != 0 )
	{
		node* temp_ptr = pop( &Q );
		printf( "(%d,%d)\n", temp_ptr->key, temp_ptr->value );
		if( temp_ptr->left != NULL ) push( &temp_ptr->left, &Q );
		if( temp_ptr->right != NULL ) push( &temp_ptr->right, &Q );
	}

	return;
}

int main()
{
	Tree MyTree = NULL; // Дерево - указаель на корень

	int n;
	scanf( "%d", &n );

	int new_key, new_value;
	int i = 0;
	for( ; i < n; i++ )
	{
		scanf( "%d %d", &new_key, &new_value );
		add_node( new_key, new_value, &MyTree );
	}

	print_tree( &MyTree , 0, '-');

	func( &MyTree );

	delete_tree( &MyTree );

	return 0;
}
