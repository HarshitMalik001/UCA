
// https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

class Solution{
public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    if(n == 1) return x % M;
		    
		    x = x % M;
		    
		    long long int t = PowMod(x, n / 2, M ) ;
		    
		    t = (t * t) % M;
		    
		    if(n % 2 == 0) return (t) % M;
		    else return (x * t) % M;
		}
};