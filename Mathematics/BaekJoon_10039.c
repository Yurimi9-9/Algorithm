// 백준 10039 - 평균 점수
#include <stdio.h>

int main()
{
	int score[5]={0,};
	int sum=0;
	int i;

	setvbuf(stdout, NULL, _IONBF, 0);
	for(i=0; i<5; i++)	// 점수 입력 받기
	{
		scanf("%d", &score[i]);
		if(score[i]<40)
			score[i]=40;
	}

	for(i=0; i<5; i++)
		sum += score[i];

	printf("%d", sum/5);

	return 0;
}
