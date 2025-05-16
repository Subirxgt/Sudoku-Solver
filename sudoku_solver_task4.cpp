// C++ Program to solve Sudoku problem (with user input)
#include <iostream>
#include <vector>
using namespace std;

// Function to check if it is safe to place num at mat[row][col]
bool isSafe(vector<vector<int>> &mat, int row, int col, int num) {
    for (int x = 0; x <= 8; x++)
        if (mat[row][x] == num || mat[x][col] == num)
            return false;

    int startRow = row - (row % 3), startCol = col - (col % 3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (mat[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Recursive function to solve the Sudoku
bool solveSudokuRec(vector<vector<int>> &mat, int row, int col) {
    int n = mat.size();

    if (row == n - 1 && col == n)
        return true;

    if (col == n) {
        row++;
        col = 0;
    }

    if (mat[row][col] != 0)
        return solveSudokuRec(mat, row, col + 1);

    for (int num = 1; num <= n; num++) {
        if (isSafe(mat, row, col, num)) {
            mat[row][col] = num;
            if (solveSudokuRec(mat, row, col + 1))
                return true;
            mat[row][col] = 0;
        }
    }

    return false;
}

bool solveSudoku(vector<vector<int>> &mat) {
    return solveSudokuRec(mat, 0, 0);
}

// Function to print the Sudoku grid
void printGrid(const vector<vector<int>> &mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat.size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mat(9, vector<int>(9));

    cout << "Enter the Sudoku puzzle (use 0 for empty cells):" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> mat[i][j];
        }
    }

    if (solveSudoku(mat)) {
        cout << "Solved Sudoku puzzle:" << endl;
        printGrid(mat);
    } else {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }

    return 0;
}
