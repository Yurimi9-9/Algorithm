// 백준 1260 - DFS와 BFS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
void dfs(vector<vector<int> > &graph, bool visited[], int V);
void bfs(vector<vector<int> > &graph, int N, int V);

int main()
{
	int N=0, M=0;	// N: 정점의 개수, M: 간선의 개수
	cin >> N >> M;
	int V=0;		// V: 탐색을 시작할 정점의 번호
	cin >> V;
	vector<vector<int> > graph(N+1);
	bool visited[N+1]={};	// 각 노드들의 방문 상태

	for(int i=0; i<M; i++)
	{
		int a=0, b=0;	// 서로 연결되는 두 정점 입력 받기
		cin >> a >> b;
		graph[a].push_back(b);	// (양방향 그래프)
		graph[b].push_back(a);	// 그래프 간선 연결
	}

	for(int i=1; i<=N; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(graph, visited, V);
	cout << '\n';
	bfs(graph, N, V);

	return 0;
}


void dfs(vector<vector<int> > &graph, bool visited[], int V)
{
	visited[V] = true;
	cout << V << " ";

	vector<int>::iterator itr = graph[V].begin();
	for(; itr!=graph[V].end(); itr++)
	{
		if(!visited[*itr])
			dfs(graph, visited, *itr);
	}
}

void bfs(vector<vector<int> > &graph, int N, int V)
{
	bool BFSvisited[N+1]={};
	queue<int> Q;
	Q.push(V);	// 시작 노드(V)를 큐에 넣기
	BFSvisited[V] = true;	// 방문 상태 저장

	while(!Q.empty())
	{
		int current = Q.front();	// 큐의 맨 앞 원소 저장
		Q.pop();	// 큐의 맨 앞 원소 꺼내기
		cout << current << " ";

		vector<int>::iterator itr = graph[current].begin();
		for(; itr!=graph[current].end(); itr++)
		{
			if(!BFSvisited[*itr])
			{
				Q.push(*itr);
				BFSvisited[*itr] = true;
			}
		}
	}
}
