#include <iostream>
#include <vector>

class Matrix {
    private:
        std::vector<std::vector<int>> data;
        size_t rows;
        size_t cols;
    public:
        // Constructor
        Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
            data.resize(rows, std::vector<int>(cols, 0)); // Initialize to 0
        }

        // Constructor from 2d vector
        Matrix(std::vector<std::vector<int>> &data) 
            : data(data), rows(data.size()), cols(data[0].size()) {}
        
        // Getters
        size_t getRows() { return rows; }
        size_t getCols() { return cols; }
        size_t getVal(size_t i, size_t j) {
            if (i >= rows || j >= cols) {
                throw std::out_of_range("Index out of range");
            }
            return data[i][j]; 
        }

        // Setters
        void setVal(size_t i, size_t j, int val) { 
            if (i >= rows || j >= cols) {
                throw std::out_of_range("Index out of range");
            }
            data[i][j] = val; 
        }

        // Print Matrix
        void print() {
            for (size_t i = 0; i < rows; i++) {
                std::cout << "[ ";
                for (size_t j = 0; j < cols; j++) {
                    std::cout << data[i][j] << " ";
                }
                std::cout << "]" << std::endl;
            }
        }

        // ===========================================
        // Math
        // ===========================================

        // Matrix Addition
        Matrix operator+(Matrix &m2) const {
            if (rows != m2.getRows() || cols != m2.getCols()) {
                throw std::invalid_argument("Matrix dimensions do not match");
            }

            Matrix sum(rows, cols);

            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    sum.setVal(i, j, data[i][j] + m2.getVal(i, j));
                }
            }

            return sum;
        }
};

int main() {
    std::vector<std::vector<int>> data = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matrix m(data);
    Matrix m2(data);

    Matrix sum = m + m2;

    sum.print();

    return 0;
}