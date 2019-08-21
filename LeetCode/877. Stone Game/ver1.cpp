class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // Trivial answer
        // return 1;
        
        //The question becomes very good when there are odd number of piles as well
        // with the restriction of even only, the method i was using was unoptimal
        //see MinMax algorithm, AI.
        // for even only scheme, for 1 2 n-1 n,
        // there arise 4 cases :-
        // 1 and 2, 
        // 1 and n
        // n and 1,
        // n and n-1,
        // choices, out of which each will choose the optimal.
        // This solution is more elegant and obvious.
        // see https://www.youtube.com/watch?v=WxpIHvsu1RI for better explanation
        // see Solution for (direct) return bool True 

        vector<vector<int> > maxscore(piles.size(),vector<int>(piles.size(),0));
        vector<vector<int> > minscore(piles.size(),vector<int>(piles.size(),0));
        
        for(int j=0;j<piles.size();j++)
        {
            for(int i=0;i+j<piles.size();i++)
            {
                if(j==0)
                {
                    maxscore[i][i+j] = piles[i];
                    minscore[i][i+j] = 0;
                }
                else if(j==1)
                {
                    maxscore[i][i+j] = max(piles[i],piles[i+1]);
                    minscore[i][i+j] = min(piles[i],piles[i+1]);
                }
                else
                {
                    if(minscore[i+1][j-1]+piles[i]>piles[i+j]+minscore[i][i+j-1])
                    {
                        maxscore[i][i+j] = minscore[i+1][j-1]+piles[i];
                        minscore[i][i+j] = piles[i+j]+minscore[i][i+j-1];
                    }
                    else
                    {
                        maxscore[i][i+j] = piles[i+j]+minscore[i][i+j-1];
                        minscore[i][i+j] = minscore[i+1][j-1]+piles[i];
                    }
                }
            }
        }
        return (maxscore[0][piles.size()-1]-minscore[0][piles.size()-1]>0);
    }
};