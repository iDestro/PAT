#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> *arr = new vector<int>[5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i].push_back(j);
        }
    }
    for (int i = 0; i < 5; i++) {
        int size = arr[i].size();
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}