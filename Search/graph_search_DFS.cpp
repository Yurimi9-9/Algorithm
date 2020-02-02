#include <vector>

// 깊이 우선 탐색
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
