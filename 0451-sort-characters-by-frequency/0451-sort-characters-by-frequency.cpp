class Solution {
public:
    string frequencySort(string s) {
        // vector<int> hashArr(26, 0);
        vector<pair<int, char>> hashArr(123, {0, 0});
        string ans="";
        for(char ch : s)
        {
            hashArr[ch] = {++hashArr[ch].first, ch};
        }
        sort(hashArr.begin(), hashArr.end());
        for(int i = 122; i>=0; i--)
        {
            if(hashArr[i].first !=0)
                for(int j=0; j<hashArr[i].first; j++)
                    ans += hashArr[i].second;
        }
        return ans;
    }
};