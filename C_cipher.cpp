#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
int main2()
{
	int N;
	vector<int> array;

	ifstream file("input.txt");
	if (!file) {
		std::cout << "Not open " << endl;
		return -1;

	}

	ofstream out_file("output.txt");

	file >> N;

	int r = N/2;


	int **mtrx;
	mtrx = new int*[N];
	for (int i = 0; i < N; i++) mtrx[i] = new int[N];

	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			file >> mtrx[i][j];

	
	int rowBeg = N / 2 - 1;
	int rowEnd = N / 2;
	int colBeg = N / 2;
	int colEnd = N / 2 + 1;
	
	while (r--)
	{
		for (int i = rowEnd; i > rowBeg; i--) 
		{
			
			array.push_back(mtrx[i][colBeg]);
		}

		for (int i = colBeg; i < colEnd; i++)
		{
			
			array.push_back(mtrx[rowBeg][i]);
		}
		

		for (int i = rowBeg; i < rowEnd + 1; i++)
		{
			
			array.push_back(mtrx[i][colEnd]);
		}
		

		for (int i = colEnd; i >= colBeg; i--)
		{
			
			array.push_back(mtrx[rowEnd + 1][i]);
		}
		

	colBeg--;
	rowBeg--;

	colEnd++;
	rowEnd++;
	}

	for (int i = rowEnd; i > rowBeg; i--)
	{
		
		array.push_back(mtrx[i][colBeg]);
	}
		

	for (auto &i : array)
		out_file << i << "\n";



	for (int i = 0; i < N; i++)
		delete[] mtrx[i];
	delete[] mtrx;

		
	out_file.close();
	file.close();
	return 0;
}
