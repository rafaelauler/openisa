/* hello world example */

int fib(int n);

int
main() {
  return fib(45);
}

int
fib(int n) {
  if (n == 1 || n == 2)
    return 1;
  return fib(n-1) + fib(n-2);
}


