class Solution {
public:
    bool checkIthBit(int n, int i) {
        bool status = (n>>i & 1)==1? true : false;
        // or // bool status = (1<<i) & n == 1? true : false;
        return status;
    }
};