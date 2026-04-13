#include <iostream>
#include <vector>
using namespace std;

int max(vector<int>& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    int max_value = numbers[0]; 

    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] > max_value) {
            max_value = numbers[i];
        }
    }
    return max_value;
}

int main() {
    std::vector<int> numbers = {12, 45, 7, 89, 32, 56};

    int result = max(numbers);

    cout << "數列中的最大值是: " << result << endl;

    return 0;
}
