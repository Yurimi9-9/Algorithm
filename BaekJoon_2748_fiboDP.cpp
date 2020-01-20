// 백준 2748 - [동적 계획법] 피보나치 수
#include <iostream>

using namespace std;

long long fib(int n);

/* n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램 */
int main()
{
	// n은 90보다 작거나 같은 자연수
	int n;
	cin >> n;

	cout << fib(n);

	return 0;
}

long long fib(int n)
{
	long long prev_prev, prev, current;
	if(n==1 || n==2)
		return 1;
	prev_prev = prev = 1;
	for(int i=3; i<=n; i++)
	{
		current = prev_prev + prev;
		prev_prev = prev;
		prev = current;
	}
	return current;
}
