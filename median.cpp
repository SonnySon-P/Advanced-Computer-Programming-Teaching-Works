#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& numbers) {
    int n = numbers.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

double median(vector<int>& numbers) {
    bubble_sort(numbers);

    int n = numbers.size();

    if (n % 2 != 0) {
        return numbers[n / 2];
    } else {
        int middle1 = numbers[n / 2 - 1];
        int middle2 = numbers[n / 2];
        return (middle1 + middle2) / 2.0;
    }
}

int main() {
    vector<int> numbers = {12, 45, 7, 89, 32, 56};

    double result = median(numbers);

    cout << "數列中位數是: " << result << endl;

    return 0;
}