#include <iostream>
#include <algorithm> // Para std::sort
using namespace std;

typedef int TElem;

void particion(TElem v[], int a, int b, TElem pivote, int& p, int& q) {
    int k = a;
    q = b;
        while (k <= q) {
        if (v[k] == pivote) {
        k++;
        } else if (v[k] < pivote) {
        swap(v[p], v[k]);
        p++;
        k++;
        } else {
        swap(v[q], v[k]);
        q--;
        }
    }
}

TElem mediana(TElem v[], int a, int b, int k) {
    if (b - a + 1 <= 12) {
        sort(&v[a], &v[b] + 1);
        return v[k];
    }

    int s = (b - a + 1) / 5;
    for (int l = 1; l <= s; ++l) {
        sort(&v[a] + 5 * (l - 1), &v[a] + 5 * l);
    }

    int pm = a + 5 * (s - 1) / 2;
    TElem mm = v[a + s - 1];
    swap(v[a + s - 1], v[a]); // Intercambiar la mediana con el primer elemento

    int p, q;
    particion(v, a, b, mm, p, q);

    if (k >= p && k <= q) {
        return mm;
    } else if (k < p) {
        return mediana(v, a, p - 1, k);
    } else {
        return mediana(v, q + 1, b, k);
    }
}

int main() {
    TElem v[] = { 1, 6, 3, 11, 14, 2, 7, 8, 9, 4, 5, 10, 12, 13, 15 };
    int k = 5; // Posicion de la mediana
    cout << mediana(v, 0, 14, k) << endl;
    return 0;
}