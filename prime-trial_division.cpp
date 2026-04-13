#include <iostream>
using namespace std;

bool prime(int n) {
    if (n <= 1) {
        return false;
    }
    
    if (n == 2) {
        return true;
    }
    
    if (n % 2 == 0) {
        return false;
    }

    for (int i = 3; i * i <= n; i += 2) {  // i * i <= n等同於i <= sqrt(n)
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