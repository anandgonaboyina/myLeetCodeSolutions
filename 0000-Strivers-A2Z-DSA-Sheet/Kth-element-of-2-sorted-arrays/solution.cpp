//it comes to hard problem so will look at this later
//it uses the logic of that hard problem medain of two sorted ARRays so will do later

// not binary search solution but normal brute force solutioin of TC as M+N
class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) 
    {
       int left = a.size()-1, right = b.size()-1;
       int i=0, j=0;
       int kthNum=0;
       int ans = -1;
       while(i<=left && j<=right)
       {
            if(a[i]<=b[j])
                {
                    i++;
                    kthNum++;
                    if(kthNum == k)
                        {
                            ans = a[i];
                            break;
                        }
                }
            else
                {
                    j++;
                    kthNum++;
                        if(kthNum == k)
                            {
                                ans = b[j]
                                break;
                            }
                }
       }
       return ans;
    }
};