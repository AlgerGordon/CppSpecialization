//
// Created by General on 31.05.2020.
//

#include <iostream>
#include <vector>
#include <exception>

using namespace std;


class Matrix {
public:
    Matrix() {
        num_rows = 0;
        num_cols = 0;
    }
    Matrix(int new_num_rows, int new_num_cols) {
        if (new_num_rows < 0 || new_num_cols < 0){
            throw out_of_range("Incorrect size of matrix");
        }
        num_rows = new_num_cols == 0 ? 0: new_num_rows;
        num_cols = new_num_rows == 0 ? 0 : new_num_cols;
        matrix.resize(new_num_rows, vector<int>(new_num_cols, 0));
    }
    void Reset(int new_num_rows, int new_num_cols) {
        if (new_num_rows < 0 || new_num_cols < 0){
            throw out_of_range("Incorrect size of matrix");
        }
        num_rows = new_num_cols == 0 ? 0: new_num_rows;
        num_cols = new_num_rows == 0 ? 0 : new_num_cols;
        matrix.resize(new_num_rows, vector<int>(new_num_cols, 0));
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
               matrix[i][j] = 0;
            }
        }
    }
    int At(int row, int col) const{
        if (row < 0 || col < 0 || row > (num_rows - 1) || col > (num_cols - 1)){
            throw out_of_range("Out of range im matrix");
        }
        return matrix[row][col];
    }
    int& At(int row, int col){
        if (row < 0 || col < 0 || row > (num_rows - 1) || col > (num_cols - 1)){
            throw out_of_range("Out of range im matrix");
        }
        return matrix[row][col];
    }
    int GetNumRows() const{
        return num_rows;
    }
    int GetNumColumns() const{
        return num_cols;
    };
private:
    int num_rows, num_cols;
    vector<vector<int>> matrix;
};


istream& operator>> (istream& stream, Matrix& matrix) {
    int new_num_rows, new_num_cols;
    stream >> new_num_rows >> new_num_cols;
    matrix.Reset(new_num_rows,new_num_cols);
    for (int i = 0; i < new_num_rows; ++i ){
        for (int j = 0; j < new_num_cols; ++j ){
            stream >> matrix.At(i,j);
        }
    }
    return stream;
}

ostream& operator<< (ostream& stream, const Matrix& matrix) {
    int num_rows = matrix.GetNumRows();
    int num_cols = matrix.GetNumColumns();
    stream << num_rows << " " << num_cols << endl;
    for (int i = 0; i < num_rows; ++i ){
        for (int j = 0; j < num_cols; ++j ){
            stream << matrix.At(i,j) << " ";
        }
        stream << endl;
    }
    return stream;
}

bool operator== (const Matrix& lhs, const Matrix& rhs) {
    if (rhs.GetNumColumns() != lhs.GetNumColumns() || rhs.GetNumRows() != lhs.GetNumRows()){
        return false;
    }
    int num_rows = rhs.GetNumRows();
    int num_cols = lhs.GetNumColumns();
    for (int i = 0; i < num_rows; ++i ){
        for (int j = 0; j < num_cols; ++j ){
            if (lhs.At(i,j) != rhs.At(i,j)){
                return false;
            }
        }
    }
    return true;
}
Matrix operator+ (const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns()) {
        throw invalid_argument("Matrix dimensions must agree!");
    }
    int num_rows = rhs.GetNumRows();
    int num_cols = lhs.GetNumColumns();
    Matrix matrix(num_rows, num_cols);
    for (int i = 0; i < num_rows; ++i ){
        for (int j = 0; j < num_cols; ++j ){
           matrix.At(i,j) = lhs.At(i,j) + rhs.At(i,j);
        }
    }
    return matrix;
}

int main() {

    Matrix one(0,2), two(0,3);
    cout << one + two << endl;

    return 0;
}