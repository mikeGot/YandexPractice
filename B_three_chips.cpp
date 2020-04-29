#include <set>
#include <vector>
#include <iostream>

using namespace std;


bool NextSet(int *a, int n, int m)
{
	int k = m;
	for (int i = k - 1; i >= 0; --i)
		if (a[i] < n - k + i + 1)
		{
			++a[i];
			for (int j = i + 1; j < k; ++j)
				a[j] = a[j - 1] + 1;
			return true;
		}
	return false;
}


int main() 
{

	vector<int> vec_a;
	set<int> end_set;
	int min, num;
	int M;
	cin >> M;

	int *ptr_d;
	ptr_d = new int[M];
	
	for (int m = 0; m < M; m++)
	{
		int n;
		cin >> n;
		ptr_d[m] = n;
	}

	int *a;
	a = new int[M];

	for (int i = 0; i < M; i++)
	{
		a[i] = i + 1;
		vec_a.push_back(i + 1);
	}
	
	if (M >= 3)
	{
		while (NextSet(a, M, 3))
		{
			for (int i = 0; i < 3; i++) 
				vec_a.push_back(a[i]);			
		}		
	}


	for (int i = 0; i < vec_a.size() - 2; i++)
		end_set.insert(ptr_d[vec_a[i] - 1] + ptr_d[vec_a[i+1] - 1] + ptr_d[vec_a[i+2] - 1]);
	


	std::set<int>::iterator it = end_set.begin();

	min = abs(*it - M);
	for (it = end_set.begin(); it != end_set.end(); ++it)
	{
		if (abs(*it - M) <= min)
		{
			min = abs(*it - M);
			num = *it;
		}
	}

	cout << num;
	delete[] ptr_d;
	delete[] a;

	return 0;
}