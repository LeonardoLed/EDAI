// Deque implementation in C

#include <stdio.h>

#define MAX 10

void adding_by_head(int *, int, int *, int *);
void adding_by_tail(int *, int, int *, int *);
int removing_by_head(int *, int *, int *);
int removing_by_tail(int *, int *, int *);
void display(int *);
int count(int *);

int main() {
  int arr[MAX];
  int head, tail, i, n;

  head = tail = -1;
  for (i = 0; i < MAX; i++)
    arr[i] = 0;

  adding_by_tail(arr, 5, &head, &tail);
  adding_by_head(arr, 12, &head, &tail);
  adding_by_tail(arr, 11, &head, &tail);
  adding_by_head(arr, 5, &head, &tail);
  adding_by_tail(arr, 6, &head, &tail);
  adding_by_head(arr, 8, &head, &tail);

  printf("\nElements in a deque: ");
  display(arr);

  i = removing_by_head(arr, &head, &tail);
  printf("\nremoved item: %d", i);

  printf("\nElements in a deque after deletion: ");
  display(arr);

  adding_by_tail(arr, 16, &head, &tail);
  adding_by_tail(arr, 7, &head, &tail);

  printf("\nElements in a deque after addition: ");
  display(arr);

  i = removing_by_tail(arr, &head, &tail);
  printf("\nremoved item: %d", i);

  printf("\nElements in a deque after deletion: ");
  display(arr);

  n = count(arr);
  printf("\nTotal number of elements in deque: %d", n);
}

void adding_by_head(int *arr, int item, int *phead, int *ptail) {
  int i, k, c;

  if (*phead == 0 && *ptail == MAX - 1) {
    printf("\nDeque is full.\n");
    return;
  }

  if (*phead == -1) {
    *phead = *ptail = 0;
    arr[*phead] = item;
    return;
  }

  if (*ptail != MAX - 1) {
    c = count(arr);
    k = *ptail + 1;
    for (i = 1; i <= c; i++) {
      arr[k] = arr[k - 1];
      k--;
    }
    arr[k] = item;
    *phead = k;
    (*ptail)++;
  } else {
    (*phead)--;
    arr[*phead] = item;
  }
}

void adding_by_tail(int *arr, int item, int *phead, int *ptail) {
  int i, k;

  if (*phead == 0 && *ptail == MAX - 1) {
    printf("\nDeque is full.\n");
    return;
  }

  if (*phead == -1) {
    *ptail = *phead = 0;
    arr[*ptail] = item;
    return;
  }

  if (*ptail == MAX - 1) {
    k = *phead - 1;
    for (i = *phead - 1; i < *ptail; i++) {
      k = i;
      if (k == MAX - 1)
        arr[k] = 0;
      else
        arr[k] = arr[i + 1];
    }
    (*ptail)--;
    (*phead)--;
  }
  (*ptail)++;
  arr[*ptail] = item;
}

int removing_by_head(int *arr, int *phead, int *ptail) {
  int item;

  if (*phead == -1) {
    printf("\nDeque is empty.\n");
    return 0;
  }

  item = arr[*phead];
  arr[*phead] = 0;

  if (*phead == *ptail)
    *phead = *ptail = -1;
  else
    (*phead)++;

  return item;
}

int removing_by_tail(int *arr, int *phead, int *ptail) {
  int item;

  if (*phead == -1) {
    printf("\nDeque is empty.\n");
    return 0;
  }

  item = arr[*ptail];
  arr[*ptail] = 0;
  (*ptail)--;
  if (*ptail == -1)
    *phead = -1;
  return item;
}

void display(int *arr) {
  int i;

  printf("\n head:  ");
  for (i = 0; i < MAX; i++)
    printf("  %d", arr[i]);
  printf("  :tail");
}

int count(int *arr) {
  int c = 0, i;

  for (i = 0; i < MAX; i++) {
    if (arr[i] != 0)
      c++;
  }
  return c;
}