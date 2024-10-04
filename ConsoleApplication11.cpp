#include <iostream>
#include <vector>

void addColumn(std::vector<std::vector<int>>& matrix, int position, const std::vector<int>& newColumn) {
    if (position < 0 || position > matrix[0].size()) {
        std::cout << "Неправильна позиція для вставки стовпця." << std::endl;
        return;
    }
    for (int i = 0; i < matrix.size(); ++i) {
        matrix[i].insert(matrix[i].begin() + position, newColumn[i]);
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int el : row) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::vector<int> newColumn = { 10, 11, 12 };
    int position = 1;

    std::cout << "Матриця перед додаванням стовпчика:\n";
    printMatrix(matrix);

    addColumn(matrix, position, newColumn);

    std::cout << "Матриця після додавання стовпчика:\n";
    printMatrix(matrix);

    return 0;
}
#include <iostream>
#include <vector>

void removeColumn(std::vector<std::vector<int>>& matrix, int position) {
    if (position < 0 || position >= matrix[0].size()) {
        std::cout << "Неправильний індекс стовпця." << std::endl;
        return;
    }
    for (int i = 0; i < matrix.size(); ++i) {
        matrix[i].erase(matrix[i].begin() + position);
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int el : row) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int columnToRemove = 2;

    std::cout << "Матриця перед видаленням стовпчика:\n";
    printMatrix(matrix);

    removeColumn(matrix, columnToRemove);

    std::cout << "Матриця після видалення стовпчика:\n";
    printMatrix(matrix);

    return 0;
}
#include <iostream>
#include <vector>

void shiftRow(std::vector<std::vector<int>>& matrix, int shiftTimes, bool toRight) {
    int M = matrix.size();
    int N = matrix[0].size();
    shiftTimes %= N;

    for (int i = 0; i < M; ++i) {
        if (toRight) {
            std::rotate(matrix[i].rbegin(), matrix[i].rbegin() + shiftTimes, matrix[i].rend());
        }
        else {
            std::rotate(matrix[i].begin(), matrix[i].begin() + shiftTimes, matrix[i].end());
        }
    }
}

void shiftColumn(std::vector<std::vector<int>>& matrix, int shiftTimes, bool toDown) {
    int M = matrix.size();
    int N = matrix[0].size();
    shiftTimes %= M;

    for (int j = 0; j < N; ++j) {
        std::vector<int> column(M);
        for (int i = 0; i < M; ++i) {
            column[i] = matrix[i][j];
        }

        if (toDown) {
            std::rotate(column.rbegin(), column.rbegin() + shiftTimes, column.rend());
        }
        else {
            std::rotate(column.begin(), column.begin() + shiftTimes, column.end());
        }

        for (int i = 0; i < M; ++i) {
            matrix[i][j] = column[i];
        }
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int el : row) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int shiftTimes;
    bool toRight, toDown;

    std::cout << "Введіть кількість зсувів для рядків: ";
    std::cin >> shiftTimes;
    std::cout << "Зсувати рядки вправо (1) чи вліво (0)? ";
    std::cin >> toRight;
    shiftRow(matrix, shiftTimes, toRight);

    std::cout << "Матриця після зсуву рядків:\n";
    printMatrix(matrix);

    std::cout << "Введіть кількість зсувів для стовпців: ";
    std::cin >> shiftTimes;
    std::cout << "Зсувати стовпці вниз (1) чи вгору (0)? ";
    std::cin >> toDown;
    shiftColumn(matrix, shiftTimes, toDown);

    std::cout << "Матриця після зсуву стовпців:\n";
    printMatrix(matrix);

    return 0;
}
