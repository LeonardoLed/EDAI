// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, char item)
{
    if (isFull(stack)){
      printf("\tOverflow!\n");
      return;
    }

    stack->array[++stack->top] = item;
    //printf("%c pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
char pop(struct Stack* stack)
{
    if (isEmpty(stack)){
      printf("\tUnderflow!\n");
      return INT_MIN;
    }
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
char peek(struct Stack* stack)
{
    if (isEmpty(stack)){
      printf("\tUnderflow!\n");
      return INT_MIN;
    }

    return stack->array[stack->top];
}

void show(struct Stack* stack)
{

  printf("\nElements present in the stack: \n");
  for (int i = stack->top; i >= 0; --i)
      printf("%s\n", stack->array[i]);

}


int prec(char c) {

    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to return associativity of operators
char associativity(char c) {
    if (c == '^')
        return 'R';
    return 'L'; // Default to left-associative
}



// Driver program to test above functions
int main()
{

  char exp[]= "A+B*(C^D-E)^(F+G*H)-I";
  char result[strlen(exp)];
  int resultIndex = 0;

  struct Stack* stack = createStack(strlen(exp));

  printf("Length of string a = %zu \n",strlen(exp));


  for (int i = 0; i < strlen(exp); i++){
	  char c = exp[i];

	  // If the scanned character is an operand, add it to the output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result[resultIndex++] = c;
        }
		// If the scanned character is an ‘(‘, push it to the stack.
        else if (c == '(') {
            push(stack, c);
        }
		// If the scanned character is an ‘)’, pop and add to the output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
            while (!(isEmpty(stack)) && peek(stack) != '(') {
                result[resultIndex++] = pop(stack);
            }
            pop(stack);
        }
        // If an operator is scanned
        else {
            while ( !(isEmpty(stack)) && (prec(c) < prec(peek(stack)) || prec(c) == prec(peek(stack)) && associativity(c) == 'L'))
            {
                result[resultIndex++] = pop(stack);
            }
            push(stack,c);
        }
    }

	 // Pop all the remaining elements from the stack
    while (!(isEmpty(stack))) {
        result[resultIndex++] = pop(stack);
    }

    result[resultIndex] = '\0';
    printf("%s\n", result);


    return 0;
  }
