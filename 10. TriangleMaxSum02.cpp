#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int rows = 5;
	std::vector<std::vector<int>> DP =
	{
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 7, 0, 0, 0, 0 },
		{ 0, 3, 8, 0, 0, 0 },
		{ 0, 8, 1, 0, 0, 0 },
		{ 0, 2, 7, 4, 4, 0 },
		{ 0, 4, 5, 2, 6, 5 }
	};

	std::vector<std::vector<int>>MaxSum(rows + 1, std::vector<int>(rows + 1, -1));

	for (int i = rows; i >= 1; --i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (i == rows)
			{
				MaxSum[i][j] = DP[i][j];
			}
			else
			{
				MaxSum[i][j] = std::max(MaxSum[i + 1][j], MaxSum[i + 1][j + 1]) + DP[i][j];
			}
		}
	}

	std::cout << "最大路径和: " << MaxSum[1][1] << std::endl;
	return 0;
}