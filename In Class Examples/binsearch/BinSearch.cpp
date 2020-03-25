#include <deepstate/DeepState.hpp>

using namespace deepstate;

#include<stdlib.h>

int binsearch(int a[], int target, size_t size) {
  if (size == 0) {
    return -1;
  }
  int low = 0;
  int high = size-1;
  int mid = (low + high)/2;
  while ((low < high) && (a[mid] != target)) {
    if (a[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
    mid = (low+high)/2;    
  }
  if (a[mid] == target) {
    return mid;
  }
  return -1;
}

#define MAX_SIZE 64

int cmpfunc (const void * a, const void * b) {
  int p1 = *(int*)a;
  int p2 = *(int*)b;
  if (p1 == p2) {
    return 0;
  }
  if (p1 < p2) {
    return -1;
  }
  return 1;
}

TEST(BinSearch, BinSearch) {
  int target = DeepState_Int();
  LOG(TRACE) << "Target: " << target;
  size_t size = DeepState_SizeInRange(0, MAX_SIZE);
  LOG(TRACE) << "Size: " << size;
  int a[MAX_SIZE];
  bool shouldFind = false;
  for (int i = 0; i < size; i++) {
    int v = DeepState_Int();
    a[i] = v;
    if (v == target) {
      shouldFind = true;
    }
  }
  qsort(a, size, sizeof(int), cmpfunc);
  for (int i = 0; i < size; i++) {
    LOG(TRACE) << "a[" << i << "] = " << a[i];    
  }
  int r = binsearch(a, target, size);
  LOG(TRACE) << "binsearch(a, target, size) = " << r;
  if (shouldFind) {
    ASSERT(r != -1) << "binsearch claims target not found!";
    ASSERT(a[r] == target) << "binsearch return bad index!";
  } else {
    ASSERT(r == -1);
  }
}
