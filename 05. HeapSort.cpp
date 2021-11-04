// 堆排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

#define Swap(x, y) { x = x + y; y = x - y; x = x - y; }

void display(vector<int>& varray)
{
	for (auto iter : varray)
	{
		cout << iter << " ";
	}

	cout << endl;
}

/*从小到大排序*/
void HeapAdjust(vector<int>& varray, int i, int n) //大顶堆
{
	//二叉树坐标是：0，1，2，3，4...
	int parent = i;			//父节点下标
	int child = 2 * i + 1;	//左子节点下标
	while (child < n)
	{
		if ((child + 1 < n) && (varray[child] < varray[child + 1])) //判断左右子节点哪个大，大的与父节点比较
		{
			child++;
		}

		if (varray[parent] < varray[child]) //判断父节点是否小于子节点
		{
			Swap(varray[parent], varray[child]);//交换父节点和子节点
			parent = child;//子节点下标赋值给父节点下标
		}

		child = child * 2 + 1; //换行，比较下面的父节点和子节点
	}
}

void BuildHeap(vector<int>& varray)
{
	for (int i = varray.size() / 2 - 1; i >= 0; --i)//倒数第二排开始，创建大顶堆，必须从下往上比较
	{
		HeapAdjust(varray, i, varray.size()); //否则有的不符合大顶堆定义
	}
}

void HeapSort(vector<int>& varray)
{
	cout << "初始化数组: ";
	BuildHeap(varray); //初始化堆
	display(varray);
	for (int i = varray.size() - 1; i > 0; --i)
	{
		Swap(varray[0], varray[i]);//交换顶点和第i个数据
								   //因为只有varray[0]改变，其他都符合大顶堆的定义，所以可以从上往下重新建立
		HeapAdjust(varray, 0, i); //重新建立大顶堆
		cout << "排序的数组：";
		display(varray);
	}
}

int main()
{
	vector<int>varray { 49, 38, 65, 97, 76, 13, 27, 49, 10 };
	// 打印数据
	cout << "排序前数组：";
	display(varray);
	HeapSort(varray);
	return 0;
}
