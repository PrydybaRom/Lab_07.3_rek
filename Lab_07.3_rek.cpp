
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

void fillMatrix(int** matrix, int k, int n, int i = 0, int j = 0) {
    if (i < k) {
        if (j < n) {
            matrix[i][j] = rand() % 20;
            fillMatrix(matrix, k, n, i, j + 1);
        }
        else {
            fillMatrix(matrix, k, n, i + 1, 0);
        }
    }
}

int** create(int k, int n) {
    int** matrix = new int* [k];
    for (int i = 0; i < k; ++i) {
        matrix[i] = new int[n];
    }

    srand(time(0));
    fillMatrix(matrix, k, n);

    return matrix;
}

void print(int** matrix, int k, int n, int i = 0, int j = 0) {
    if (i < k) {
        if (j < n) {
            cout << setw(4) << matrix[i][j];
            print(matrix, k, n, i, j + 1);
        }
        else {
            cout << endl;
            print(matrix, k, n, i + 1, 0);
        }
    }
}

int countColumns(int** matrix, int k, int n, int j = 0, int i = 0) {
    if (j < n) {
        if (i < k) {
            if (matrix[i][j] == 0) {
                return countColumns(matrix, k, n, j + 1, 0);
            }
            return countColumns(matrix, k, n, j, i + 1);
        }
        return 1 + countColumns(matrix, k, n, j + 1, 0);
    }
    return 0;
}


int main() {
    int k, n;

    cout << "Enter k: ";
    cin >> k;
    cout << "Enter n: ";
    cin >> n;

    int** matrix = create(k, n);

    print(matrix, k, n);

    int nonZeroColumns = countColumns(matrix, k, n);
    cout << "Count Columns without ZERO: " << nonZeroColumns << endl;

    for (int i = 0; i < k; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
