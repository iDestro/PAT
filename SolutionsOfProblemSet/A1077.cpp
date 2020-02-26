#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
    int N;
    string s, res, temp;
    cin >> N;
    getchar();
    getline(cin, temp);
    N = N-1;
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        res = "";
        int j = temp.length()-1, k = s.length()-1;
        while (j >= 0 && k >= 0) {
            if (temp[j] == s[k]) {
                res = s[k] + res;
            } else {
                break;
            }
            j--, k--;
        }
        temp = res;
    }
    if (temp.size() != 0) {
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i];
        }
    } else {
        cout << "nai";
    }
    
    return 0;
}