//getting <40%% beats Sc is 1 as axialiary space for ans and Tc is 2^n    
    class Solution {
    public:

        void solve(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &vt, int target, int sum, int i)
        {
            if(i >= candidates.size() || sum>=target)
            {
                if(sum==target)
                    ans.push_back(vt);
                return;
            }
            vt.push_back(candidates[i]);
            solve(candidates, ans, vt, target, sum+candidates[i], i+1);
            vt.pop_back();
            int curr=i;
            while(i+1 < candidates.size() && candidates[curr]==candidates[i+1])
                i++;
            solve(candidates, ans, vt, target, sum, i+1);
        }

        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> vt;
            sort(candidates.begin(), candidates.end());
            solve(candidates, ans, vt, target, 0, 0);
            return ans;
        }
    };


    //note 
    // as while loop takes us to after identical nums so we have to  go to the last identical one so i+1 works well
