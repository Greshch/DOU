#include <iostream>
using namespace std;

struct Array2D
{
	int* matrix = nullptr;
	int row;
	int col;

	Array2D();
	Array2D(int row_, int col_);
	int& get(int row_, int col_);
	~Array2D();
};

int main()
{
	Array2D tmp;
	cout << tmp.get(0, 2) << endl;
	tmp.get(0, 2) = 5;
	cout << tmp.get(0, 2) << endl;
	cout << "HELLO\n";
	return 0;
}

Array2D::Array2D() : Array2D(1, 10)
{
}

Array2D::Array2D(int row_, int col_) : row(row_), col(col_), 
										matrix(new int[row_ * col_])
{
	int size = row * col;
	//cout << "size " << size << endl;
	for (size_t i = 0; i < size; i++)
	{
		matrix[i] = 0;
	}
}

int& Array2D::get(int r_, int c_)
{
	return matrix[r_ * col + c_ ];
}

Array2D::~Array2D()
{
	delete[] matrix;
}
