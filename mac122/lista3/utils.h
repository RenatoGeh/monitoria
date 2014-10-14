#ifndef _UTILS_H
#define _UTILS_H

typedef enum boolean {
	false,
	true
} bool;

typedef int DataType;

struct _struct_node {
	void* value;
	struct _struct_node* next;
};

typedef struct _struct_node Node;

Node* Node_new(void);

void Node_free(Node* this);

DataType Node_get(Node* this);

DataType Node_set(Node* this, DataType val);

struct _struct_stack {
	Node* head;
	int size;
};

typedef struct _struct_stack Stack;

Stack* Stack_new(void);

void Stack_free(Stack* this);

bool Stack_isEmpty(Stack* this);

void Stack_enqueue(Stack* this, DataType data);

DataType Stack_dequeue(Stack* this);

#endif
