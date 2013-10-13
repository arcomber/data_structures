#include <stdio.h> 
#include <stdlib.h>

typedef char stackdata;

typedef struct node_ {
	stackdata val;
	struct node_* next;
} node, * node_ptr;

node_ptr initStack(stackdata value) {
	node_ptr newnode = malloc(sizeof(node));
	newnode->val = value;
	newnode->next = NULL;
	return newnode;
}

int empty(node_ptr top) {
	return top == NULL;
}

/* head will thus change so return new head */
node_ptr push(node_ptr top, stackdata data) {
	if(top) {
		node_ptr newnode = malloc(sizeof(node));
		newnode->val = data;
		newnode->next = top;
		top = newnode;
	}
	return top;
}

/* head will thus change so return new head. Note something very bad happens if stack empty */
stackdata pop(node_ptr* top) {
	stackdata value;
	node_ptr tmp = *top;
	value = tmp->val;
	*top = (*top)->next;
	free(tmp);
	return value;
}

int main() {
    node_ptr mystack = initStack('A');
	mystack = push(mystack, 'B');
	mystack = push(mystack, 'C');

	while(!empty(mystack)) {
		printf("element val=%c\n", pop(&mystack));
	}

	return 0;
}
