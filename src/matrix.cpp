#include <vector>
#include <iostream>

class Matrix
{
    size_t _rows;
    size_t _columns;

    /* A=
     * | 1 1 1 |
     * | 2 2 2 |
     * | 3 3 3 |
     *
     * _data = 1, 1, 1, 2, 2, 2, 3, 3, 3
     * A[0] = | 1 1 1 | 
     */
    std::vector<char> _data;

    class Proxy
    {
        Matrix* _matrix;
        size_t _colNum;
    public:
        Proxy(Matrix* matrix_, size_t i)
        :   _matrix(matrix_)
        ,   _colNum(i)
        {
        }

        Proxy(std::vector<char> column)
        :   _colNum(0)
        {
            _matrix = new Matrix(column);
        }

        const char& operator[](size_t j) const
        {
            return _matrix->_data[j*_colNum]; 
        }

        char& operator[](size_t j)
        {
            return _matrix->_data[j*_colNum]; 
        }

        Proxy& operator=(const Proxy&& proxy_)
        {
            for (size_t i(_colNum*_matrix->ncols()); i <= (1+_colNum)*_matrix->nrows(); i++) 
            {
                _matrix->_data[i] =  proxy_._matrix->_data[i-_colNum];
            }
            return *this;
        }
    };

public:
    Matrix(const std::vector<char>& column_)
    :   _rows(column_.size())
    ,   _columns(1)
    ,   _data(column_)
    {}

    Matrix(size_t m, size_t n)
    :   _rows(n)
    ,   _columns(m)
    ,   _data(_rows*_columns)
    {
    }

    size_t nrows() const { return _rows; }
    size_t ncols() const { return _columns; }

    // matrix[i][j] 
    Proxy operator[] (size_t i)
    {
        return Proxy(this, i);
    }

    const Proxy operator[] (size_t i) const
    {
        return Proxy(this, i);
    }
};

std::ostream& operator<<(std::ostream& os_, const Matrix& matrix_)
{
    int j(0);
    for (size_t i(0); i <= matrix_.nrows(); i++)
    {
        os_ << '\t' << matrix_[i][j] << '\t';
        if (i % matrix_.nrows() == 0)
            os_ << '\n';
    }
}
