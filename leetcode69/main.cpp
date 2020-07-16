/*
 * author:Mr.Cai
 * num:1
 * */

#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return x;
        int min = 0;
        int max = x;
        while(max - min>1)
        {
            int m = min+ ((max-min)>>1);
            if(x/m<m)
            {
                max = m;
            }else{
                min = m;
            }
        }
        return min;
    }
};
int main() {
    Solution s;
    int x = 8;
    cout<<s.mySqrt(x)<<endl;
    return 0;
}
