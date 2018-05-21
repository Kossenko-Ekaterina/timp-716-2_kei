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

void add_node( int new_key, int new_value, Tree* tree_ptr )
{
	node* new_node_ptr = (node*) malloc( sizeof(node) );

	new_node_ptr->key = new_key;
	new_node_ptr->value = new_value;
	new_node_ptr->left = NULL;
	new_node_ptr->right = NULL;

	if( (*tree_ptr) == NULL ) // Åñëè äåðåâî ïóñòîå
	{
		(*tree_ptr) = new_node_ptr;
	}
	else // Èíà÷å èùåì íóæíîå ìåñòî
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
	if( (*tree_ptr) == NULL ) return; // Åñëè ïîääåðåâî ïóñòîå

	if( (*tree_ptr)->left != NULL ) delete_tree( &(*tree_ptr)->left ); //Åñëè íå ïóñòàÿ ëåâàÿ âåòêà

	if( (*tree_ptr)->right != NULL ) delete_tree( &(*tree_ptr)->right ); //Åñëè íå ïóñòàÿ ïðàâàÿ

	if( (*tree_ptr)->left == NULL && (*tree_ptr)->right == NULL ) //Â ïðèíöèïå ýòî óñëîâèå è íåíóæíî
	{
		free( (*tree_ptr) ); (*tree_ptr) = NULL;
	}

	return;
}

void search( int s_key, Tree* tree_ptr )
{
    node* temp_node_ptr = (*tree_ptr);

	int level = 0;

	while( 1 )
	{
		if( temp_node_ptr == NULL )
		{
			printf( "%d\n", -1 );
			return;
		}

		if( s_key == temp_node_ptr->key )
		{
			printf( "%d %d\n", level, temp_node_ptr->value );
			return;
		}

		if( s_key > temp_node_ptr->key )
		{
			temp_node_ptr = temp_node_ptr->right;
		}
		else
		{
			temp_node_ptr = temp_node_ptr->left;
		}

		level++;
	}
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

int main()
{
	Tree MyTree = NULL; // Äåðåâî - óêàçàåëü íà êîðåíü

	int n, new_key, new_value;

	scanf( "%d", &n );

	int i = 0;
	for( ; i < n; i++ )
	{
		scanf( "%d %d", &new_key, &new_value );
		add_node( new_key, new_value, &MyTree );
	}

	print_tree( &MyTree, 0, '-' );

	int a, b, c;
	scanf( "%d %d %d", &a, &b, &c );

	search( a, &MyTree );
	search( b, &MyTree );
	search( c, &MyTree );

	delete_tree( &MyTree );

	return 0;
}
