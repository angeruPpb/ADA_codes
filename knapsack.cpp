#include <iostream>
#include <vector>
using namespace std;

vector<float> mochila(float capacity, vector<float>& p, vector<float>& b) {
    vector<float> solution(p.size(), 0);
    vector<float> ratios(p.size());
    for (int i = 0; i < p.size(); i++)
        ratios[i] = b[i] / p[i];
    while (capacity > 0) {
        int max_index = max_element(ratios.begin(), ratios.end()) - ratios.begin();
        if (p[max_index] <= capacity) {
            solution[max_index] = 1;
            capacity -= p[max_index];
        }
        else {
            solution[max_index] = capacity / p[max_index];
            capacity = 0;
        }
        ratios[max_index] = 0;
    }
    return solution;
}

int main() {
    vector<float> p = { 10, 3, 3, 4 };
    vector<float> b = { 10, 9, 9, 9 };
    float max_peso = 10;
    vector<float> solucion = mochila(max_peso, p, b);
    cout << "The solution is: " << endl;
    for (int i = 0; i < solucion.size(); i++)
        cout << solucion[i] << " of " << p[i] << endl;

    return 0;
}