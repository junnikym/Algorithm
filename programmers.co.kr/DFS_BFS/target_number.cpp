#include <string>
#include <vector>

using namespace std;

int dfs( int pre, int index, vector<int>& numbers, const int& target ) {
    int answer = 0;
    
    if(index == numbers.size()-1) {
        if( pre + numbers[index] == target )
            answer++;

        if( pre - numbers[index] == target)
            answer++;

        return answer;
    }
    else {
        answer += dfs( pre+numbers[index], index+1, numbers, target);
        answer += dfs( pre-numbers[index], index+1, numbers, target);
    }

    return answer;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    answer += dfs(numbers[0], 1, numbers, target);
    answer += dfs(-numbers[0], 1, numbers, target);

    return answer;
}