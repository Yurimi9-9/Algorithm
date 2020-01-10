// 셀에서 방문할 수 있는 셀 개수의 최댓값 찾기

#include <iostream>

using namespace std;

// v에서 출발하는 깊이우선탐색
void dfs(int v, int n, int cells[], bool visited[])
{
	visited[v] = true;
	// v에서 이동할 수 각 위치 (v의 왼쪽과 오른쪽)로 가 확인
	if (v-cells[v] >= 0) // 왼쪽으로 갈 수 있는지 확인
		if (!visited[v-cells[v]])	// 방문한 적 없다면,
			dfs(v-cells[v], n, cells, visited);	// 왼쪽으로 dfs

	if (v+cells[v] < n)  // 오른쪽으로 갈 수 있는 지 확인
		if (!visited[v+cells[v]])	// 방문한 적 없다면,
			dfs(v+cells[v], n, cells, visited);	// 오른쪽으로 dfs
}

int main()
{
	int n;				// 행을 이루는 셀의 개수
	cin >> n;
	int ways[n]={0,};	// 각 셀에서 출발하였을 때, 도달할 수 있는 셀의 개수 저장
	int cells[n]={0,};	// 각 셀에서 앞 또는 뒤로 이동할 수 있는 인덱스 크기를 저장
	bool visited[n];	// 각 셀들의 방문 상태를 저장할 배열

	// cell에 있는 값 입력받기
	for (int i=0; i<n; i++)
		cin >> cells[i];

	// 모든 셀의 방문상태를 false로 초기화
	for (int i=0; i<n; i++)
		visited[i] = false;

	for (int i=0; i<n; i++)
	{
		dfs(i, n, cells, visited);
		for(int j=0; j<n; j++)
			// cells[v]에서 출발하여 dfs를 하고 나서
			if (visited[j])	// 방문한 셀들의 개수를 모두 세어준다.
			{
				ways[i]++;			// 개수를 세고 난 후,
				visited[j] = false;	// 방문상태를 초기화 해준다.
			}
	}

	// 방문할 수 있는 셀의 개수 최댓값 찾기
	int max=0;
	for(int i=1; i<n; i++)
	{	// 같은 경우에는 인덱스가 큰 숫자를 출력하기 위해 <=을 사용함.
		if(ways[max] <= ways[i])
			max = i;
	}

	cout << max << " " << ways[max];

	return 0;
}
