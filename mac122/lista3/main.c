#include <stdlib.h>
#include <stdio.h>

#include "utils.h"

#define MAX_STRING_LENGTH 256

#include "exs/ex1.h"
#include "exs/ex2.h"
#include "exs/ex3.h"
#include "exs/ex4.h"
#include "exs/ex5.h"
#include "exs/ex6.h"
#include "exs/ex7.h"

void (*exs[7])(void) = {ex1, ex2, ex3, ex4, ex5, ex6, ex7};

int main(int argc, char* args[]) { 
	int i = (int)(args[1][0]-'0');

	printf("Exercicio %d:\n", i);
	(*exs[i-1])();

	return 0;
}
