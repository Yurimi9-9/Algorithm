// 백준 2748
#include <iostream>

using namespace std;

#define MAX 100

long long f[MAX];
// f[MAX] 배열 초기화
void initialize(int n)
{
	for(int i=0; i<=n; i++)
		f[i] = -1;
}
long long fib(int n)
{
	// 초기화 x -> 재귀로 값 찾기
	if(f[n]==-1)
	{
		if(n<=1)
			f[n]=n;
		else
			f[n] = fib(n-1) + fib(n-2);
	}
	// 초기화 o -> 배열에 저장된 값으로 return
	return f[n];
}

/* n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램 */
int main()
{
	// n은 90보다 작거나 같은 자연수
	int n;
	cin >> n;

	initialize(n);	// 1. 값을 저장할 배열 초기화
	cout << fib(n);	// 2. fib() 호출

	return 0;
}
