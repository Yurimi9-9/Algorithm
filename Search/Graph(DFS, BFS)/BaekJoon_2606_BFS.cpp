// 백준 2606 - 바이러스 (BFS 탐색)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int infected=0;	// 1번 컴퓨터에 의해 감염된 컴퓨터의 수 카운트

void bfs(vector<vector<int> > &graph, int N, int V);

int main()
{
	int N=0, M=0;	// N: 정점의 개수, M: 간선의 개수
	cin >> N >> M;

	vector<vector<int> > graph(N+1);

	for(int i=0; i<M; i++)
	{
		int a=0, b=0;	// 서로 연결되는 두 정점 입력 받기
		cin >> a >> b;
		graph[a].push_back(b);	// (양방향 그래프)
		graph[b].push_back(a);	// 그래프 간선 연결
	}

	bfs(graph, N, 1);

	cout << infected;

	return 0;
}


void bfs(vector<vector<int> > &graph, int N, int V)
{
	bool visited[N+1]={};
	queue<int> Q;
	Q.push(V);	// 시작 노드(V)를 큐에 넣기
	visited[V] = true;	// 방문 상태 저장

	while(!Q.empty())
	{
		int current = Q.front();	// 큐의 맨 앞 원소 저장
		Q.pop();	// 큐의 맨 앞 원소 꺼내기

		vector<int>::iterator itr = graph[current].begin();
		for(; itr!=graph[current].end(); itr++)
		{
			if(!visited[*itr])
			{
				Q.push(*itr);
				visited[*itr] = true;
				infected++;	// 감염된(방문한) 컴퓨터의 수 증가
			}
		}
	}
}
