#include <iostream>
#include <set>
#include <vector>
#define NUMS 8

using namespace std;

class Solution
{
public:
    bool ifInValid(int row,int col,vector<string> &map,int n)
    {
        //检测列上是否有相同的
        for (int i = 0; i < row; i++)
        {
            if (map[i][col] == 'Q')
                return false;
        }

        //检测左边斜着是否有相同的
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i,++j)
        {
            if (map[i][j] == 'Q')
                return false;
        }
        
        //检测右边斜着是否有相同的
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i,--j)
        {
            if (map[i][j] == 'Q')
                return false;
        }
        
        return true;
    }
    void backTrack(const int n,int row,vector<string> &map)
    {
        if (n == row)
        {
            res.push_back(map);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (ifInValid(row,col,map,n))
            {
                //放置皇后
                map[row][col] = 'Q';
                //回溯
                backTrack(n,row + 1,map);
                //取消放置
                map[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solutionN(const int n)
    {
        vector<string> map(n,string(n,'.'));
        backTrack(n,0,map);
        return res;
    }
private:
    vector<vector<string>> res;
};

int main()
{
    Solution s;
    vector<vector<string>> ans = s.solutionN(8);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            for (int k = 0; k < ans[i][j][k]; k++)
            {
                cout << ans[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}