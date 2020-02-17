#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define SIZE 4096
#define LENGTH 128

int stack[SIZE];
int top = 0;

void clear() {
  top = 0;
}

void push(int x) {
  assert(top < SIZE);
  stack[top++] = x;
}

int pop() {
  if (top > 0) {
    return stack[--top];
  } else {
    return -1;
  }
}

void pop_n(unsigned n) {
  if (top >= n) {
    top -= n;
  } else {
    top = 0;
  }
}

int get_top()  {
  if (top > 0) {
    return stack[top-1];
  } else {
    return -1;
  }
}

#define BUFFER_SIZE 1024

int main() {
  unsigned char buffer[BUFFER_SIZE];
  size_t buf_read = 0;
  for(int i = 0; i < BUFFER_SIZE; i++) {
    unsigned char c = getchar();
    if (c == (unsigned char)EOF) {
      break;
    }
    buf_read += 1;
    buffer[i] = c;
    printf("buffer[%u] = %u\n", i, buffer[i]);
  }

  int read_pos = 0;
  int i = 0;
  while(read_pos < buf_read) {
    switch((buffer[read_pos++]) % 30) {
    case 0:
      printf("%d: clear()\n", i);
      clear();
      break;
    case 1:
      printf("%d: push(%u)\n", i, (unsigned)buffer[read_pos]);
      read_pos++;
      read_pos++;
      read_pos++;      
      push(buffer[read_pos++]);
      break;
    case 2:
      printf("%d: pop()\n", i);      
      pop();
      break;
    case 3:
      printf("%d: pop_n(%u)\n", i, (unsigned)buffer[read_pos]);      
      pop_n(buffer[read_pos++]);
      break;
    case 4:
      printf("%d: get_top()\n", i);
      get_top();
      break;
    default:
      printf("%d: push(%u)\n", i, (unsigned)buffer[read_pos]);
      push(buffer[read_pos++]);
      break;      
    }
    i++;
  }
}
