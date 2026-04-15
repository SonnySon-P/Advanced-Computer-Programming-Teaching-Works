#include <iostream>
#include <string>
using namespace std;

void search(string text, string pattern) {
    int m = text.length();
    int n = pattern.length();
    bool found = false;

    for (int i = 0; i <= m - n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        
        if (j == n) {
            cout << "在索引 " << i << " ，找到匹配" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "未在字串中找到匹配" << endl;
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    search(text, pattern);

    return 0;
}