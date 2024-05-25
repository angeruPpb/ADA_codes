#include <iostream>
#include <vector>
using namespace std;

bool return_change(int p, vector<int>& c, vector<int>& x) {
    int act = 0;
    int j = c.size() - 1;
    while (act != p) {
        while (c[j] > (p - act) && j > 0)
        j--;
        if (j == 0) return false;
        x[j] = (p - act) / c[j];
        act += c[j] * x[j];
    }
    return true;
}
int main() {
    //vector<int> monedas = { 1, 2, 5, 10, 20, 50, 100, 200}; // Todas con solucion
    vector<int> monedas = { 90, 100, 200 };
    vector<int> solucion(monedas.size(), 0);
    int p = 180;
    if (return_change(p, monedas, solucion)) {
        cout << "The change is: " << endl;
        for (int i = 0; i < solucion.size(); i++)
            if (solucion[i] != 0)
                cout << solucion[i] << " -> " << monedas[i] << endl;
    }
    else cout << "No Solution" << endl;
    
    return 0;
}