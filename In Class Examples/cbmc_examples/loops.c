int nondet_int();

#define SIZE 5

int main() {
  int a[SIZE];
  for (int i = 0; i < SIZE; i++) {
    a[i] = nondet_int();
    printf("LOG: a[%d] = %d\n", i, a[i]);
  }

  // MAKE SURE NO DUPLICATES BY ADDING
  for (int i = 0; i < (SIZE-1); i++) {
    for (int j = i + 1; j < SIZE; j++) {
      if (a[i] == a[j]) {
	printf("LOG: setting a[%d] to %d to avoid matching a[%d]\n", i, a[i]+1, j);
	a[i] = a[i] + 1;
      }
    }
  }

  // CHECK FOR DUPLICATES
  for (int i = 0; i < (SIZE-1); i++) {
    for (int j = i + 1; j < SIZE; j++) {
      if (a[i] == a[j]) {
	printf("LOG a[%d] = %d = a[%d]\n", i, a[i], j);
      }
      assert(a[i] != a[j]);
    }
  }
}
