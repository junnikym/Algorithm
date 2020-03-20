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
    
    while( !pq.empty() || append_i < jobs.size() ) {
        if( jobs[append_i][0] <= wait && append_i < jobs.size() ) {
            pq.push(jobs[append_i++]);
            
            continue;
        }
        
        if(pq.empty()) {
            wait = jobs[append_i][0];
        }
        else {
            wait += pq.top()[1];
            answer += wait - pq.top()[0];
            pq.pop();
        }
    }

    return answer / jobs.size();
}