// InsertionSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

#define Swap(x, y) { x = x + y; y = x - y; x = x - y; }

template <typename T>
void InsertionSort(vector<T>& varray)
{
	for (size_t i = 1; i < varray.size(); ++i)
	{
		for (size_t j = i; j > 0; --j)
		{
			if (varray[j - 1] > varray[j])
			{
				Swap(varray[j - 1], varray[j]);
			}
		}
	}
}

int main()
{
	vector<int> int_array{ 10, 8, 9, 6, 7, 1, 2, 4, 5, 3 };
	vector<char> char_array{ 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A' };
	InsertionSort(int_array);
	InsertionSort(char_array);
	for (auto it : int_array)
	{
		cout << it << " ";
	}
	cout << endl;

	for (auto it : char_array)
	{
		cout << it << " ";
	}
	cout << endl;
	return 0;
}
