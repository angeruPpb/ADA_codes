#include <iostream>
using namespace std;

int karatsuba(int x, int y, int n, int base) {
	if (n <= base) return x * y;
	int div = pow(10, n/2);
	int a = x / div;
	int b = x % div;
	int c = y / div;
	int d = y % div;
	int m1 = karatsuba(a, c, n / 2, base);
	int m2 = karatsuba(b, d, n / 2, base);
	int m3 = karatsuba((a - b), (d - c), n / 2, base);

	return m1 * pow(div, 2) + (m3 + m2 + m1) * div + m2;

	return 0;
}

int main() {
	int a = 12345;
	int b = 67891;
	cout << karatsuba(a,b,5,3) << endl;
	cout << a * b;
	return 0;
}