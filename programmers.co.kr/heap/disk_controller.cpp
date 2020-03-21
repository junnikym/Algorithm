#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct pq_comp {
    bool operator() (vector<int> lhs, vector<int> rhs) {
        return lhs[1] > rhs[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    int append_i = 0;
    int wait = 0;

    priority_queue< vector<int>, vector<vector<int>>, pq_comp > pq;
    
    sort(jobs.begin(), jobs.end());
    
    while( append_i < jobs.size() || !pq.empty() ) {
        
        if( append_i < jobs.size() && jobs[append_i][0] <= wait ) {
            pq.push( jobs[append_i] );
            append_i++;
            
            continue;
        }
        
        if( !pq.empty() ) {
            wait += pq.top().at(1);
            answer += wait - pq.top().at(0);
            pq.pop();
        }
        else {
            wait = jobs[append_i][0];
        }
    }

    return answer / jobs.size();
}