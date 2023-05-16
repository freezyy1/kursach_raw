#include "solve.h"
#include<bits/stdc++.h>

void findEmpty(int grid[9][9], int arr[]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(grid[i][j] == 0){
                arr[0] = i;
                arr[1] = j;
            }
        }
    }
}

// Проверяет, является ли заданное число допустимым для данной ячейки в судоку
bool isValid(int grid[9][9], int row, int col, int num){
    // Проверка наличия дубликатов в строке
    for(int i = 0; i < 9; i++){
        if(grid[row][i] == num && col != i){
            return false;
        }
    }

    // Проверка наличия дубликатов в столбце
    for(int i = 0; i < 9; i++){
        if(grid[i][col] == num && row != i){
            return false;
        }
    }

    // Проверка наличия дубликатов в квадрате 3x3
    int xCord = (row / 3) * 3;
    int yCord = (col / 3) * 3;
    for (int i = xCord; i < xCord + 3; i++){
        for(int j = yCord; j < yCord + 3; j++){
            if((grid[i][j] == num) && (i != row && j != col)){
                return false;
            }
        }
    }

    return true;
}

// Решает головоломку судоку с помощью вышеупомянутых функций
bool solve(int grid[9][9], int arr[]){
    arr[0] = -1;
    arr[1] = -1;
    findEmpty(grid, arr);

    // Если нет пустых ячеек, то головоломка решена
    if(arr[0] == -1){
        return true;
    }

    int row = arr[0];
    int col = arr[1];
    for(int i = 1; i < 10; i++){
        if (isValid(grid, row, col, i)){
            // Помещаем число в пустую ячейку
            grid[row][col] = i;

            // Рекурсивно вызываем solve для следующей пустой ячейки
            if (solve(grid, arr)){
                return true;
            }

            // Если solve вернул false, то отменяем выбор текущего числа и продолжаем поиск
            grid[row][col] = 0;
        }
    }

    // Если не найдено ни одного допустимого числа, возвращаем false
    return false;
}
