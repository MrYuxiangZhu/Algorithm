// PalindromeString.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 回文串

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string GetMaxPalindromeString(string& str)
{
	if (str.size() < 2) return str;
	int length = str.size();
	int start = 0;
	int maxlen = 1;
	vector<vector<int>> DP(length, vector<int>(length, 0));

	for (int i = 0; i < length; ++i)
	{
		DP[i][i] = 1;
	}

	for (int k = 2; k < length; ++k)
	{
		for (int i = 0; i < length; ++i)
		{
			int j = k + i - 1;
			if (j >= length)
			{
				break;
			}

			if (str[i] != str[j])
			{
				DP[i][j] = 0;
			}
			else
			{
				DP[i][j] = j - i < 3 ? 1 : DP[i + 1][j - 1];
			}

			if (DP[i][j] && (j - i + 1) > maxlen)
			{
				start = i;
				maxlen = j - i + 1;
			}
		}
	}

	return str.substr(start, maxlen);
}

int main()
{
	string str = "ababa";
	std::cout << GetMaxPalindromeString(str) << endl;
	return 0;
}
