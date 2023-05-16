#ifndef SOLVE_H               // Директива условной компиляции для предотвращения повторного включения заголовочного файла
#define SOLVE_H

void findEmpty(int grid[9][9]);    // Объявление функции findEmpty для поиска пустой ячейки в сетке судоку

bool isValid(int grid[9][9], int row, int col, int num);    // Объявление функции isValid для проверки, является ли число num допустимым в заданной ячейке сетки

bool solve(int grid[9][9], int arr[]);    // Объявление функции solve для решения судоку

void printGrid(int grid[9][9]);    // Объявление функции printGrid для печати сетки судоку

#endif     // Завершение директивы условной компиляции
