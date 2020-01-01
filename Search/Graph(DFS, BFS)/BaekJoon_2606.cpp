// 백준 1260 - DFS와 BFS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dfs(vector<vector<int> > &graph, bool visited[], int V, int count);

int main()
{
	int N=0, M=0;	// N: 정점의 개수, M: 간선의 개수
	cin >> N >> M;
	int count=0;

	vector<vector<int> > graph(N+1);
	bool visited[N+1]={};	// 각 노드들의 방문 상태

	for(int i=0; i<M; i++)
	{
		int a=0, b=0;	// 서로 연결되는 두 정점 입력 받기
		cin >> a >> b;
		graph[a].push_back(b);	// (양방향 그래프)
		graph[b].push_back(a);	// 그래프 간선 연결
	}

	count = dfs(graph, visited, 1, count);

	cout << count;

	return 0;
}


int dfs(vector<vector<int> > &graph, bool visited[], int V, int count)
{
	visited[V] = true;

	vector<int>::iterator itr = graph[V].begin();
	for(; itr!=graph[V].end(); itr++)
	{
		if(!visited[*itr])
			count = dfs(graph, visited, *itr, count)+1;
	}
}
