/*
 * author:Mr.Cai
 * num:1
 * 要好好做一下
 * */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct Data{
    string root;
    double val;
    Data(string s="",double v = 0):root(s),val(v){};
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,Data> mutiple;
        vector<double> res;
        int q_num = queries.size();
        int e_num = equations.size();
        int v_num = values.size();
        for(int i = 0;i<e_num;i++)
        {
            string x = equations[i][0],y = equations[i][1];
            if(mutiple.find(x) == mutiple.end()&&mutiple.find(y)==mutiple.end())
            {
                mutiple[x] = Data(y,values[i]);
                mutiple[y] = Data(y,1.0);
            }
            else if(mutiple.find(x)!=mutiple.end()&& mutiple.find(y)!=mutiple.end())
            {
                mutiple[mutiple[x].root] = Data(y,values[i]/mutiple[x].val);
                mutiple[x] = Data(y,values[i]);
            }
            else if(mutiple.find(y)!=mutiple.end())
            {
                mutiple[x] = Data(mutiple[y].root,mutiple[y].val*values[i]);
            }
            else if(mutiple.find(x)!=mutiple.end())
            {
                mutiple[y] = Data(mutiple[x].root,mutiple[x].val/values[i]);
            }
        }
        for(auto val:mutiple)
        {
            string ID = val.first;
            while(mutiple[ID].root!=mutiple[mutiple[ID].root].root)
            {
                string root_ID = mutiple[mutiple[ID].root].root;
                double root_mults = mutiple[mutiple[ID].root].val;
                mutiple[ID] = Data(root_ID,mutiple[ID].val*root_mults);

            }
        }
        for(auto e:queries)
        {
            string x= e[0],y = e[1];
            if(mutiple.find(x)!=mutiple.end()&&mutiple.find(y)!=mutiple.end()&&mutiple[x].root==mutiple[y].root)
            {
                res.push_back(mutiple[x].val/mutiple[y].val);
            }else{
                res.push_back(-1.0);
            }
        }
        return res;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
