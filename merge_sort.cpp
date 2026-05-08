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

void merge(vector<int>& numbers, int left, int mid, int right) {
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    // 比較左右兩邊，較小的放進temp
    while (i <= mid && j <= right) {
        if (numbers[i] < numbers[j]) {
            temp.push_back(numbers[i]);
            i++;
        } else {
            temp.push_back(numbers[j]);
            j++;
        }
    }

    // 把剩下的補上
    while (i <= mid) {
        temp.push_back(numbers[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(numbers[j]);
        j++;
    }

    // 複製回原本陣列
    for (int k = 0; k < temp.size(); k++) {
        numbers[left + k] = temp[k];
    }
}

void merge_sort(vector<int>& numbers, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    // 左右各自排序
    merge_sort(numbers, left, mid);
    merge_sort(numbers, mid + 1, right);

    // 合併
    merge(numbers, left, mid, right);
}

int main() {
    vector<int> numbers = {12, 45, 7, 89, 32, 56};

    merge_sort(numbers, 0, numbers.size() - 1);

    cout << "排序後: ";
    print_vector(numbers);

    return 0;
}