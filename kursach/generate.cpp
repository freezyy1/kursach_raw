#include "generate.h"           // Подключение заголовочного файла generate.h (не предоставлен)
#include <bits/stdc++.h>       // Подключение стандартной библиотеки C++
#include <time.h>               // Подключение заголовочного файла time.h
#include "solve.h"              // Подключение заголовочного файла solve.h (не предоставлен)

using namespace std;            // Использование пространства имен std

void initialiseSudoku(int grid[9][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            grid[i][j] = 0;    // Инициализация всех элементов сетки значением 0
        }
    }
}

void generateRadomGrid(int grid[9][9], int arr[], int level){
    srand(time(0));            // Инициализация генератора случайных чисел на основе текущего времени

    initialiseSudoku(grid);    // Инициализация сетки судоку значением 0 для всех ячеек

    grid[0][0] = ((int)rand() % 9) + 1;     // Заполнение случайной ячейки сетки значениями от 1 до 9
    grid[4][4] = ((int)rand() % 9) + 1;
    grid[8][8] = ((int)rand() % 9) + 1;

    if(solve(grid, arr)){       // Проверка, имеет ли сгенерированная сетка решение с помощью функции solve
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(level == 1){
                    if((int)rand() % 4 == 0){
                        grid[row][col] = 0;    // Установка случайной ячейки в значение 0 с вероятностью 1/4
                    }
                }else if(level == 2){
                    if((int)rand() % 3 == 0){
                        grid[row][col] = 0;    // Установка случайной ячейки в значение 0 с вероятностью 1/3
                    }
                }else{
                    if((int)rand() % 2 == 0){
                        grid[row][col] = 0;    // Установка случайной ячейки в значение 0 с вероятностью 1/2
                    }
                }
            }
        }
    }
}
