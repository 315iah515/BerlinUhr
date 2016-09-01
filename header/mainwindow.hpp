//==================================================================================================
//  File Name:
//      mainwindow.hpp
//
//  Product:
//      BerlinUhr
//
//  Interface Header:
//
//
//  Authors:
//      Ian Heaton
//
//  Copyright Notice:
//
//==================================================================================================
//
#ifndef MAINWINDOW_HPP_DEFINED
#define MAINWINDOW_HPP_DEFINED

#include <QMainWindow>

namespace Ui {
class MainWindow;
}


class QAction;
class QGraphicsScene;

//--------------------------------------------------------------------------------------------------
//  Class:
//      CLASS_NAME
//
//  Summary:
//      Does ...
//
//
//  Remarks:
//      {Optional...}
//
//  See Also:
//      {Optional...}
//--------------------------------------------------------------------------------------------------
//
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


private:
    Ui::MainWindow *ui;
    QGraphicsScene *mpScene;
    QAction *mpExitAct;

    void CreateActions();
    void CreateMenus();
    void DrawLights();

};

#endif // MAINWINDOW_HPP_DEFINED
