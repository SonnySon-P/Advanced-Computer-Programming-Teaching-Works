#include <iostream>
#include <string>
using namespace std;

string multiply(string number_1, string number_2) {
    int m = number_1.size();
    int n = number_2.size();
    
    int result[1000] = {0};  // 儲存結果（假設最多1000位）

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (number_1[i] - '0') * (number_2[j] - '0');  // 文字轉整數在相乘
            int sum = result[i + j + 1] + mul;

            result[i + j + 1] = sum % 10;  // 個位
            result[i + j] += sum / 10;  // 進位
        }
    }

    string answer = "";
    for (int i = 0; i < m + n; i++) {
        if (!(answer.empty() && result[i] == 0)) {
            answer += (result[i] + '0');  // 整數轉文字在字串相加
        }
    }

    if (answer.empty()) {
        return "0";
    } else {
        return answer;
    }
}

int main() {
    string a = "123456789";
    string b = "987654321";

    string result = multiply(a, b);

    cout << "大數相乘結果: " << result << endl;

    return 0;
}