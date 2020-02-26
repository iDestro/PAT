#include <iostream>
#include <map>
using namespace std;
int main() {
    map<string, bool> m;
    m["234"] = true;
    cout << m["234"];
}