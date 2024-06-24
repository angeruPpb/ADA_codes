#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct activity {
    char name;
    int start, end;
    activity(char n, int s, int e) : start(s), end(e), name(n) {}
};

vector<activity> activities_sort(vector<activity> activities) {
    sort(activities.begin(), activities.end(), [](activity a, activity b) {
        return a.end < b.end;
    });
    vector<activity> result;
    result.push_back(activities[0]);
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= result.back().end)
            result.push_back(activities[i]);
    }
    return result;
}

int main() {
    vector<activity> activities = {
        activity('A', 0, 6),
        activity('B', 1, 4),
        activity('C', 3, 5),
        activity('D', 3, 8),
        activity('E', 4, 7),
        activity('F', 5, 9),
        activity('G', 6, 10),
        activity('H', 8, 11)
    };
    vector<activity> result = activities_sort(activities);
    for (int i = 0; i < result.size(); i++)
        cout << result[i].name << " " << result[i].start << " " << result[i].end << endl;
    return 0;
}