#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <quatnumber.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    quatNumber a, b, res;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_toDecNumberA_clicked();

    void on_toDecNumberB_clicked();

    void on_toDecResult_clicked();

    void on_operationCommit_clicked();

    void on_clear_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
