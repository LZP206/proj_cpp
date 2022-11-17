using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>


// ¹þÏ£½â·¨
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> umap;
        int counter = 0;
        for (int a : A) {
            for (int b : B) {
                if (umap.find(a+b) != umap.end()){umap[a+b]++;}
                umap.insert(pair<int,int>(a+b,1));
            }
        }
        for (int c : C) {
            for (int d : D) {
                if (umap.find(0-c-d) != umap.end()){counter += umap[0-c-d];}
            }
        }
        return counter;
    }

};






int main() {
    unordered_map<int,int> test_map;
    // cout << test_map.size() << endl;
    test_map[2]++;
    cout << test_map[2] << endl;


    system("pause");
    return 0;
}