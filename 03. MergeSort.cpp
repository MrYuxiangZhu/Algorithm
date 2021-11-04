// MergeSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void Merge(vector<T>& vec, int low, int mid, int high)
{
	//low为第1有序区的第1各元素，i指向第1个元素，mid为第1有序区的最后1个元素
	int i = low, j = mid + 1, k = 0;//mid+1为第2有序区第1个元素，j指向第1个元素
	vector<T> temp(high - low + 1, 0);//temp数组暂存合并的有序序列
	//cout << temp.size() << endl;
	while (i < mid && j <= high)
	{
		if (vec[i] <= vec[j])//较小的先存入temp中
		{
			temp[k++] = vec[i++];
		}
		else
		{
			temp[k++] = vec[j++];
		}
	}

	while (i <= mid)//若比较完之后，第一个有序区仍有剩余，则直接复制到temp数组中
	{
		temp[k++] = vec[i++];
	}

	while (j <= high)//若比较完之后，第二个有序区仍有剩余，则直接复制到temp数组中
	{
		temp[k++] = vec[j++];
	}

	for (i = low, k = 0; i <= high; ++i, ++k)
	{
		vec[i] = temp[k];
	}
}

template <typename T>
void MergeSort(vector<T>& vec, int low, int high)
{
	if (low >= high)//终止递归的条件，子序列长度为1
	{
		return;
	}

	int mid = low + (high - low) / 2;//取得序列中间的元素
	MergeSort(vec, low, mid);//对左半边递归
	MergeSort(vec, mid + 1, high);//对右半边递归
	Merge(vec, low, mid, high);
}

int main()
{
	vector<int>vec{ 8, 10, 9, 7, 6, 4, 3, 1, 2, 5};
	MergeSort(vec, 0, 9);
	for (auto it : vec)
	{
		//cout << it << " ";
	}

	cout << endl;

	return 0;
}