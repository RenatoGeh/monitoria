void ex5(void) { 
  Stack *op;
  char prefixa[MAX_STRING_LENGTH];
  char word[MAX_STRING_LENGTH];
  char c;
  int i, iprefixa, tam;
  
  while (scanf("%s", word) != EOF) {
    iprefixa = 0;
    op = Stack_new();
    tam = strlen(word);
    //varre a string ao contrario para calcular a notacao
    for (i = tam - 1; i >= 0; i--) {
      if (word[i] == ')')
        Stack_enqueue(op, word[i]); 
      else if (word[i] == '+' || word[i] == '-') {
        while (!Stack_isEmpty(op)) {
          c = Stack_dequeue(op);
          if (c == '*' || c == '/')
            prefixa[iprefixa++] = c;
          else {
            Stack_enqueue(op, c);
            break;
          }
        }
        Stack_enqueue(op, word[i]);  
      } 
      else if (word[i] == '*' || word[i] == '/') {
        Stack_enqueue(op, word[i]);   
      }
      else if (word[i] == '(') {
        while (!Stack_isEmpty(op)) {
          c = Stack_dequeue(op);
          if (c == ')') break;
          else 
            prefixa[iprefixa++] = c;
        }
      }
      else prefixa[iprefixa++] = word[i];
    }
    //coloca o restando dos operadores
    while (!Stack_isEmpty(op)) 
      prefixa[iprefixa++] = Stack_dequeue(op);

    //imprime a string ao contrario
    for (i = iprefixa - 1; i >= 0; i--)
      printf("%c", prefixa[i]);
    printf("\n");
    Stack_free(op); 
  }
}
