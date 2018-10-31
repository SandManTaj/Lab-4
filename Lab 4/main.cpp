#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int quick_select(vector<int> &arr, int l, int r, int k)
{
	int left = l;
	int right = r;
	int mid = ceil((double(l + r)) / 2);

	int pivot = 0;
	if (arr[mid] < arr[left] && arr[left] < arr[right] || arr[mid] > arr[left] && arr[left] > arr[right])
		pivot = left;
	else if (arr[mid] < arr[right] && arr[right] < arr[left] || arr[mid] > arr[right] && arr[right] > arr[left])
		pivot = right;
	else
		pivot = mid;


	while (left < pivot || pivot < right)
	{
		if (left < pivot)
		{
			while (arr[left] < arr[pivot])
			{
				left++;
			}
		}
		if (right > pivot)
		{
			while (arr[right] > arr[pivot])
			{
				right--;
			}
		}

		if (left < pivot && right > pivot)
		{
			swap(arr[left], arr[right]);
			right--;
			left++;
		}

		else if (left < pivot && pivot >= right)
		{
			for (int i = left; i < pivot; i++)
			{
				swap(arr[i], arr[i + 1]);
			}
			pivot--;
			left++;
		}
		else if (left >= pivot && pivot < right)
		{
			for (int i = right; i > pivot; i--)
			{
				swap(arr[i], arr[i - 1]);
			}
			pivot++;
		}


	}
	if (k == pivot)
	{
		return arr[k];
	}
	else if (k < pivot)
	{
		return quick_select(arr, l, pivot, k);
	}
	else if (k > pivot)
	{
		return quick_select(arr, pivot, r, k);
	}
}
int quick_selecti(vector<int> &arr, int l, int r, int k)
{
	int left = l;
	int right = r;
	int mid = ceil((double(l + r)) / 2);

	int pivot = 0;
	if (arr[mid] < arr[left] && arr[left] < arr[right] || arr[mid] > arr[left] && arr[left] > arr[right])
		pivot = left;
	else if (arr[mid] < arr[right] && arr[right] < arr[left] || arr[mid] > arr[right] && arr[right] > arr[left])
		pivot = right;
	else
		pivot = mid;


	while (left < pivot || pivot < right)
	{
		if (left < pivot)
		{
			while (arr[left] < arr[pivot])
			{
				left++;
			}
		}
		if (right > pivot)
		{
			while (arr[right] > arr[pivot])
			{
				right--;
			}
		}

		if (left < pivot && right > pivot)
		{
			swap(arr[left], arr[right]);
			right--;
			left++;
		}

		else if (left < pivot && pivot >= right)
		{
			for (int i = left; i < pivot; i++)
			{
				swap(arr[i], arr[i + 1]);
			}
			pivot--;
			left++;
		}
		else if (left >= pivot && pivot < right)
		{
			for (int i = right; i > pivot; i--)
			{
				swap(arr[i], arr[i - 1]);
			}
			pivot++;
		}


	}

	if (k == pivot)
	{
		return k;
	}
	else if (k < pivot)
	{
		return quick_selecti(arr, l, pivot - 1, k);
	}
	else if (k > pivot)
	{
		return quick_selecti(arr, pivot + 1, r, k);
	}
}
void max_select(vector<int> &arr, int l, int r, int k)
{

	int pivot = quick_selecti(arr, l, r, arr.size() - k);
	for (int i = pivot; i < arr.size(); i++)
		cout << arr[i] << " ";
}

int main()
{
	vector<int> vec;
	vector<int> vec2;
	int n;
	int k;
	srand(time(0));
	cout << "Please enter the number of elements in the array: ";
	cin >> n;
	cout << endl;
	cout << "Please enter the k for the kth smallest element: ";
	cin >> k;
	cout << endl;
	for (int i = 0; i < n; i++)
		vec.push_back((rand() % 201 - 100));
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	int j = quick_select(vec, 0, vec.size()-1, k - 1);
	cout << j << endl;

	for (int i = 0; i < 20; i++)
		vec2.push_back((rand() % 201 - 100));
	max_select(vec2, 0, vec2.size() - 1, 5);
}