//solution
class Solution{	
	public:
		int NnumbersSum(int N){
			//your code goes here
            if(N==1)
                    return 1;
            return N+NnumbersSum(N-1);
		}
};