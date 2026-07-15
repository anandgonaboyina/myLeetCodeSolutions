class Solution {
  public:
    void printNumbers(int n) {
        // Your code goes here
        if(n<1) return;
        printNumbers(n-1);
        cout<<n<<endl;
    }
};