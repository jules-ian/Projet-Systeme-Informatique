
void main(void) {
  int a;
  a = 3;
  if (a == 3) {
    print(a);
  } else {
    int b = compute(a, 2 * a);
   print(b);
  }
}

int compute(int a, int d) {
    int b, c = a + d * 5;
    b = a;
    while (c > 0) {
      b = b + a * 4;
    }
    return b;
}

