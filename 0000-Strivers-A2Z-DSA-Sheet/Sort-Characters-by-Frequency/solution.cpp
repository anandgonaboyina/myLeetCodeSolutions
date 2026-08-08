// leet code problem : 451. Sort Characters By Frequency
//my brute solution got 100% beats Tc is NlogN and 
// space Complexity 1 as for ans return we dont count and fixed array size has taken
class Solution {
public:
    string frequencySort(string s) {
        // vector<int> hashArr(26, 0);  //wont work
        vector<pair<int, char>> hashArr(123, {0, 0});
        string ans="";
        for(char ch : s)
        {
            hashArr[ch] = {++hashArr[ch].first, ch};
        }
        sort(hashArr.begin(), hashArr.end());
        for(int i = 122; i>=0; i--)    
        {
            if(hashArr[i].first == 0)
                break;
             // as sorted all are 0's  from first 0 from right are no chars or digits so stopped here
           /*  for(int j=0; j<hashArr[i].first; j++)
                    ans += hashArr[i].second;
            */
                    // insted lead using the append method better as loop relocates the memory that many time
                    //but append will relocate at once with that many times you want to add
            ans.append(hashArr[i].first, hashArr[i].second);
        }
        return ans;
    }
};