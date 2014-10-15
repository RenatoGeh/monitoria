
void ex1(void) {
	Stack* st;
	char word[MAX_STRING_LENGTH];
	int i;

	st = Stack_new();

	while(scanf(" %s", word) != EOF) {
		for(i=0;word[i]!='\0';++i)
			Stack_enqueue(st, word[i]);
		
		while(!Stack_isEmpty(st))
			printf("%c", Stack_dequeue(st));
		
		putchar(' ');
	}
	
	putchar('\n');
	Stack_free(st);
}

