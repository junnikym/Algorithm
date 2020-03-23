#include <string>
#include <vector>
#include <deque>

#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    int num = 0;
    
    dq.push_back( stoi( (*operations.begin()).substr(2) ) );
    for( auto it = operations.begin()+1; it != operations.end(); it++ ) {
        if( (*it)[0] == 'I' ) {
            num = stoi( (*it).substr(2) );
            
            if( num < *dq.begin() ) 
                dq.push_front(num);
            
            else if( !dq.empty() && num > *(dq.end()-1) ) 
                dq.push_back(num);
            
            else {
                for(auto dq_it = dq.begin(); dq_it != dq.end(); dq_it++) {
                    if( num < *dq_it) {
                        dq.insert(dq_it, num);
                        break;
                    }
                }
            }
        }
            
        else {
            if( !dq.empty() ) {
                if( (*it)[3] == 1 )     // delete max value
                    dq.pop_back();
                else                    // delete min value
                    dq.pop_front();
            }
        }
    }
    
    if(dq.empty()) 
        answer = {0, 0};
    else
        answer = {dq.back(), dq.front()};
    
    for(auto dq_it : dq) {
        cout << dq_it << ", ";
    }
    
    return answer;
}