#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int a = 0;
    int b = 0;
    cin >> a >> b;

    int exchange = a;
    a = b;
    b = exchange;

    cout << a << " " << b << endl;
    return 0;
}