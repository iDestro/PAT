#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <map>
#include <cctype>
using namespace std;

struct Node {
    double num;
    char op;
    bool flag;
};

string str;
stack<Node> s;
queue<Node> q;

map<char, int> op;

void Change() {
    double num;
    Node temp;
    for (int i = 0; i < str.length();) {
        if(isdigit(str[i])) {
            temp.flag = true;
            temp.num = str[i++] - '0';
            while (i < str.length() && isdigit(str[i])) {
                temp.num = temp.num * 10 + str[i]-'0';
                i++;
            }
            q.push(temp);
        } else {
            temp.flag = false;
            while (!s.empty() && op[str[i]] <= op[s.top().op]) {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

double Cal() {
    // 从右往左依次读取字符
    double temp1, temp2;
    Node cur, temp;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur.flag == true) {
            s.push(cur);
        } else {
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            temp.flag = true;
            switch(cur.op) {
                case '+': temp.num = temp1+temp2;
                            break;
                case '-': temp.num = temp1-temp2;
                            break;
                case '*': temp.num = temp1*temp2;
                            break;
                case '/': temp.num = temp1/temp2;
                            break;
            }
            s.push(temp);
        }
        // cout << s.top().num << endl;
    }
    return s.top().num;
}

int main() {
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while (getline(cin, str), str != "0") {
        for (string::iterator it = str.end(); it != str.begin(); it--) {
            if (*it == ' ') str.erase(it);
        }
        while (!s.empty()) s.pop();
        Change();
        printf("%lf", Cal());
    }
    return 0;
}
