#include <iostream>
#include <string>
using namespace std;
int P[100001] = {0};
int T[100001] = {0};
int main() {
    string s;
    cin >> s; 
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'P') {
            P[i] = (i-1 >= 0 ? P[i-1] : 0) + 1;
        } else {
            P[i] = P[i-1];
        }
    }
    int rightTnums = 0;
    for (int i = s.length()-1 ; i >= 0; i--) {
        if (s[i] == 'A') {
            T[i] = T[i+1];
            ans = (ans + P[i]*rightTnums)%1000000007;
        } else if (s[i] == 'T'){
            rightTnums++;
        }
    }
    cout << ans << endl;
    return 0;
}