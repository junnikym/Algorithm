#include <string>
#include <vector>

using namespace std;

int dfs(int index, const vector<vector<int>>& computer, vector<int>& visited) {
	if(visited[index] != 0) {
		return 0;
	}

	visited[index] = 1;

	for(int i = 0; i < computer[index].size(); i++) {
		if(computer[index][i] == 1) 
			dfs(i, computer, visited);
	}

	return 1;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector<int> visited_node;
	visited_node.assign(n, 0);

	for(int i = 0; i < n; i++) {
		if(visited_node[i] == 0)
			answer += dfs(i, computers, visited_node);
	}

	return answer;
}