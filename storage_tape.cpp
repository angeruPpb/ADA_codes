#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void storage_tape(vector<int> tape) {
    vector<pair<int,int>> data;
    for (int i = 0; i < tape.size(); i++)
        data.push_back({tape[i], i});

    sort(data.begin(), data.end());
    for (int i = 0; i < data.size(); i++)
        cout << data[i].first << " " << data[i].second + 1 << endl;
}

int main() {
    vector<int> tape = { 5, 10, 3 };
    storage_tape(tape);
    return 0;
}