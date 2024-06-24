#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Persona {
    int index;
    int pesos[3];
    Persona(int i, int p1, int p2, int p3) {
        index = i;
        pesos[0] = p1;
        pesos[1] = p2;
        pesos[2] = p3;
    }
};

int solution(vector<int> &soa, vector<Persona> &personas, int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += personas[i].pesos[soa[i]-1];
    }
    return suma;
}

void generar(vector<int> &soa, vector<int> &solucion, vector<Persona> &personas, int n, int nivel, int &voa, int &boa) {
    if (nivel == n) {
        voa = solution(soa, personas, n);
        if (voa > boa) {
            boa = voa;
            solucion = soa;
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (find(soa.begin(), soa.end(), i) == soa.end()) {
                soa.push_back(i);
                generar(soa, solucion, personas, n, nivel + 1, voa, boa);
                soa.pop_back();
            }
        }
    }
}

vector<int> permutacional(vector<Persona> personas, int n) {
    int nivel = 0;
    int voa = -1;
    vector<int> soa;
    vector<int> solucion;
    int boa = 0;

    generar(soa, solucion, personas, n, nivel, voa, boa);
    
    
    return solucion;
}


int main() {
    vector<Persona> personas = {
        Persona(1, 4, 9, 1),
        Persona(2, 7, 2, 3),
        Persona(3, 6, 3, 5)
    };
    int n = personas.size();

    vector<int> solucion = permutacional(personas, n);
    cout << "Solucion: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Persona: " << i+1 << " -> Tarea: " << solucion[i] << endl;
    }
    return 0;
}