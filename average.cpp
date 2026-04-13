#include <iostream>
#include <vector>
using namespace std;

double average(vector<int>& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    int n = numbers.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }

    return sum / n;
}

int main() {
    vector<int> numbers = {12, 45, 7, 89, 32, 56};

    double result = average(numbers); 

    cout << "數列的平均值是: " << result << endl;

    return 0;
}