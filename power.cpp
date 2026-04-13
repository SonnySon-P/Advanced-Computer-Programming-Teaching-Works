#include <iostream>
using namespace std;

int absolute(int number) {
    if (number < 0) {
        number = number * -1;
    }

    return number;
}

double power(double base, int exponential) {
    double result = 1.0;

    int absolute_exponential = absolute(exponential);

    for (int i = 0; i < absolute_exponential; i++) {
        result *= base;
    }

    if (exponential < 0) {
        return 1.0 / result;  // 如果原始指數是負數，結果要取倒數
    }

    return result;
}

int main() {
    double base = 2.5;
    int exponential = 4;

    double result = power(base, exponential);

    cout << base << " 的 " << exponential << " 次方是: " << result << endl;

    return 0;
}