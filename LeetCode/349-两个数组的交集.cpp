using namespace std;
#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
    public:
    vector<int> intersection(vector<int>& vec1, vector<int>& vec2) {
        unordered_set<int> set1(vec1.begin(), vec1.end());
        unordered_set<int> res_set;
        for (vector<int>::iterator it=vec2.begin();it!=vec2.end();it++) {
            if(set1.find(*it) != set1.end()){res_set.insert(*it);} 
        }
        return vector<int>(res_set.begin(), res_set.end());
    }

};

void test() {
    Solution s;
    vector<int> vec1;
    vector<int> vec2;
    vec1.push_back(1);vec1.push_back(2);vec1.push_back(2);vec1.push_back(1);
    vec2.push_back(2);vec2.push_back(2);
    vector<int> res = s.intersection(vec1, vec2);
    for (vector<int>::iterator it = res.begin(); it != res.end();it++) {cout << *it << endl;}
}

int main(){
    test();
    system("pause");
    return 0;
}