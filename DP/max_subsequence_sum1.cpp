// 연속하는 수들의 최대 합 구하기
#include <iostream>

using namespace std;

int main()
{
	int max=0;
	// 주어지는 수들의 개수
	int n=0;
	cin >> n;

	// 연속하는 수들 입력받기
	int num[n]={ };
	for(int i=0; i<n; i++)
		cin >> num[i];

	int sum[n]={ };	// i에서 끝나는 연속하는 수들의 최대 합
	int p[n]={ };	// 연속하는 수들의 시작 인덱스

	sum[0] = num[0]; p[0] = 0;	// basecase (i==0)
	max = 0;
	for(int i=1; i<n; i++)
	{
		if(sum[i-1]>0)
		{	// 양수를 더하면 커지므로, sum[i-1]>0인 경우 더해줌.
			sum[i] = sum[i-1] + num[i];
			p[i] = p[i-1];
		}
		else
		{	// 음수를 더하면 작아지므로, 앞부분을 포함하지 않음
			sum[i] = num[i];
			p[i] = i;
		}
		// i에서 끝나는 최대 합들 중 최댓값 찾기
		if(sum[i] > sum[max])
			max = i;
	}

	cout << "연속하는 수들의 최대합은 " << p[max] << " ~ " << max
			<< "까지의 합 = " << sum[max] << " 입니다." << endl;

	return 0;
}
