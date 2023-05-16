#ifndef MAINWINDOW_H             // Директива условной компиляции для предотвращения повторного включения заголовочного файла
#define MAINWINDOW_H

#include <QMainWindow>          // Подключение заголовочного файла QMainWindow из Qt

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }    // Объявление пространства имен Ui и класса MainWindow в нем
QT_END_NAMESPACE

class MainWindow : public QMainWindow    // Определение класса MainWindow как подкласса класса QMainWindow
{
    Q_OBJECT    // Макрос Q_OBJECT для поддержки механизма сигналов и слотов

public:
    MainWindow(QWidget *parent = nullptr);    // Конструктор класса MainWindow
    ~MainWindow();                            // Деструктор класса MainWindow

private slots:    // Объявление слотов (функций), которые могут быть связаны с сигналами (событиями) в интерфейсе пользователя
    void on_pushButton_clicked();       // Слот для обработки нажатия на кнопку с именем "pushButton"
    void on_pushButton_2_clicked();     // Слот для обработки нажатия на кнопку с именем "pushButton_2"
    void on_pushButton_3_clicked();     // Слот для обработки нажатия на кнопку с именем "pushButton_3"
    void on_pushButton_5_clicked();     // Слот для обработки нажатия на кнопку с именем "pushButton_5"
    void on_pushButton_4_clicked();     // Слот для обработки нажатия на кнопку с именем "pushButton_4"
    void on_pushButton_6_clicked();     // Слот для обработки нажатия на кнопку с именем "pushButton_6"
    void on_pushButton_7_clicked();     // Слот для обработки нажатия на кнопку с именем "pushButton_7"

private:
    Ui::MainWindow *ui;    // Указатель на объект класса Ui::MainWindow, который представляет графический интерфейс пользователя
};
#endif // MAINWINDOW_H             // Завершение директивы условной компиляции
