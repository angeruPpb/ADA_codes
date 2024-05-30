#include<iostream>
#include<vector>

using namespace std;

struct arista {
    int ini;
    int fin;
    int peso;
    arista(int i, int f, int p) : ini(i), fin(f), peso(p) {}
};

int ciclo(vector<arista> arist1, int ini, int fin) {
    int aux = 0;
    if (ini == fin) 
        return 1;
    for (int i = 0; i < arist1.size(); i++) {
        if (arist1[i].ini == ini) {
            vector<arista> arist2;
            int ini_2;
            if (arist1[i].ini == ini) 
                ini_2 = arist1[i].fin;
            else 
                ini_2 = arist1[i].ini;
            arist2.assign(arist1.begin(), arist1.end());
            arist2.erase(arist2.begin() + i);
            aux = max(aux, ciclo(arist2, ini_2, fin));
        }
    }
    return aux;
}

bool ver(vector<int> vert) {
    for (int i = 0; i < vert.size(); i++) 
        if (vert[i] == 0) 
            return 0;
    return 1;
}

int kruskal(vector<arista>& aristas, vector<int>& vertices, vector<arista>& solucion) {
    int piv = aristas[0].peso;
    int ini = aristas[0].ini;
    int fin = aristas[0].fin;
    int j = 0;
    for (int i = 1; i < aristas.size(); i++) {
        if (aristas[i].peso < piv) {
            piv = aristas[i].peso;
            ini = aristas[i].ini;
            fin = aristas[i].fin;
            j = i;
        }
    }
    bool num = vertices[ini - 1] == 1 && vertices[fin - 1] == 1 && ciclo(solucion, ini, fin);
    if (!num) 
        solucion.push_back(arista{ ini,fin,piv });
    aristas.erase(aristas.begin() + j);
    vertices[ini - 1] = 1;
    vertices[fin - 1] = 1;
    return !ver(vertices);
}

int main() {
    vector<arista> aristas = {
        arista{1,2,4}, arista{1,8,8},
        arista{2,3,8}, arista{2,8,11},
        arista{3,4,7}, arista{3,6,4},
        arista{4,5,9}, arista{4,6,14},
        arista{5,6,10}, arista{6,7,2},
        arista{7,8,1}, arista{7,9,6},
        arista{8,9,7}, arista{3,9,2} };
    vector<int> vertices(9,0);
    vector<arista> solucion;
    while (kruskal(aristas, vertices, solucion));
    cout << "Ini\t" << "Fin\t" << "Peso\t" << endl;
    for (arista i : solucion) 
        cout << i.ini << "\t" << i.fin << "\t" << i.peso << endl;

    return 0;
}