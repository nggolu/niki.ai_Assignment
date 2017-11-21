#include<bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
 
 
void mul(long long int A[2][2], long long int B[2][2])
{
	long long int a = ((A[0][0]*B[0][0])%MOD + (A[0][1]*B[1][0])%MOD)%MOD;
	long long int b = ((A[0][0]*B[0][1])%MOD + (A[0][1]*B[1][1])%MOD)%MOD;
	long long int c = ((A[1][0]*B[0][0])%MOD + (A[1][1]*B[1][0])%MOD)%MOD;
	long long int d = ((A[1][0]*B[0][1])%MOD + (A[1][1]*B[1][1])%MOD)%MOD;
	A[0][0] = a;
	A[0][1] = b;
	A[1][0] = c;
	A[1][1] = d;
}
 
void power(long long int A[2][2], long long int n)
{
	  if( n == 0 || n == 1)
	      return;
	  long long int B[2][2];
	  B[0][0]=1;
	  B[0][1]=1;
	  B[1][0]=1;
	  B[1][1]=0;
	  power(A, n/2);
	  mul(A, A);
 
	  if (n%2 != 0)
	     mul(A, B);
}
 
long long int fibonacci(long long int n)
{
	  long long int A[2][2];
	  A[0][0]=1;
	  A[0][1]=1;
	  A[1][0]=1;
	  A[1][1]=0;
 
	  if (n == 0)
	    return 0;
	  if (n == 1)
	    return 2;
	  if (n == 2)
	    return 3;
	  power(A, n-2);
	  return (A[0][0]*3+A[0][1]*2)%MOD;
}
 
 
 
 
 
int main()
{
	long long int T;
	cin >> T;
	while(T--)
	{
		long long int num;
		cin >> num;
		cout << fibonacci(num) << endl;
	}
	return 0;
}
