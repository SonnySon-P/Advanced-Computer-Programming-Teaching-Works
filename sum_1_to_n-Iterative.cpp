#include <iostream>
using namespace std;

int sum(int n) {
    int result = 0;

    for (int i = 1; i <= n; i++) {
        result += i;
    }

    return result;
}

int main() {
    int result = sum(100);

    cout << "1到100的累加和是: " << result << endl;

    return 0;
}