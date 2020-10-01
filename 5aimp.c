#include "5a.h"

Node* create_node(int data , Node* link)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->link = link;
    printf("Hello World");

    return node;
}


void list_initialize(List* ptr_list) 
{
	//TODO - initialize structure members to default values
    ptr_list->head = NULL;
	ptr_list->number_of_Nodes = 0 ;
}


void list_insert_front(List* ptr_list, int data) 
{
	//TODO - perform linked list implementation of push operation.
	Node* new = create_node(data,NULL) ;
	if ( ptr_list->head == NULL )
	{
		new->link = NULL ;
		ptr_list->head = new ;
		ptr_list->number_of_Nodes++ ;
		return ;
	}

	new->link = ptr_list->head ;
	ptr_list->head = new ;
	ptr_list->number_of_Nodes++ ;
}


const int Node_get_data(Node *Node_ptr) 
{
	//TODO - return the top most element
	return ( Node_ptr->data ) ;
}


void list_delete_front(List* ptr_list) 
{
	//TODO - perform linked list implementation of pop operation.
	struct Node* temp;
	if( ptr_list->number_of_Nodes == 1 )
	{
		ptr_list->head = NULL ;
		ptr_list->number_of_Nodes-- ;
		return ;
	}
	temp = ptr_list->head ;
	ptr_list->head = temp->link ;
	ptr_list->number_of_Nodes-- ;
	free(temp) ;
}




void list_destroy(List* ptr_list) 
{
	//TODO - free the allocated space
    Node *p = ptr_list->head;
	Node *q = NULL;
	printf("Hello");

    while (p != NULL)
    {
		q = p;
		p = p->link;
		free(q);
	}
	
    free(ptr_list);
}

void Stack_initialize(Stack *ptr_Stack) 
{
	//TODO - get the memory allocation for stack, and intern call list initialize
	ptr_Stack->ptr_list = (List*)malloc(sizeof(List));
	list_initialize( ptr_Stack->ptr_list ) ;
	printf("Hello world");
}

void Stack_push(Stack *ptr_Stack, int key) 
{
	//TODO	 - call the function list_insert_front
	list_insert_front( ptr_Stack->ptr_list , key) ;
}

void Stack_pop(Stack *ptr_Stack) 
{
	//TODO- call the function list_delete_front
	list_delete_front( ptr_Stack->ptr_list ) ;
}

int Stack_is_empty(Stack *ptr_Stack) 
{
	//TODO	- return 0 if stack is not empty
	int j = 0 ;
	if ( ptr_Stack->ptr_list->head == NULL )
	{
		j = 1 ;
	}
	return j ;
}

const int Stack_peek(Stack *ptr_Stack) 
{
	//TODO	- return the top most element of the stack
	return ( ptr_Stack->ptr_list->head->data ) ;
}

void Stack_destroy(Stack *ptr_Stack)
 {
	//TODO	- deallocate
	Stack* p = ptr_Stack ;
	list_destroy( p->ptr_list ) ;
	free ( p ) ;
	return ;
}

int match_parenthesis(const char* string)
{
	//TODO - implement the code to match paranthesis in a string which is passed as a parameter.
	Stack* st = (Stack*)malloc(sizeof(Stack)); ;
	Stack_initialize(st) ;
	int i = 0 ;
	while ( string[i] != '\0' )
	{
		if ( string[i] == '(' || string[i] == '{' || string[i] == '[' )
		{
			Stack_push( st , (int)string[i] ) ;
		}
		
		else if ( (string[i] == ')' && Stack_peek( st ) == (int)'(') || (string[i] == '}' && Stack_peek( st ) == (int)'{') || (string[i] == ']' && Stack_peek( st ) == (int)'[' ))
		{	
			Stack_pop( st ) ;	
		}
		else if ( string[i] == ')' || string[i] == '}' || string[i] == ']' )
		{
			Stack_push( st , (int)string[i] ) ;
		}
		else
		{
			Stack_destroy(st);
			return 0 ;
		}

		i++;
	}
	int ans = Stack_is_empty( st ) ;
	Stack_destroy(st);
	return ( ans) ;
}	




 

