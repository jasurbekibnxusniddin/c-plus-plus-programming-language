#include <iostream>


int main() {
    int rows, columns;

    std::cout << "rows = ";
    std::cin >> rows;

    std::cout << "columns = ";
    std::cin >> columns;

    int matrix[rows][columns];
    
    for (int i = 0; i < rows; i++) {
       for (int j = 0; j < columns; j++) {
          matrix[i][j] = 1;  
       }
    }

    for (int i = 0; i < rows; i++) {
       for (int j = 0; j < columns; j++) {
        // if (j == 0 || j == columns - 1 || (i == j && j <= columns / 2) || (i + j == columns - 1 && j >= columns / 2)) { // M
        if (j == 0 || j == columns - 1 || i == rows / 2) { // H
                std::cout << "*";
            } else {
                std::cout << " ";  
            }
       }
       std::cout << std::endl;  
    }

    return 0;
}

// int main() {
//     // int rows, columns;

//     // std::cout << "rows = ";
//     // std::cin >> rows;

//     // std::cout << "columns = ";
//     // std::cin >> columns;

//     // int matrix[rows][columns];
//     // for (int i = 0; i < rows; i++) {
//     //    for (int j = 0; j < columns; j++) {
//     //       printf("[%d][%d] = ", i, j);
//     //       std::cin >> matrix[i][j];
//     //    }
//     // }

//     // for (int i = 0; i < rows; i++) {
//     //    for (int j = 0; j < columns; j++) {
//     //       std::cout << matrix[i][j] << " ";
//     //    }
//     //    std::cout << std::endl;
//     // }
//     return 0;
// }

