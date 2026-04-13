#include <iostream>

// 找出數列中的最大值
int max(int array[], int size) {
    if (size == 0) {
        return 0;
    }

    int max_value = array[0]; 

    for (int i = 1; i < size; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }
    return max_value;
}

int main() {
    // 用Array定義一個數列
    int numbers[] = {12, 45, 7, 89, 32, 56};

    // 計算數列長度
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // 呼叫副程式
    int result = max(numbers, n);  // 說明陣列退化問題，為何不能在副程式中在計算

    std::cout << "數列中的最大值是: " << result << std::endl;

    return 0;
}
