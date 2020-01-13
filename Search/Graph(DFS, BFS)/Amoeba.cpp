//주어진 N×M개의 아메바 픽셀 정보로 아메바의 개수와 가장 큰 아메바의 크기 찾기

#include <iostream>

using namespace std;

// petri[m][n]에서 출발하는 깊이우선탐색
void dfs(int m, int n, int mMax, int nMax, char petri[][100], bool visited[][100], int size[], int amoeba);

int main()
{
	int M, N;
	cin >> M >> N;
	char petri[M][100]={0,};
	bool visited[M][100]={0,};
	int amoeba=0, size[100]={0,};
	int mSize=0;

	// 아메바의 상태 입력받기
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			cin >> petri[i][j];

	// false로 초기화
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			visited[i][j] = false;

	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{	// 셀이 '1'의 정보를 갖는다면
			if(petri[i][j]=='1')
			{	// 한 번도 간 적 없는 셀만 방문
				if(!visited[i][j])
				{
					dfs(i, j, M, N, petri, visited, size, amoeba);
					amoeba++;	// main에서 dfs를 한 번 호출할 때마다 아메바의 개수 세어주기
				}
			}
		}
	}

	// 존재하는 아메바들 중 최대 크기 찾기
	for(int i=1; i<amoeba; i++)
		if(size[mSize] < size[i])
			mSize = i;

	cout << amoeba << " " << size[mSize];

	return 0;
}

// petri[m][n]에서 출발하는 깊이우선탐색
void dfs(int m, int n, int mMax, int nMax, char petri[][100], bool visited[][100], int size[], int amoeba)
{
	visited[m][n] = true;	// 방문한 셀 표시
	size[amoeba]++;	// dfs가 호출될때마다 해당 아메바의 size 증가

	if (m-1 >= 0) // 위로 갈 수 있는지 확인
	{
		if(!visited[m-1][n] && petri[m-1][n]=='1')
			dfs(m-1, n, mMax, nMax, petri, visited, size, amoeba);
		if(n-1 >= 0)	// 왼쪽으로 갈 수 있는지 확인
		{
			if(!visited[m-1][n-1] && petri[m-1][n-1]=='1')	// 방문한 적 없다면,
				dfs(m-1, n-1, mMax, nMax, petri, visited, size, amoeba);
		}
		if(n+1 < nMax)	// 오른쪽으로 갈 수 있는지 확인
		{
			if(!visited[m-1][n+1] && petri[m-1][n+1]=='1')
				dfs(m-1, n+1, mMax, nMax, petri, visited, size, amoeba);
		}
	}

	if(n-1 >= 0)	// 왼쪽으로 갈 수 있는지 확인
	{
		if(!visited[m][n-1] && petri[m][n-1]=='1')	// 방문한 적 없다면,
			dfs(m, n-1, mMax, nMax, petri, visited, size, amoeba);
	}
	if(n+1 < nMax)	// 오른쪽으로 갈 수 있는지 확인
	{
		if(!visited[m][n+1] && petri[m][n+1]=='1')
			dfs(m, n+1, mMax, nMax, petri, visited, size, amoeba);
	}

	if (m+1 < mMax) // 아랫줄로 갈 수 있는지 확인
	{
		if(!visited[m+1][n] && petri[m+1][n]=='1')
			dfs(m+1, n, mMax, nMax, petri, visited, size, amoeba);
		if(n-1 >= 0)	// 왼쪽으로 갈 수 있는지 확인
		{
			if(!visited[m+1][n-1] && petri[m+1][n-1]=='1')	// 방문한 적 없다면,
				dfs(m+1, n-1, mMax, nMax, petri, visited, size, amoeba);
		}
		if(n+1 < nMax)	// 오른쪽으로 갈 수 있는지 확인
		{
			if(!visited[m+1][n+1] && petri[m+1][n+1]=='1')
				dfs(m+1, n+1, mMax, nMax, petri, visited, size, amoeba);
		}
	}
}

