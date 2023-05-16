#include "mainwindow.h"  // Подключение заголовочного файла для класса MainWindow

#include <QApplication>  // Подключение класса QApplication
#include <QDebug>       // Подключение функции qDebug() для отладки

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // Создание объекта QApplication

    MainWindow w;  // Создание экземпляра класса MainWindow

    w.show();  // Отображение главного окна

    return a.exec();  // Запуск цикла обработки событий и ожидание завершения программы
}
