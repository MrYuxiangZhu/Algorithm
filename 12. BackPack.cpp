// BackPack.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 背包问题，动态规划

#include <iostream>
#include <vector>

using namespace std;

int GetMaxBag(std::vector<int>& vGoodsWg, std::vector<int>& vValue, int nWeightMax)
{
    if (vGoodsWg.size() <= 0 || vValue.size() <= 0) return -1;

    int nGoodsMax = vGoodsWg.size();
    std::vector<std::vector<int>> vMaxValue(nGoodsMax, std::vector<int>(nWeightMax + 1, 0));

    for (int i = 0; i < nGoodsMax; ++i)
    {
        for (int j = 1; j <= nWeightMax; ++j)
        {
            if (i == 0)
            {
                vMaxValue[i][j] = (vGoodsWg[i] <= j ? vValue[i] : 0);
            }
            else
            {
                if (vGoodsWg[i] > j)
                {
                    vMaxValue[i][j] = vMaxValue[i - 1][j];
                }
                else
                {
                    vMaxValue[i][j] = std::max(vValue[i], std::max(vMaxValue[i - 1][j], vMaxValue[i - 1][j - vGoodsWg[i]] + vValue[i]));
                }
            }
        }
    }

    for (auto iter : vMaxValue)
    {
        for (auto it : iter)
        {
            cout << it << " ";
        }

        cout << endl;
    }

    return vMaxValue[nGoodsMax - 1][nWeightMax];
}

int main()
{
    //std::vector<int> vGoodsWg = { 1, 4, 3 };
    //std::vector<int> vValue = { 1500, 3000, 2000 };
    std::vector<int> vGoodsWg = { 3, 4, 5 };
    std::vector<int> vValue = { 4, 5, 6 };

    std::cout << "最大价值：" << GetMaxBag(vGoodsWg, vValue, 10) << std::endl;

    return 0;
}