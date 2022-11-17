using namespace std;
#include <iostream>
#include <string>



// 暴力解法
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (int i = 0; i < magazine.length(); i++) {
            for (int j = 0; j < ransomNote.length(); j++) {
                // 在ransomNote中找到和magazine相同的字符
                if (magazine[i] == ransomNote[j]) {
                    ransomNote.erase(ransomNote.begin() + j); // ransomNote删除这个字符
                    break;
                }
            }
        }
        // 如果ransomNote为空，则说明magazine的字符可以组成ransomNote
        if (ransomNote.length() == 0) {return true;}
        return false;
    }
};



// 哈希法
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int array[26] = {0};
        for (int i = 0; i < magazine.size(); i++) {
            array[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            array[ransomNote[i] - 'a']--;
            if (array[ransomNote[i] - 'a'] < 0) {return false;}
        }
        return true;
    }
};
