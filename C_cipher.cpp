#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
int main2()
{
	int N;
	vector<int> array;

	ifstream file("c:/D/С++/yandex/num1/input.txt");
	if (!file) {
		std::cout << "Not open " << endl;
		return -1;

	}

	ofstream out_file("c:/D/С++/yandex/num1/output.txt");

	file >> N;

	/*while (!file.eof()) {
		int n;
		file >> n;
		//numbers.push_back(n);
	}*/

	
	int r = N/2;


	int **mtrx;
	mtrx = new int*[N];
	for (int i = 0; i < N; i++) mtrx[i] = new int[N];

	//Считаем матрицу из файла
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			file >> mtrx[i][j];

	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << mtrx[i][j] << "\t";
		cout << "\n";
	}*/

	



	/*int rowBeg = 0;
	int rowEnd = ROWS - 1;
	int colBeg = -1;
	int colEnd = COLS - 1;
	int amount = ROWS * COLS;
	int value = 0;

	// закручиваем спираль
	while (value < amount)
	{
		for (int i = ++colBeg; i <= colEnd && value < amount; i++)
			matr[rowBeg][i] = ++value;
		for (int i = ++rowBeg; i <= rowEnd && value < amount; i++)
			matr[i][colEnd] = ++value;
		for (int i = --colEnd; i >= colBeg && value < amount; i--)
			matr[rowEnd][i] = ++value;
		for (int i = --rowEnd; i >= rowBeg && value < amount; i--)
			matr[i][colBeg] = ++value;
	}



	cout << endl;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++)
			cout << setw(3) << matr[i][j];
		cout << endl;
	}
	cout << endl;

	rowBeg = 0;
	rowEnd = ROWS - 1;
	colBeg = -1;
	colEnd = COLS - 1;*/

	
	int rowBeg = N / 2 - 1;
	int rowEnd = N / 2;
	int colBeg = N / 2;
	int colEnd = N / 2 + 1;
	// раскручиваем
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


	/*for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			out_file << mtrx[i][j] << endl;*/


	for (int i = 0; i < N; i++)
		delete[] mtrx[i];
	delete[] mtrx;

		
	out_file.close();
	file.close();
	return 0;
}