char get_pair(char c) {
	if(c == ')') return '(';
	else if(c == ']') return '[';
	else if(c == '(') return ')';
	return ']';
}

void ex4(void) {
	Stack* st;
	char str[MAX_STRING_LENGTH];
	int i, counts;	
	char c, d;

	st = Stack_new();

	while(scanf("%s", str) != EOF) {
		counts = 0;

		/* Item A: */
		printf("Item A: ");
		
		for(i=0;str[i]!='\0';++i) {
			c = str[i];

			if(c == '(' || c == '[') {
				Stack_enqueue(st, c);
				putchar(c);
			} else {
				if(Stack_isEmpty(st)) {
					putchar(get_pair(c));
					putchar(c);
					++counts;
				} else {
					do {
						d = Stack_dequeue(st);
	
						if(d != get_pair(c)) {
							putchar(get_pair(d));
							++counts;
						} else {
							putchar(c);
							if(!Stack_isEmpty(st))
								Stack_dequeue(st);
						}
					} while(!Stack_isEmpty(st) || (d != get_pair(c)));
				}	
			}
		}

		while(!Stack_isEmpty(st)) {
			putchar(get_pair(Stack_dequeue(st)));
			++counts;
		}

		printf(" -> %d correcoes.\n", counts);

		Stack_clear(st);

		/* Item B: */
		counts = 0;
		printf("Item B: ");

		for(i=0;str[i]!='\0';++i) {
			c = str[i];

			if(c == '(' || c == '[') {
				Stack_enqueue(st, c);
				putchar(c);
			} else {
				if(Stack_isEmpty(st)) {
					putchar(get_pair(c));
					putchar(c);
					++counts;
				} else {
					d = Stack_dequeue(st);
					
					if(c != get_pair(d)) {
						putchar(get_pair(c));
						putchar(c);
						Stack_enqueue(st, d);
						++counts;
					} else
						putchar(c);
				}
			}
		}

		while(!Stack_isEmpty(st)) {
			putchar(get_pair(Stack_dequeue(st)));
			++counts;
		}

		printf(" -> %d correcoes.\n", counts);
	}

	Stack_free(st);
}
