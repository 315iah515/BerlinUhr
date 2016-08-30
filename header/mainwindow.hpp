#ifndef MAINWINDOW_HPP_DEFINED
#define MAINWINDOW_HPP_DEFINED

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


private:
    Ui::MainWindow *ui;
    QAction *mpExitAct;

    void CreateActions();
    void CreateMenus();

};

#endif // MAINWINDOW_HPP_DEFINED
