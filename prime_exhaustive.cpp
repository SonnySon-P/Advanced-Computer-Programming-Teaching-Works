#include <iostream>
using namespace std;

bool prime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int number = 11;

    if (prime(number)) {
        cout << number << " 是質數" << endl;
    } else {
        cout << number << " 不是質數" << endl;
    }

    return 0;
}