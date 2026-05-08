#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];

        if (i != numbers.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

void bucket_sort(vector<int>& numbers) {
    if (numbers.empty()) {
        return;
    }

    int max_value = numbers[0];
    for (int number : numbers) {
        if (number > max_value) {
            max_value = number;
        }
    }

    // 建立桶子
    vector<int> bucket(max_value + 1, 0);

    // 將元素放入桶中
    for (int number : numbers) {
        bucket[number]++;
    }

    // 依序取出
    int index = 0;
    for (int i = 0; i < bucket.size(); i++) {
        while (bucket[i] > 0) {
            numbers[index] = i;
            index++;
            bucket[i]--;
        }
    }
}

int main() {
    vector<int> numbers = {12, 45, 7, 89, 32, 56};

    bucket_sort(numbers);

    cout << "排序後: ";
    print_vector(numbers);

    return 0;
}