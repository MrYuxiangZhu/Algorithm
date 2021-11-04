// 数字三角形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int GetMaxSum(std::vector<std::vector<int>>& DP, std::vector<std::vector<int>>& MaxSum, int i, int j)
{
	if (MaxSum[i][j] != -1)
	{
		return MaxSum[i][j];
	}
	else if (i == DP.size() - 1)
	{
		MaxSum[i][j] = DP[i][j];
		return MaxSum[i][j];
	}
	else
	{
		MaxSum[i][j] = std::max(GetMaxSum(DP, MaxSum, i + 1, j), GetMaxSum(DP, MaxSum, i + 1, j + 1)) + DP[i][j];
		return MaxSum[i][j];
	}

	return -1;
}

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

	std::cout << "最大路径和: " << GetMaxSum(DP, MaxSum, 1, 1) << std::endl;
	return 0;
}
