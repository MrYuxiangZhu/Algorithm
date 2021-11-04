// BubbleSort2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

#define Swap(x, y) { x = x + y; y = x - y; x = x - y; }

template <typename T>
void BubbleSort2(vector<T>& varray)
{
	bool flag = true;
	for (size_t i = 1; i < varray.size() && flag; i++)
	{
		flag = false;
		for (size_t j = 0; j < varray.size() - i - 1; j++)
		{
			if (varray[j] > varray[j + 1])
			{
				Swap(varray[j], varray[j + 1]);
				flag = true;
			}
		}
	}
}

template <typename T>
void BubbleSort(vector<T>& varray)
{
	for (size_t i = 0; i < varray.size(); ++i)
	{
		for (size_t j = 0; j < varray.size() - i - 1; ++j)
		{
			if (varray[j] > varray[j + 1])
			{
				Swap(varray[j], varray[j + 1]);
			}
		}
	}
}

int main()
{
	vector<int> array{ 2, 3, 4, 1, 5, 6, 7, 8, 9, 10 };
	BubbleSort(array);

	for (auto it : array)
	{
		cout << it << " ";
	}

	cout << endl;
}
