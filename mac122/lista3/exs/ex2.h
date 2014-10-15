
void ex2(void) {
	Stack* st;
	char word[MAX_STRING_LENGTH];
	int i;
	bool contains;

	st = Stack_new();

	while(scanf(" %s", word) != EOF) {
		contains = true;
	
		for(i=0;word[i]!='c';++i)
			Stack_enqueue(st, word[i]);
		
		for(++i;word[i]!='\0';++i)
			if(Stack_isEmpty(st) || (word[i] != Stack_dequeue(st))) {
				contains = false;
				break;
			}
		
		if(contains)
			puts("Pertence");
		else
			puts("Falso");
	}

	Stack_free(st);
}
