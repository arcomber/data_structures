#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


typedef char* stackdata;

typedef struct node_ {
	stackdata val;
	struct node_* next;
} node, * node_ptr;

typedef struct {
	node_ptr top;
} stacktype, * stack;

stack initStack() {
	stack newnode = malloc(sizeof(stacktype));
	newnode->top = NULL;
	return newnode;
}

int empty(stack s) {
	return s->top == NULL;
}

/*  head will thus change so return new head */
void push(stack s, stackdata data) {
    node_ptr newnode = malloc(sizeof(node));
	newnode->val = malloc(strlen(data)+1);
	strcpy(newnode->val, data);
	newnode->next = s->top;
	s->top = newnode;
}

/* head will thus change so return new head. Note something very bad happens if stack empty 
Caller must free string */
stackdata pop(stack s) {
	stackdata value;
	node_ptr tmp = s->top;
	value = tmp->val;
	s->top = tmp->next;
	free(tmp);
	return value;
}

void free_stack(stack s) {
	while(!empty(s)) {
		pop(s);
	}
	free(s);
}

void get_data(stack s) {
   char data[64];
   const char* p = NULL;
   printf("Enter a string without spaces, new line to separate. Enter \'quit\' to end entering data\n");
   while(fgets(data, sizeof data, stdin)) {
	   if(strncmp(data, "quit", 4) == 0)
		   break;

	   push(s, data);	   
   }
}

int main() {
    stack s = initStack();
	get_data(s);
	while(!empty(s)) {
		char* tmp = pop(s);
		printf("element val=%s\n", tmp);
		free(tmp);
	}
    free_stack(s);
	return 0;
}
