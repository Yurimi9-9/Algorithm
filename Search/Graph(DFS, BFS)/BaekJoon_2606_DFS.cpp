// 백준 2606 - 바이러스 (DFS 탐색)
#include <iostream>
#include <vector>

using namespace std;

int infected=0;	// 1번 컴퓨터에 의해 감염된 컴퓨터의 수 카운트

void dfs(vector<vector<int> > &graph, bool visited[], int V);

int main()
{
	int N=0, M=0;	// N: 정점의 개수, M: 간선의 개수
	cin >> N >> M;

	vector<vector<int> > graph(N+1);
	bool visited[N+1]={};	// 각 노드들의 방문 상태

	for(int i=0; i<M; i++)
	{
		int a=0, b=0;	// 서로 연결되는 두 정점 입력 받기
		cin >> a >> b;
		graph[a].push_back(b);	// (양방향 그래프)
		graph[b].push_back(a);	// 그래프 간선 연결
	}

	dfs(graph, visited, 1);

	cout << infected;

	return 0;
}


void dfs(vector<vector<int> > &graph, bool visited[], int V)
{
	visited[V] = true;

	vector<int>::iterator itr = graph[V].begin();
	for(; itr!=graph[V].end(); itr++)
		if(!visited[*itr])
		{
			dfs(graph, visited, *itr);
			infected++;		// dfs 탐색으로 노드를 하나씩 찾아갈 때마다 카운트 증가
		}
}
