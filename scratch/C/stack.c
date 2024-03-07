// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
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
void push(struct Stack* stack, int item)
{
    if (isFull(stack)){
      printf("\tOverflow!\n");
      return;
    }

    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack)){
      printf("\tUnderflow!\n");
      return INT_MIN;
    }
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
int peek(struct Stack* stack)
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
      printf("%d\n", stack->array[i]);
  
}

// Driver program to test above functions
int main()
{
  int size;

  printf("Welcome to Stack Creator\n");
  printf("Give please a Stack's Size: ");
  scanf("%d", &size);

  struct Stack* stack = createStack(size);



 int choice;

 while (1)
 {
     printf("\nPerform operations on the stack:");
     printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.Peek\n5.End");
     printf("\n\nEnter the choice: ");
     scanf("%d", &choice);

     switch (choice)
     {
     case 1:
         int x;
         printf("Give an element to add: ");
         scanf("%d", &x);
         push(stack, x);
         break;
     case 2:
         printf("%d popped from stack\n", pop(stack));
         break;
     case 3:
         show(stack);
         break;
     case 4:
          printf("%d the element in the top from stack\n", peek(stack));
		  break;
     case 5:
         exit(0);

     default:
         printf("\nInvalid choice!!");
     }
 }



return 0;
}
