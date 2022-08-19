#include <iostream>

class Matrix
{
public:
	Matrix(int row, int col, int text)
	{
		printf("Matrix(int row, int col)\n");
		_row = row;
		_col = col;
		_data = new float* [_row];
		for (int i = 0; i < _row; i++)
		{
			_data[i] = new float[_col];
			for (int j = 0; j < _col; j++)
			{
				_data[i][j] = 0;
			}
		}
		_text = text;
	}

	Matrix(const Matrix& mat)
	{
		printf("Matrix(const Matrix& mat)\n");
		_row = mat._row;
		_col = mat._col;
		_data = new float* [_row];
		for (int i = 0; i < _row; i++)
		{
			_data[i] = new float[_col];
			for (int j = 0; j < _col; j++)
			{
				_data[i][j] = mat._data[i][j];
			}
		}
	}

	Matrix(Matrix && mat)
	{
		printf("Matrix(Matrix && mat)\n");
		_row = mat._row;
		_col = mat._col;
		_data = mat._data;
		_text = mat._text;
		mat._data = nullptr;
	}
#if 1
	Matrix operator + (const Matrix& mat)
	{
		if (mat._row != _row || mat._col != _col)
		{
			printf("Error\n");
		}

		Matrix res(mat._row, mat._col, 0);

		for (int i = 0; i < mat._row; i++)
		{
			for (int j = 0; j < mat._col; j++)
			{
				res._data[i][j] = _data[i][j] + mat._data[i][j];
			}
		}
		return res;
	}
#endif
#if 0
	friend Matrix operator + (const Matrix& a, const Matrix& b)
	{
		printf("friend Matrix operator + (const Matrix& a, const Matrix& b)\n");
		if (a._row != b._row || a._col != b._col)
		{
			printf("Error\n");
		}

		Matrix res(a._row, a._col);

		for (int i = 0; i < a._row; i++)
		{
			for (int j = 0; j < a._col; j++)
			{
				res._data[i][j] = a._data[i][j] + b._data[i][j];
			}
		}
		return res;
	}

	friend Matrix operator + (Matrix&& a, const Matrix& b)
	{
		printf("friend Matrix operator + (Matrix&& a, const Matrix& b)\n");
		if (a._row != b._row || a._col != b._col)
		{
			printf("Error\n");
		}

		Matrix res = std::move(a);

		for (int i = 0; i < a._row; i++)
		{
			for (int j = 0; j < a._col; j++)
			{
				res._data[i][j] = res._data[i][j] + b._data[i][j];
			}
		}
		return res;
	}
#endif
	~Matrix()
	{
		if (_data != nullptr)
		{
			for (int i = 0; i < _row; i++)
			{
				if (_data[i])
				{
					delete[] _data[i];
					_data[i] = nullptr;
				}
			}
			delete[] _data;
			_data = nullptr;
		}
	}

	int _row = 0;
	int _col = 0;
	int _text = 0;
	float** _data = nullptr;
};

int add(int a, int b)
{
	return 10;
}
int add(char a, char b)
{
	return 15;
}

int main()
{
	Matrix a(3, 4, 1);
	Matrix b(3, 4, 2);
	Matrix c(3, 4, 3);
	Matrix d(3, 4, 4);

	//Matrix r = a + b + c + d;
	//Matrix r = std::move(a);
	printf("%d\n", add('a', 'b'));
	return 0;
}