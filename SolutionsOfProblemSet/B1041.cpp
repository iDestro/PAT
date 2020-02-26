#include <iostream>
#include <string>
using namespace std;
struct Stu{
    string id;
    int num;
}S[1001];
int main() {
    int M, N, test_num, true_num;
    string id;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> id >> test_num >> true_num;
        S[test_num].id = id;
        S[test_num].num = true_num;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> test_num;
        cout << S[test_num].id << " " << S[test_num].num << endl;
    }
    return 0;
}