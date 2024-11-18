// avtor: Jasurbek Shamsitdinov
// maqsad: matrix orqali ismni chop etish
// sana: 16.10.2024

#include <iostream>

void InitializeMatrix(int rows, int columns, char matrix[7][7], char fill = ' ') {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = fill;
        }
    }
}

void PrintMatrix(int rows, int columns, char matrix[7][7]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void CreateJLetter(int rows, int columns, char matrix[7][7]) {
    InitializeMatrix(rows, columns, matrix);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == 0 || (i == rows - 1 && j > 0 && j < columns - 1) || 
                (j == columns - 1 && i < rows - 1) || (i > rows / 2 && j == 0)) {
                matrix[i][j] = '*';
            }
        }
    }
}

void CreateALetter(int rows, int columns, char matrix[7][7]) {
    InitializeMatrix(rows, columns, matrix);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if ((i == 0 && j > 0 && j < columns - 1) || 
                (j == 0 || j == columns - 1) || 
                (i == rows / 2 && j > 0 && j < columns - 1)) {
                matrix[i][j] = '*';
            }
        }
    }
}

void CreateSLetter(int rows, int columns, char matrix[7][7]) {
    InitializeMatrix(rows, columns, matrix);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == 0 || i == rows / 2 || i == rows - 1 || 
                (i < rows / 2 && j == 0) || 
                (i > rows / 2 && j == columns - 1)) {
                matrix[i][j] = '*';
            }
        }
    }
}

void CreateULetter(int rows, int columns, char matrix[7][7]) {
    InitializeMatrix(rows, columns, matrix);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if ((j == 0 || j == columns - 1) && i < rows - 1) {
                matrix[i][j] = '*';
            } else if (i == rows - 1 && j > 0 && j < columns - 1) {
                matrix[i][j] = '*';
            }
        }
    }
}

void CreateRLetter(int rows, int columns, char matrix[7][7]) {
    InitializeMatrix(rows, columns, matrix);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (j == 0 || (i == 0 && j < columns - 1) || 
                (i == rows / 2 && j < columns - 1) || 
                (j == columns - 1 && i > 0 && i < rows / 2) || 
                (i > rows / 2 && i - j == rows / 2)) {
                matrix[i][j] = '*';
            }
        }
    }
}

int main() {
    const int rows = 7;
    const int columns = 7;
    char matrix[7][7];

    CreateJLetter(rows, columns, matrix);
    PrintMatrix(rows, columns, matrix);
    std::cout << std::endl;

    CreateALetter(rows, columns, matrix);
    PrintMatrix(rows, columns, matrix);
    std::cout << std::endl;

    CreateSLetter(rows, columns, matrix);
    PrintMatrix(rows, columns, matrix);
    std::cout << std::endl;

    CreateULetter(rows, columns, matrix);
    PrintMatrix(rows, columns, matrix);
    std::cout << std::endl;

    CreateRLetter(rows, columns, matrix);
    PrintMatrix(rows, columns, matrix);

    return 0;
}
