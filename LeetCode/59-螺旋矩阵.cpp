using namespace std;
#include <iostream>
#include <vector>

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0)); 
        int start_x = 0; int start_y = 0;
        int loop = n / 2;
        int i,j;
        int counter = 1;
        for(int idx_loop =1; idx_loop <= loop; idx_loop++) {
            i = start_x; j = start_y;
            for (j = start_y; j < n + start_y - 1; j++) {result[i][j] = counter++;}
            for (i = start_x; i < n + start_x - 1; i++) {result[i][j] = counter++;}
            for (; j > idx_loop - 1; j--) {result[i][j] = counter++;}
            for (; i > idx_loop - 1; i--) {result[i][j] = counter++;}
            start_x++; start_y++; n -= 2;
        }
        if (n != 0) {result[loop][loop] = counter;}
        return result;
    }
};

