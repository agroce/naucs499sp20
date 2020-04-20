#include <deepstate/DeepState.hpp>
using namespace deepstate;

#include<time.h>

unsigned int stack[100];
size_t top = 0;

void push(unsigned int x) {
  stack[top++] = x;
}

void clear() {
  top = 0;
}

unsigned int pop() {
  if (top > 0) {
    return stack[--top];
  } else {
    return 0;
  }
}

int expensive_thing() {
  int sum = 0;
  for (int i = 0; i < top; i++) {
    if ((stack[i] % 2) == 0) {
      return 0;
    }
  }
  for (int i = 0; i < top; i++) {
    for (int j = 0; j < top; j++) {
      for (int k = 0; k < top; k++) {
        for (int l = 0; l < (stack[k] / 100); l++) {
          sum += stack[i] + stack[j] + stack[k];
        }
      }
    }
  }
  return sum;
}

#define LENGTH 100

TEST(Performance, Deadline) {
  top = 0;
  for (int i = 0; i < LENGTH; i++) {
    OneOf(
          [&] {
            unsigned int v = DeepState_UInt();
            LOG(TRACE) << "PUSH " << v;
            push(v);
          },
          [&] {
            LOG(TRACE) << "POP = " << pop();
          },
          [&] {
            LOG(TRACE) << "CLEAR";
            clear();
          },
          [&] {
            LOG(TRACE) << "STARTING EXPENSIVE_THING...";
            clock_t start, end;
            double cpu_time_used;
            start = clock();
            expensive_thing();
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            LOG(TRACE) << "EXPENSIVE THING TOOK " << cpu_time_used << " SECONDS";
            ASSERT (cpu_time_used < 5) << "USED MORE THAN 5 SECONDS CPU TIME!";
          });
  }
}
