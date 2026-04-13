#include <iostream>
#include <vector>
#include <cmath>   // 為了使用sqrt()函式
using namespace std;

double average(vector<int>& numbers) {
    int n = numbers.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }

    return sum / n;
}

double standard_deviation(vector<int>& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    double mean = average(numbers);
    int n = numbers.size();
    
    double sum_of_squares = 0;
    for (int i = 0; i < n; i++) {
        double difference = numbers[i] - mean;
        sum_of_squares += difference * difference;
    }

    double variance = sum_of_squares / n;

    return sqrt(variance);
}

int main() {
    vector<int> numbers = {12, 45, 7, 89, 32, 56};

    double result = standard_deviation(numbers); 

    cout << "數列的標準差是: " << result << endl;

    return 0;
}