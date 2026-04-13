#include <iostream>
using namespace std;

double degree_to_radian(double degree) {
    const double PI = 3.14159265358979323846;
    double radian = degree * (PI / 180.0);
    return radian;
}

int main() {
    double degree = 90.0;

    double result = degree_to_radian(degree);

    cout << degree << " 度轉換為弧度是 " << result << endl;

    return 0;
}