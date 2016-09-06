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
#include <vector>


namespace Ui {
class MainWindow;
}


class QAction;
class QGraphicsScene;
class QGraphicsRectWidget;
class QGraphicsRoundWidget;
class QGraphicsLinearLayout;
class QGraphicsGridLayout;

//--------------------------------------------------------------------------------------------------
//  Class:
//      MainWindow
//
//  Summary:
//      Holds the graphics scene housing the Mengenlehreclock
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
    using RectContainer = std::vector<QGraphicsRectWidget*>;

    Ui::MainWindow        *ui;
    QGraphicsScene        *mpScene;
    QAction               *mpExitAct;
    RectContainer         mFiveHourLamps;
    RectContainer         mOneHourLamps;
    RectContainer         mFiveMinuteLamps;
    RectContainer         mOneMinuteLamps;
    QGraphicsRoundWidget* mpSecondsLamp;

    QGraphicsGridLayout   *mpContainerLayout;
    QGraphicsLinearLayout *mpSecondsLayout;
    QGraphicsLinearLayout *mpFiveHourLayout;
    QGraphicsLinearLayout *mpOneHourLayout;
    QGraphicsLinearLayout *mpFiveMinuteLayout;
    QGraphicsLinearLayout *mpOneMinuteLayout;

    void CreateActions();
    void CreateMenus();
    void CreateLamps();
    void CreateSceneLayout();

};

#endif // MAINWINDOW_HPP_DEFINED
