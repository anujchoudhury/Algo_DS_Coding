// Pretty Easy DP question.
// Use value for num/2, and add 1 if its odd, or 0 if its even
// Or you could use the normal way to solve it - for each integer - pretty boring

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> a1(num+1,0);
        if(num==0)
        {
            return a1;
        }
        else if(num==1)
        {
            a1[1]=1;
            return a1;
        }
        a1[1]=1;
        for(int i=2;i<=num;i++)
        {
            if(i%2==0)
            {
                a1[i]=a1[i/2];
            }
            else
            {
                a1[i]=a1[i/2]+1;
            }
        }
        return a1;
    }
};