
/*
We are given an array of integers. For each number, if it has exactly four positive divisors, 
we add the sum of those divisors to the result

For each number, I count its divisors by checking up to √n.
If the divisor count is exactly four, I add their sum.

optimal 
A number has exactly four divisors only if it is of the form p³ or p×q, where p and q are prime numbers.
So we only check these two cases instead of counting all divisors.


cbrt(x) returns the cube root of x
O(n√m)


Case ️1: p³ where p is prime

Divisors: 1, p, p², p³
Sum = 1 + p + p² + p³

Case 2 ️: p × q where p and q are distinct primes

Divisors: 1, p, q, p×q
Sum = 1 + p + q + (p×q)

No other number can have exactly 4 divisors 
*/
class Solution
{
public:

    bool isprime (int n)
    {

        if(n<2) return false ;
        for(int i =2; i*i<=n; i++)
        
            if(n%i == 0) return false ;

            return true;

        
    }
    int sumFourDivisors(vector<int>& nums)
    {

        int ans =0;
        for(int n : nums)
        {
            int p = round(cbrt(n));
            if( p* p*p ==n && isprime(p))
            {
                ans += 1+p+p*p+n;
                continue;

            }

            for(int i =2; i*i <=n; i++)
            {
                if(n%i==0)
                {
                    int j =n/i;
                    if(i!=j && isprime(i)&& isprime(j) )
                    {
                        ans+=1+i +j+n;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};