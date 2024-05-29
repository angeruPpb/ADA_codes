#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> planificacion(vector<float>& b, vector<float>& d) {
    int n = b.size();
    vector<int> solucion;
    int aux = 1;
    vector<float> tmp = d;
    int mini = *min_element(tmp.begin(), tmp.end());
    vector<float> ratios(n);
    for (int i = 0; i < n; i++)
        ratios[i] = b[i] / d[i];
    while (true) {
        vector<float> kek = ratios;
        int max_index;
        while (true) {
            max_index = max_element(ratios.begin(), ratios.end()) - ratios.begin();
            if (d[max_index] > mini)
                kek[max_index] = 0;
            else break;
        }
        solucion.push_back(max_index + 1);
        ratios[max_index] = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] == aux) {
                ratios[i] = 0;
                tmp[i] = n + 1;
            }
        }
        mini = *min_element(tmp.begin(), tmp.end());
        aux++;
        if (mini == n + 1) break;
    }
    return solucion;
}

int main() {
    vector<float> b = { 20, 15, 10, 7, 5, 3 };
    vector<float> d = { 3,   1,   1, 3, 1, 3 };
    vector<int> solucion = planificacion(b, d);
    cout << "The solution is: " << endl;
    for (int i = 0; i < solucion.size(); i++)
        cout << solucion[i] << " ";
    cout << endl;

    return 0;
}