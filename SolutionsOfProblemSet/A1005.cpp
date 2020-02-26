/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-05-28 10:13:50
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-08 21:57:31
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
    string num, nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int sum = 0;
    stack<int> S;
    cin >> num;
    for (int i = 0; i < num.length(); i++) {
        sum += num[i] - '0';
    }
    if (sum == 0) {
        cout << "zero";
        return 0;
    }
    while (sum != 0) {
        S.push(sum % 10);
        sum /= 10;
    }
    while (!S.empty()) {
        cout << nums[S.top()];
        S.pop();
        if (!S.empty()) {
            cout << " ";
        }
    }
    return 0;
}