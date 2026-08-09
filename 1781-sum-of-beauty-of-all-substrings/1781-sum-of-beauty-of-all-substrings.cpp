//my brute force solution
class Solution {
public:
    // int calBeauty(string s, int left, int right)
    int beautySum(string s) {
        int n = s.size();
        int maxFreq = 0;
        int beauty = 0;
        for(int i=0; i<n; i++)
        {
            vector<int> hashArr(26, 0);  // since only lowercase english letters
            maxFreq = 0;
            for(int j=i; j<n; j++)
            {
                hashArr[s[j]-'a']++;
                maxFreq = max(maxFreq, hashArr[s[j]-'a']);
                int minFreq=n+1;
                for(int k=0; k<26; k++)
                {
                    if(hashArr[k] > 0 )    // the chars that not come  yet so they have 0 as value need to skip them
                        minFreq = min(minFreq, hashArr[k]);
                }
            beauty += maxFreq - minFreq;
            }
        }
        return beauty;
    }
};