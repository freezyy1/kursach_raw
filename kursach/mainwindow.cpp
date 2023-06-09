#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<bits/stdc++.h>
#include "generate.h"
#include "solve.h"
#include <QMessageBox>


using namespace std;


int arr[2];
int grid[9][9];

QLineEdit* list[81];


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//Начать новую игру
void MainWindow::on_pushButton_2_clicked()
{
    if(!ui->Easy->isChecked() && !ui->Medium->isChecked() && !ui->Hard->isChecked()){
        QMessageBox::information(this, "Выберите сложность", "Пожалуйста, выберите одну из следующих сложностей - легкая, средняя или сложная");
        return;
    }else if(ui->Easy->isChecked()){
        generateRadomGrid(grid, arr, 1);
    }else if(ui->Medium->isChecked()){
        generateRadomGrid(grid, arr, 2);
    }else if(ui->Hard->isChecked()){
        generateRadomGrid(grid, arr, 3);
    }

    QLineEdit* list[81] = {ui->lineEdit_00, ui->lineEdit_01, ui->lineEdit_02, ui->lineEdit_03, ui->lineEdit_04, ui->lineEdit_05, ui->lineEdit_06, ui->lineEdit_07, ui->lineEdit_08,
                           ui->lineEdit_10, ui->lineEdit_11, ui->lineEdit_12, ui->lineEdit_13, ui->lineEdit_14, ui->lineEdit_15, ui->lineEdit_16, ui->lineEdit_17, ui->lineEdit_18,
                           ui->lineEdit_20, ui->lineEdit_21, ui->lineEdit_22, ui->lineEdit_23, ui->lineEdit_24, ui->lineEdit_25, ui->lineEdit_26, ui->lineEdit_27, ui->lineEdit_28,
                           ui->lineEdit_30, ui->lineEdit_31, ui->lineEdit_32, ui->lineEdit_33, ui->lineEdit_34, ui->lineEdit_35, ui->lineEdit_36, ui->lineEdit_37, ui->lineEdit_38,
                           ui->lineEdit_40, ui->lineEdit_41, ui->lineEdit_42, ui->lineEdit_43, ui->lineEdit_44, ui->lineEdit_45, ui->lineEdit_46, ui->lineEdit_47, ui->lineEdit_48,
                           ui->lineEdit_50, ui->lineEdit_51, ui->lineEdit_52, ui->lineEdit_53, ui->lineEdit_54, ui->lineEdit_55, ui->lineEdit_56, ui->lineEdit_57, ui->lineEdit_58,
                           ui->lineEdit_60, ui->lineEdit_61, ui->lineEdit_62, ui->lineEdit_63, ui->lineEdit_64, ui->lineEdit_65, ui->lineEdit_66, ui->lineEdit_67, ui->lineEdit_68,
                           ui->lineEdit_70, ui->lineEdit_71, ui->lineEdit_72, ui->lineEdit_73, ui->lineEdit_74, ui->lineEdit_75, ui->lineEdit_76, ui->lineEdit_77, ui->lineEdit_78,
                           ui->lineEdit_80, ui->lineEdit_81, ui->lineEdit_82, ui->lineEdit_83, ui->lineEdit_84, ui->lineEdit_85, ui->lineEdit_86, ui->lineEdit_87, ui->lineEdit_88};

    int index = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            index = 10 * i + j - i;
            list[index]->setText("");
        }
    }

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(grid[i][j] == 0){
                continue;
            }else{
                index = 10 * i + j - i;
                QString q = QString::fromStdString(to_string(grid[i][j]));
                list[index]->setText(q);
                list[index]->setReadOnly(true);
            }
        }
    }
}





// Убрать решение
void MainWindow::on_pushButton_clicked()
{
    QLineEdit* list[81] = {ui->lineEdit_00, ui->lineEdit_01, ui->lineEdit_02, ui->lineEdit_03, ui->lineEdit_04, ui->lineEdit_05, ui->lineEdit_06, ui->lineEdit_07, ui->lineEdit_08,
                           ui->lineEdit_10, ui->lineEdit_11, ui->lineEdit_12, ui->lineEdit_13, ui->lineEdit_14, ui->lineEdit_15, ui->lineEdit_16, ui->lineEdit_17, ui->lineEdit_18,
                           ui->lineEdit_20, ui->lineEdit_21, ui->lineEdit_22, ui->lineEdit_23, ui->lineEdit_24, ui->lineEdit_25, ui->lineEdit_26, ui->lineEdit_27, ui->lineEdit_28,
                           ui->lineEdit_30, ui->lineEdit_31, ui->lineEdit_32, ui->lineEdit_33, ui->lineEdit_34, ui->lineEdit_35, ui->lineEdit_36, ui->lineEdit_37, ui->lineEdit_38,
                           ui->lineEdit_40, ui->lineEdit_41, ui->lineEdit_42, ui->lineEdit_43, ui->lineEdit_44, ui->lineEdit_45, ui->lineEdit_46, ui->lineEdit_47, ui->lineEdit_48,
                           ui->lineEdit_50, ui->lineEdit_51, ui->lineEdit_52, ui->lineEdit_53, ui->lineEdit_54, ui->lineEdit_55, ui->lineEdit_56, ui->lineEdit_57, ui->lineEdit_58,
                           ui->lineEdit_60, ui->lineEdit_61, ui->lineEdit_62, ui->lineEdit_63, ui->lineEdit_64, ui->lineEdit_65, ui->lineEdit_66, ui->lineEdit_67, ui->lineEdit_68,
                           ui->lineEdit_70, ui->lineEdit_71, ui->lineEdit_72, ui->lineEdit_73, ui->lineEdit_74, ui->lineEdit_75, ui->lineEdit_76, ui->lineEdit_77, ui->lineEdit_78,
                           ui->lineEdit_80, ui->lineEdit_81, ui->lineEdit_82, ui->lineEdit_83, ui->lineEdit_84, ui->lineEdit_85, ui->lineEdit_86, ui->lineEdit_87, ui->lineEdit_88};

    int index = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(grid[i][j] == 0){
                index = 10 * i + j - i;
                list[index]->setText("");
            }else{
                index = 10 * i + j - i;
                QString q = QString::fromStdString(to_string(grid[i][j]));
                list[index]->setText(q);
            }
        }
    }
}



//подсмотреть решение
void MainWindow::on_pushButton_3_clicked()
{
    int a[2];

    int solution[9][9];

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            solution[i][j] = grid[i][j];
        }
    }


    solve(solution, a);

    QLineEdit* list[81] = {ui->lineEdit_00, ui->lineEdit_01, ui->lineEdit_02, ui->lineEdit_03, ui->lineEdit_04, ui->lineEdit_05, ui->lineEdit_06, ui->lineEdit_07, ui->lineEdit_08,
                           ui->lineEdit_10, ui->lineEdit_11, ui->lineEdit_12, ui->lineEdit_13, ui->lineEdit_14, ui->lineEdit_15, ui->lineEdit_16, ui->lineEdit_17, ui->lineEdit_18,
                           ui->lineEdit_20, ui->lineEdit_21, ui->lineEdit_22, ui->lineEdit_23, ui->lineEdit_24, ui->lineEdit_25, ui->lineEdit_26, ui->lineEdit_27, ui->lineEdit_28,
                           ui->lineEdit_30, ui->lineEdit_31, ui->lineEdit_32, ui->lineEdit_33, ui->lineEdit_34, ui->lineEdit_35, ui->lineEdit_36, ui->lineEdit_37, ui->lineEdit_38,
                           ui->lineEdit_40, ui->lineEdit_41, ui->lineEdit_42, ui->lineEdit_43, ui->lineEdit_44, ui->lineEdit_45, ui->lineEdit_46, ui->lineEdit_47, ui->lineEdit_48,
                           ui->lineEdit_50, ui->lineEdit_51, ui->lineEdit_52, ui->lineEdit_53, ui->lineEdit_54, ui->lineEdit_55, ui->lineEdit_56, ui->lineEdit_57, ui->lineEdit_58,
                           ui->lineEdit_60, ui->lineEdit_61, ui->lineEdit_62, ui->lineEdit_63, ui->lineEdit_64, ui->lineEdit_65, ui->lineEdit_66, ui->lineEdit_67, ui->lineEdit_68,
                           ui->lineEdit_70, ui->lineEdit_71, ui->lineEdit_72, ui->lineEdit_73, ui->lineEdit_74, ui->lineEdit_75, ui->lineEdit_76, ui->lineEdit_77, ui->lineEdit_78,
                           ui->lineEdit_80, ui->lineEdit_81, ui->lineEdit_82, ui->lineEdit_83, ui->lineEdit_84, ui->lineEdit_85, ui->lineEdit_86, ui->lineEdit_87, ui->lineEdit_88};


    int index = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            index = 10 * i + j - i;
            QString q = QString::fromStdString(to_string(solution[i][j]));
            list[index]->setText(q);
        }
    }
}


//посмотреть решение
void MainWindow::on_pushButton_5_clicked()
{
    QLineEdit* list[81] = {ui->lineEdit_00, ui->lineEdit_01, ui->lineEdit_02, ui->lineEdit_03, ui->lineEdit_04, ui->lineEdit_05, ui->lineEdit_06, ui->lineEdit_07, ui->lineEdit_08,
                           ui->lineEdit_10, ui->lineEdit_11, ui->lineEdit_12, ui->lineEdit_13, ui->lineEdit_14, ui->lineEdit_15, ui->lineEdit_16, ui->lineEdit_17, ui->lineEdit_18,
                           ui->lineEdit_20, ui->lineEdit_21, ui->lineEdit_22, ui->lineEdit_23, ui->lineEdit_24, ui->lineEdit_25, ui->lineEdit_26, ui->lineEdit_27, ui->lineEdit_28,
                           ui->lineEdit_30, ui->lineEdit_31, ui->lineEdit_32, ui->lineEdit_33, ui->lineEdit_34, ui->lineEdit_35, ui->lineEdit_36, ui->lineEdit_37, ui->lineEdit_38,
                           ui->lineEdit_40, ui->lineEdit_41, ui->lineEdit_42, ui->lineEdit_43, ui->lineEdit_44, ui->lineEdit_45, ui->lineEdit_46, ui->lineEdit_47, ui->lineEdit_48,
                           ui->lineEdit_50, ui->lineEdit_51, ui->lineEdit_52, ui->lineEdit_53, ui->lineEdit_54, ui->lineEdit_55, ui->lineEdit_56, ui->lineEdit_57, ui->lineEdit_58,
                           ui->lineEdit_60, ui->lineEdit_61, ui->lineEdit_62, ui->lineEdit_63, ui->lineEdit_64, ui->lineEdit_65, ui->lineEdit_66, ui->lineEdit_67, ui->lineEdit_68,
                           ui->lineEdit_70, ui->lineEdit_71, ui->lineEdit_72, ui->lineEdit_73, ui->lineEdit_74, ui->lineEdit_75, ui->lineEdit_76, ui->lineEdit_77, ui->lineEdit_78,
                           ui->lineEdit_80, ui->lineEdit_81, ui->lineEdit_82, ui->lineEdit_83, ui->lineEdit_84, ui->lineEdit_85, ui->lineEdit_86, ui->lineEdit_87, ui->lineEdit_88};

    int userAnswer[9][9];

    int index = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            index = 10 * i + j - i;
            userAnswer[i][j] = list[index]->text().toInt();
         }
     }


    int solution[9][9];

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            solution[i][j] = grid[i][j];
        }
    }

    int a[2];
    solve(solution, a);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(solution[i][j] != userAnswer[i][j]){
                QMessageBox::warning(this, "Проверить", "Ваш ответ неверный!");
                return;
            }
        }
    }

    QMessageBox::information(this, "Проверить", "Ваш ответ неверный!");
}



//Инструкции
void MainWindow::on_pushButton_4_clicked()
{
    QString msg = "Добро пожаловать в эту простую игру Судоку!\n";
    msg += "Для начала игры выберите уровень сложности и нажмите кнопку «Начать новую игру». \n";
    msg += "Чтобы сбросить сетку текущей игры, нажмите кнопку «Сбросить сетку». \n";
    msg += "Чтобы проверить свой ответ, нажмите кнопку «Проверить». \n";
    msg += "Чтобы увидеть решение, нажмите кнопку «Посмотреть решение». \n";
    msg += "Приятной игры!";
    QMessageBox::information(this, "Инструкции по игре", msg);
}

//О программе
void MainWindow::on_pushButton_6_clicked()
{
    QString msg = "Добро пожаловать в эту простую игру Судоку!\n";
    msg += "Эта игра разработана на C++ с использованием инструментария QT для разработки графического интерфейса. \n";
    msg += "Сделано Сатюковым Дмитрием.";
    QMessageBox::information(this, "О программе", msg);
}


//О программе
void MainWindow::on_pushButton_7_clicked()
{
    QString msg = "https://github.com/freezyy1";
    QMessageBox::information(this, "Github", msg);
}
