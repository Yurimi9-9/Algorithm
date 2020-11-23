// 백준 2839 - 설탕 배달
#include <stdio.h>

int main()
{
	int N=0;
	int i, j;		// i:5kg, j:3kg

	setvbuf(stdout, NULL, _IOFBF, 0);
	scanf("%d", &N);

	for(i=N/5; i>=0; i--)
	{
		j = (N-5*i)/3;
		if((5*i+3*j)==N)
			break;
	}

	if(i==-1)	// 정확하게 N킬로그램을 만들 수 없을 때, -1 출력
		printf("%d", i);
	else		// 배달하는 봉지의 최소 개수 출력
		printf("%d", i+j);

	return 0;
}
