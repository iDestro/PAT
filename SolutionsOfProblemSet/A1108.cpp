#include <iostream>
#include <cctype>
#include <cstdio>
using namespace std;
bool check(string s) {
    int dot_cnt = 0, dot_idx = -1;
    for (int i = s[0] == '-' ? 1:0 ; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            if (s[i] == '.') {
                dot_cnt++;
                dot_idx = i;
                if (dot_cnt > 1) {
                    return false;
                }
            } else {
                return false;
            }
        } 
    }
    double num = stof(s);
    if (num > 1000 || num < -1000) {
        return false;
    } else if (dot_cnt == 1 && s.length()-dot_idx-1 > 2) {
        return false;
    }
    return true;
}

int main() {
    int N, cnt = 0;
    double ans = 0;
    string temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (check(temp)) {
            ans += stof(temp);
            cnt++;
        } else {
            printf("ERROR: %s is not a legal number\n", temp.c_str());
        }
    }
    if (cnt == 0) {
        printf("The average of 0 numbers is Undefined");
    } else if (cnt == 1) {
        printf("The average of %d number is %0.2f", cnt, ans/cnt);
    } else {
        printf("The average of %d numbers is %0.2f", cnt, ans/cnt);
    }
    return 0;
}