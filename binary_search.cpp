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

int binary_search(vector<int>& numbers, int target) {
    bubble_sort(numbers);

    int left = 0;
    int right = numbers.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (numbers[middle] == target) {
            return middle;
        }
        
        if (numbers[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> numbers = {12, 45, 7, 89, 32, 56};

    int target = 32;

    int index = binary_search(numbers, target);

    if (index != -1) {
        cout << "在排序後的數列中，數字 " << target << " 在索引 " << index << " 的位置" << endl;
    } else {
        cout << "數列中沒有這個數字" << endl;
    }

    return 0;
}