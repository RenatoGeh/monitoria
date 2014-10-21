#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

Node* Node_new(void) {
	Node* this;

	this = (Node*) malloc(sizeof(Node));
	this->value = (DataType*) malloc(sizeof(DataType));
	this->next = NULL;

	return this;
}

void Node_free(Node* this) {
	free(this->value);
	free(this);
}

DataType Node_get(Node* this) {
	return *((DataType*)this->value);	
}

void Node_set(Node* this, DataType val) {
	*((DataType*)this->value) = val;
}

Stack* Stack_new(void) {
	Stack* this;

	this = (Stack*) malloc(sizeof(Stack));
	this->head = Node_new();
	this->size = 0;

	return this;
}

void Stack_free(Stack* this) {
	Node* it;
	Node* next;

	for(it=this->head;it!=NULL;it=next) {
		next = it->next;
		Node_free(it);
	}

	free(this);
}

bool Stack_isEmpty(Stack* this) {
	return this->size == 0;
}

void Stack_enqueue(Stack* this, DataType data) {
	Node* new_val = Node_new();

	Node_set(new_val, data);
	new_val->next = this->head->next;
	this->head->next = new_val;
	
	++(this->size);
}

DataType Stack_dequeue(Stack* this) {
	DataType ret_val;
	Node* next;

	if(this->size == 0) {
		puts("Stack empty.");
		return -1;
	}

	ret_val = Node_get(this->head->next);
	next = this->head->next->next;
	Node_free(this->head->next);
	this->head->next = next;

	--(this->size);

	return ret_val;
}

void Stack_clear(Stack* this) {
	Node* it;
	Node* next;

	for(it=this->head->next;it!=NULL;it=next) {
		next = it->next;
		Node_free(it);
	}

	this->head->next = NULL;
	this->size = 0;
}

void Stack_debug(Stack* this) {
	Node* it;
	int i=0;

	for(it=this->head->next;it!=NULL;it=it->next) {
		printf("[%d]=%d\n", i, (int)(*((char*)it->value)));
		++i;
	}
}

