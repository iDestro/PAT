#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2, s3, s4;
    string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
    cin >> s1 >> s2 >> s3 >> s4;
    int i = 0, k = 0;
    char A[3];
    while (i < s1.length() && i < s2.length()) {
        if (s1[i] == s2[i]) {
            if (k == 0) {
                if (s1[i] >= 'A' && s1[i] <= 'G') {
                    A[k++] = s1[i];
                }
            }else if (k == 1) {
                if ((s1[i] >= 'A' && s1[i] <= 'N') || isdigit(s1[i])) {
                    A[k++] = s1[i];
                    break;
                }
            }
        }
        i++;
    }
    i = 0;
    while (i < s3.length() && i < s4.length()) {
        if (s3[i] == s4[i] && isalpha(s3[i])) {
            A[k] = i;
        }
        i++;
    }
    int m = isdigit(A[1]) ? A[1] - '0' : A[1] - 'A' + 10;
    cout << week[A[0]-'A'];
    printf("%02d:%02d", m, A[2]);
    return 0;
}