#include <iostream>
#include <string>
#include <vector>

constexpr int ALPHABET_CODE_START = 65;
constexpr int N_ALPHABET = 26;
constexpr int MAX_SIZE = 20;

using namespace std;

int a_position[MAX_SIZE * 2 + 1] = {
	0,
};

int solution(string name)
{
	int answer = 0;
	int item = 0;
	int need_to_change = name.size();

	for (int i = 0; i < name.size(); i++)
	{
		item = (int)name[i] - ALPHABET_CODE_START;
		if (item > N_ALPHABET / 2)
			item = abs(item - N_ALPHABET);

		if (item == 0)
		{
			need_to_change--;
			a_position[MAX_SIZE + i] = 1;
			a_position[MAX_SIZE - name.size() + i] = 1;
		}

		answer += item;
	}
	a_position[MAX_SIZE - name.size()] = 0;

	if (a_position[MAX_SIZE] == 0)
	{
		a_position[MAX_SIZE] = 1;
		need_to_change--;
	}

	cout << "middle answer is " << answer << " \n and need to change " << need_to_change << " times" << endl;

	for (int i = 0; need_to_change != 0;)
	{
		for (int j = 0; j < 41; j++)
		{
			cout << a_position[j];
		}
		cout << endl;

		int front = 0;
		int back = 0;

		for (int j = i + 1; j < (int)name.size(); j++)
		{
			front++;
			if (a_position[MAX_SIZE + j] == 0)
				break;
		}

		for (int j = i - 1; j < ((int)name.size()) - 1; j--)
		{
			back++;
			if (a_position[MAX_SIZE + j] == 0)
				break;
		}

		cout << "(" << ((int)name.size()) - 1 << ")" << back << " -- " << front << " : ";

		if (back < front || front == 0)
		{
			for (int j = 1; j <= back; j++)
			{
				a_position[MAX_SIZE + i - j] = 1;
				a_position[MAX_SIZE - name.size() + (i - j)] = 1;
			}
			i -= back;
			cout << "</- " << back << endl;
			answer += back;
		}
		else
		{
			for (int j = 1; j <= front; j++)
			{
				a_position[MAX_SIZE + (i + j)] = 1;
				a_position[MAX_SIZE - name.size() + (i + j)] = 1;
			}
			i += front;
			cout << "-/> " << front << endl;
			answer += front;
		}
		need_to_change--;
	}

	return answer;
}