#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];

        if (i == numbers.size() - 1) {
            cout << "";
        } else {
            cout << ", ";
        }
    }
    cout << endl;
}

void insertion_sort(vector<int>& numbers) {
    int n = numbers.size();

    for (int i = 1; i < n; i++) {
        int key = numbers[i];   // 當前要插入的元素

        int j = i - 1;
        while (0 <= j && numbers[j] > key) {  // 將比key大的元素往右移
            numbers[j + 1] = numbers[j];
            j--;
        }

        numbers[j + 1] = key;  // 插入到正確位置
    }
}

int main() {
    vector<int> numbers = {12, 45, 7, 89, 32, 56};

    int target = 32;

    insertion_sort(numbers);

    cout << "排序後: ";
    print_vector(numbers);

    return 0;
}