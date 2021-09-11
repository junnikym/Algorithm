#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using vec_iter = vector<int>::iterator;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = lost.size();
	bool is_erased = false;

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	for (vec_iter l_it = lost.begin(); l_it != lost.end();)
	{
		for (vec_iter r_it = reserve.begin(); r_it != reserve.end(); r_it++)
		{

			if (*l_it == *r_it)
			{
				l_it = lost.erase(l_it);
				reserve.erase(r_it);
				is_erased = true;
				break;
			}
		}

		if (!is_erased)
			++l_it;

		is_erased = false;
	}

	for (vec_iter l_it = lost.begin(); l_it != lost.end();)
	{
		for (vec_iter r_it = reserve.begin(); r_it != reserve.end(); r_it++)
		{

			if (*l_it - 1 == *r_it || *l_it + 1 == *r_it)
			{
				l_it = lost.erase(l_it);
				reserve.erase(r_it);
				is_erased = true;
				break;
			}
		}

		if (!is_erased)
			++l_it;

		is_erased = false;
	}

	answer = n - lost.size();

	return answer;
}

// ⠄⠄⠄⠄⠄⠄⣀⣀⣀⣤⣶⣿⣿⣶⣶⣶⣤⣄⣠⣴⣶⣿⣿⣿⣿⣶⣦⣄⠄⠄ 
// ⠄⠄⣠⣴⣾⣿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦ 
// ⢠⠾⣋⣭⣄⡀⠄⠄⠈⠙⠻⣿⣿⡿⠛⠋⠉⠉⠉⠙⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿ 
// ⡎⣾⡟⢻⣿⣷⠄⠄⠄⠄⠄⡼⣡⣾⣿⣿⣦⠄⠄⠄⠄⠄⠈⠛⢿⣿⣿⣿⣿⣿ 
// ⡇⢿⣷⣾⣿⠟⠄⠄⠄⠄⢰⠁⣿⣇⣸⣿⣿⠄⠄⠄⠄⠄⠄⠄⣠⣼⣿⣿⣿⣿ 
// ⢸⣦⣭⣭⣄⣤⣤⣤⣴⣶⣿⣧⡘⠻⠛⠛⠁⠄⠄⠄⠄⣀⣴⣿⣿⣿⣿⣿⣿⣿ 
// ⠄⢉⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣦⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿