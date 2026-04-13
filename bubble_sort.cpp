#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];  // 印數字

        if (i == numbers.size() - 1) {
            cout << "";  // 如果是最後一個，後面什麼都不加
        } else {
            cout << ", ";  // 如果不是最後一個，後面加逗號
        }
    }
    cout << endl;
}

void bubble_sort(vector<int>& numbers) {  // &代表同一個東西的另一個名字，已經改到原本的東西了，不需要再回傳
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

int main() {
    vector<int> numbers = {12, 45, 7, 89, 32, 56};

    bubble_sort(numbers);

    cout << "排序後: ";
    print_vector(numbers);

    return 0;
}