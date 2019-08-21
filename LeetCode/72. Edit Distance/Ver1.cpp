// 72. Edit Distance
// Very common question in DP, simple enough once understood.

class Solution {
public:
    int min3(int x,int y,int z)
    {
        return min(min(x,y),z);
    }
    int minDistance(string word1, string word2) {
        
        int len1=word1.size()+1;
        int len2=word2.size()+1;
        
        vector<vector<int> > dp(len1,vector<int>(len2,0));
        
        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                if(i==0)
                {
                    dp[i][j] = j;
                }
                else if(j==0)
                {
                    dp[i][j] = i;
                }
                else if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=min3(1+dp[i-1][j-1],1+dp[i-1][j],1+dp[i][j-1]);
                }
            }
        }
        return dp[len1-1][len2-1];
    }
};