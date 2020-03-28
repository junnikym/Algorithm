#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<bool> visited;
    queue<int> visited_index;

    // ! TODO : Initialize visited vector

    // Using BFS Algorithm
    while() {
        for(int i = 0; i < numbers.size(); i++) {
            if(visited[i] == false) {
                visited_index.push(i);
                visited[i] == true;
            }

            break;
        }
    }
    
    return answer;
}