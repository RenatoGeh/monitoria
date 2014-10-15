
void ex3(void) {	
	Stack* st;
	char word[MAX_STRING_LENGTH], c;
	int i, x, y;

	st = Stack_new();

	while(scanf(" %s", word) != EOF) {
		for(i=0;word[i]!='\0';++i) {
			c = word[i];
			
			switch(c) {
				case '*':
					x = Stack_dequeue(st);
					y = Stack_dequeue(st);
					x *= y;
					Stack_enqueue(st, x);
				break;
				case '+':
					x = Stack_dequeue(st);
					y = Stack_dequeue(st);
					x += y;
					Stack_enqueue(st, x);
				break;
				default:
					Stack_enqueue(st, (int)(c-'0'));
			}
		}

		printf("v: %d\n", Stack_dequeue(st));
	}
}
