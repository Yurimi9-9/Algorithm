// bfs(인접행렬)
#include <iostream>
#include <queue>

using namespace std;

void bfs(int cells[], int n, int start, int finish, int parent[]);

int main()
{
	return 0;
}

void bfs(int cells[], int n, int start, int finish, int parent[])
{
	queue<int> Q;			// bfs 탐색에서 방문할 셀을 큐에 저장
	bool visited[n] = {};	// 셀의 방문 여부를 저장하는 bool형 배열

	visited[start] = true;
	Q.push(start);

	int u;	// 큐에 저장된 가장 첫번째 원소(현재 방문 셀)
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();

		// 도착 셀에 방문하면, 탐색 종료
		if(u==finish)
			return;
		if(!visited[u-cells[u]] && u-cells[u]>=0)
		{	// 왼쪽 노드 방문
			visited[u-cells[u]] = true;
			Q.push(u-cells[u]);
			parent[u-cells[u]] = u;
		}
		if(!visited[u+cells[u]] && u+cells[u]<n)
		{	// 오른쪽 노드 방문
			visited[u+cells[u]] = true;
			Q.push(u+cells[u]);
			parent[u+cells[u]] = u;
		}
	}
	// 탐색이 끝나면, 경로가 없는 것이므로 -1을 parent[finish]에 저장
	parent[finish] = -1;
}

