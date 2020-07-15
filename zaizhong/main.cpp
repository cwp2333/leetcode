#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * num:1
 * author:Mr.Cai
 * */
int getMax(vector<int>& weights)
{
    int maxV = 0;
    for(auto a:weights)
    {
        maxV = max(maxV,a);
    }
    return maxV;

}
int getSum(vector<int>& weights)
{
    int sum = 0;
    for(auto w:weights)
    {
        sum += w;
    }
    return sum;
}
bool Canarrive(vector<int>& weights, int D,int ship)
{
    int i = 0;
    for(int day = 0;day<D;day++)
    {
        int maxShip = ship;
        while((maxShip -= weights[i])>=0) {
//            cout<<ship<<" "<<weights[i]<<endl;
            i++;
            if (i == weights.size())
                return true;
        }
    }
    return false;
}
int shipWithinDays(vector<int>& weights, int D) {
    int left = getMax(weights);
    int right = getSum(weights) + 1;
    while(left<right)
    {
        int mid = left + ((right-left)>>1);
        if(Canarrive(weights,D,mid))
        {
            right = mid;
        }else
            left = mid+1;
    }
    return left;

}
int main() {
//    std::cout << "Hello, World!" << std::endl;
    vector<int> weight = {3,2,2,4,1,4};
    int D = 3;
    cout<<shipWithinDays(weight,D)<<endl;
    if(shipWithinDays(weight,D)==6)
    {
        cout<<true<<endl;
    }else cout<<false<<endl;
    return 0;
}
