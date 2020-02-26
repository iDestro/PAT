#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string s1, s2, ans;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
        if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos)
            ans += toupper(s1[i]);
    cout << ans;
    return 0;
}

// #include <iostream>
// #include <ctype.h>
// using namespace std;
// int main() {
//     string s1, s2;
//     cin >> s1 >> s2;
//     int hashtable[128] = {0};
//     for (int i = 0; i < s2.length(); i++) {
//         int j = toupper(s2[i]);
//         hashtable[j] = 1;
//     }
//     for (int i = 0; i < s1.size(); i++) {
//         if(hashtable[toupper(s1[i])] != 1) {
//             printf("%c", toupper(s1[i]));
//             hashtable[toupper(s1[i])] = 1;
//         }
//     }
//     return 0;
// }