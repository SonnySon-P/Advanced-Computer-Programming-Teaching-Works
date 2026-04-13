#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& numbers, int target) {
    int n = numbers.size();

    for (int i = 0; i < n; i++) {
        if (numbers[i] == target) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    vector<int> numbers = {12, 45, 7, 89, 32, 56};

    int target = 89;

    int index = search(numbers, target);

    if (index != -1) {
        cout << "數字 " << target << " 在索引 " << index << " 的位置" << endl;
    } else {
        cout << "數列中沒有這個數字" << endl;
    }

    return 0;
}