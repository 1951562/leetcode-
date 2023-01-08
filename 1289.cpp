//给你一个nxn整数矩阵arr，请你返回非零偏移下降路径数字和的最小值。
//非零偏移下降路径 定义为：从arr数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。
//主要思路：dp，dp[i][j]表示第i行选择j情况下的最优解，然后化成两层的dp数组。

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int dp[2][200];
        int minpos=-1;
        int minvalue=100;
        int len=grid.size();

        for (int i=0;i<len;i++){
            dp[0][i]=grid[0][i];
            if (dp[0][i]<minvalue){
                minvalue=dp[0][i];
                minpos=i;
            }
        }

        for (int i=1;i<len;i++){
            if (i%2==0){
                for (int j=0;j<len;j++){
                    if (j!=minpos)
                        dp[0][j]=minvalue+grid[i][j];
                    else{
                        int tmp=100*i;
                        for (int k=0;k<len;k++){
                            if (k==j)
                                continue;
                            if (dp[1][k]<tmp)
                                tmp=dp[1][k];
                        }
                        dp[0][j]=tmp+grid[i][j];
                    }
                }
                minpos=-1;
                minvalue=100*(i+1);
                for (int j=0;j<len;j++){
                    if (dp[0][j]<minvalue){
                        minvalue=dp[0][j];
                        minpos=j;
                    }
                }
            }
            else{
                for (int j=0;j<len;j++){
                    if (j!=minpos)
                        dp[1][j]=minvalue+grid[i][j];
                    else{
                        int tmp=100*i;
                        for (int k=0;k<len;k++){
                            if (k==j)
                                continue;
                            if (dp[0][k]<tmp)
                                tmp=dp[0][k];
                        }
                        dp[1][j]=tmp+grid[i][j];
                    }
                }
                minpos=-1;
                minvalue=100*(i+1);
                for (int j=0;j<len;j++){
                    if (dp[1][j]<minvalue){
                        minvalue=dp[1][j];
                        minpos=j;
                    }
                }
            }
        }
        return minvalue;
    }
};
