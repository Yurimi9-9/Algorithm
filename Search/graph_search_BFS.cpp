#include <vector>
#include <queue>

// 너비 우선 탐색 - BFS
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
