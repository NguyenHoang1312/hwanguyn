#include<bits/stdc++.h>
using namespace std;

class MATRIX {
    int row, column;
    double **array;
public:
    friend istream& operator>> (istream& is, MATRIX& matrix);
    friend ostream& operator<< (ostream& os, MATRIX matrix);
    MATRIX operator- ();
    MATRIX operator- (MATRIX other);
    MATRIX operator+ (MATRIX other);
};

istream& operator>> (istream& is, MATRIX& matrix) {
    cout << "Nhap so hang ma tran: "; is >> matrix.row;
    cout << "Nhap so cot ma tran: "; is >> matrix.column; 
    
    matrix.array = new double*[matrix.row];
    for (int i = 0; i < matrix.column; ++i) {
        matrix.array[i] = new double[matrix.column];
    }

    cout << "Nhap ma tran kich co " << matrix.row << " x " << matrix.column << ":\n";
    for (int i = 0; i < matrix.row; ++i) {
        for (int j = 0; j < matrix.column; ++j) {
            is >> matrix.array[i][j];
        }
    }
    return is;
}

ostream& operator<< (ostream& os, MATRIX matrix) {
    os << "Kich thuoc ma tran la: " << matrix.row << " x " << matrix.column << endl;
    os << "Ma tran:\n";
    for (int i = 0; i < matrix.row; ++i) {
        for (int j = 0; j < matrix.column; ++j) {
            os << matrix.array[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

MATRIX MATRIX::operator-() {
    MATRIX result;
    result.row = this->row;
    result.column = this->column;

    result.array = new double*[this->row];
    for (int i = 0; i < this->column; ++i) {
        result.array[i] = new double[this->column];
    }

    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->column; ++j) {
            result.array[i][j] = -(this->array[i][j]);
        }
    }
    return result;
}

MATRIX MATRIX::operator- (MATRIX other) {
    MATRIX result;
    result.row = this->row;
    result.column = this->column;
    
    result.array = new double*[this->row];
    for (int i = 0; i < this->column; ++i) {
        result.array[i] = new double[this->column];
    }

    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->column; ++j) {
            result.array[i][j] = this->array[i][j] - other.array[i][j];
        }
    }
    return result;
}

MATRIX MATRIX::operator+ (MATRIX other) {
    MATRIX result;
    result.row = this->row;
    result.column = this->column;
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->column; ++j) {
            result.array[i][j] = this->array[i][j] + other.array[i][j];
        }
    }
    return result;
}

int main() {
    system("cls");
    MATRIX a, b, c, d;
    cout << "Nhap ma tran a:\n";
    cin >> a;
    cout << "Nhap ma tran b:\n";
    cin >> b;
    cout << a;
    cout << "\nDoi dau ma tran:\n";
    a = -a;
    cout << a;
    cout << "\nCong ma tran:\n";
    c = a+b;
    cout << c;
    cout << "\nTru ma tran:\n";
    d = a-b;
    cout << d;
}

