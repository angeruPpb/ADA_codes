#include <iostream>
#include <vector>
using namespace std;

vector<int> dynamic_knapsack(vector<int> p, vector<int> b, int capacity) {
    int n = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (p[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p[i - 1]] + b[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for (auto row : dp) {
        for (auto cell : row)
            cout << cell << "\t";
        cout << endl;
    }

    vector<int> solution(n, 0);
    int i = n, j = capacity;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            solution[i - 1] = 1;
            j -= p[i - 1];
        }
        i--;
    }
    return solution;
}

int main() {
    vector<int> p = { 5, 3, 4, 1 };
    vector<int> b = { 1, 2, 1, 1 };
    int max_peso = 10;
    vector<int> solucion = dynamic_knapsack(p, b, max_peso);
    cout << "The solution is: " << endl;
    for (int i = 0; i < solucion.size(); i++)
        cout << solucion[i] << " of " << p[i] << endl;

    return 0;
}

