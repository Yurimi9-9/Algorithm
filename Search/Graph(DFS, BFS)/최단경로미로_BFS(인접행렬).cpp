// 단 경로 미로 찾기 - bfs(인접행렬) 사용
#include <iostream>
#include <queue>

using namespace std;

// 이중배열 미로의 셀 인덱스 정보를 저장할 구조체
struct cell {
	int x;
	int y;
};

// bfs로 미로를 탐색한 후, 미로를 빠져나가는 최단 경로의 길이 return
int bfs(char cells[][100], int m, int n, cell v);

int main()
{
	int m=0, n=0;	// m: 행의 개수, n: 열의 개수
	cin >> m >> n;

	char cells[m][100];	// cells[][]: 미로 정보 저장
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin >> cells[i][j];	// 미로 정보 입력 받기

	int mCount=-1;
	for(int i=0; i<n; i++)
	{	// 미로 탐색 - 첫번째 행(고정)에서 출발
		if(cells[0][i]=='1')
		{	// 첫번째 행의 미로 정보가 '1'이면, 그 곳에서 출발하여 탐색
			cell v = {0, i};
			int count = bfs(cells, m, n, v); // dfs 함수에서 리턴한 미로의 최단경로를 count에 저장

			// cells[0][i]에서 출발하여 미로를 탈출하는 경로가 존재할 때
			if(count!=-1)
			{	// 앞서 구해 저장된 최단경로 미로가 -1이라면, 현재 최단경로를 저장
				if(mCount==-1)
					mCount = count;
				// 아닌 경우, 기존의 최단경로와 현재 최단경로를 비교하여 더 작은 값 저장
				else if(mCount > count)
					mCount = count;
			}
		}
	}
	cout << mCount;	// 최단 경로 출력

	return 0;
}


int bfs(char cells[][100], int m, int n, cell v)
{
	queue<cell> Q;			// 탐색에 사용할 큐
	bool visited[m][n]={ };	// 방문 여부 저장
	cell parent[m][n];		// 이전 경로 저장

	// 이전 경로를 저장할 parent[][] 초기화
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			parent[i][j] = {-1,-1};

	// 미로 탐색 시 - 상, 하, 좌, 우 이동 정보
	cell move[4] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

	visited[v.x][v.y] = true;
	Q.push(v); 	// 큐에 v를 넣는다

	cell u;
	while(!Q.empty())
	{
		u = Q.front(); 	// 큐의 가장 앞에 있는 원소
		Q.pop(); 		// 큐의 가장 앞에 있는 원소 삭제

		// 미로의 맨 아랫줄에 도착
		if(u.x == m-1)
		{	// 거쳐온 경로를 탐색하여 방문 셀 개수 세기
			int num=1;
			cell temp = u;
			while(!(temp.x==v.x && temp.y==v.y))
			{
				temp = parent[temp.x][temp.y];
				num++;
			}
			return num;	// 방문한 셀의 개수 반환
		}

		//u와 인접한 각 정점 w에 대하여
		for(int i=0; i<4; i++)
		{
			cell w = {u.x+move[i].x, u.y+move[i].y};
			// 인덱스 범위를 벗어나지 않는지 확인 후, 위/아래/오른쪽/왼쪽 탐색
			if(w.x >= 0 && w.y >= 0 && w.y < n)
			{	// 셀 정보가 '1'이고, 방문한 적 없는 셀만 탐색
				if(cells[w.x][w.y]=='1' && !visited[w.x][w.y])
				{
					visited[w.x][w.y] = true;	// 방문 표시
					Q.push(w);	// Q에 저장
					parent[w.x][w.y] = u;	// 이전 경로 저장
				}
			}
		}
	}
	// 탐색이 끝난 후에도 미로에서 빠져나가지 못했다면, 경로가 없는 것이므로 -1을 리턴.
	return -1;
}

