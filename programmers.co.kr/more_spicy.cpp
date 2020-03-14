#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> sc, int K) {
    int answer = 0;
    int val_result = 0;
    
    priority_queue< int, vector<int>, greater<int> > pq( sc.begin(), sc.end() );
    
    for(; pq.top() < K; answer ++) {
        if(pq.size() < 2)
            return -1;

        val_result = pq.top();
        pq.pop();

        val_result += pq.top() * 2;
        pq.pop();

        pq.push( val_result );
    }

    return answer;
}