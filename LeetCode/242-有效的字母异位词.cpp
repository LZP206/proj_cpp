using namespace std;
#include<iostream>
#include<string>


class Solution {
    public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            record[s.at(i)-'a'] += 1;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t.at(i)-'a'] -= 1;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};

void test() {
    // 测试的string类型的size函数
    // string s = "hello word";
    // cout << s.size() << endl;
    string s = "anagram";
    string t = "nagaram";
    Solution solution;
    bool res = solution.isAnagram(s,t);
    cout << res << endl;
}



int main() {
    test();
    system("pause");
    return 0;
}