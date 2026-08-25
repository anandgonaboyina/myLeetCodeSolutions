//131. Palindrome Partitioning
//not completed need to solve this problem
// ??????????????????????????????????????????????????????
class Solution {
public:
    void solve(string &s, vector<vector<string>> &ans, vector<string> &pt, int i)
    {
        if(i == s.size())
        {
            for(int k=0; k<pt.size(); k++)
            {            
                int l=0, r=pt[k].size();
                while(l<r)
                {
                    if(pt[l] != pt[r])
                        return;
                    l++; r--;
                }
            }
            ans.push_back(pt);
            return;
        }
        vt.push_back()
    }

    vector<vector<string>>partition(string s) {
        vector<vector<string>> ans;
        if(s.empty()) return ans;
        vector<string> pt;
        solve(s, ans, pt, 0);
        return ans;
    }
};