//==================================================================================================
//  File Name:
//      mainwindow.hpp
//
//  Product:
//      BerlinUhr
//
//
//  Authors:
//      Ian Heaton
//
//==================================================================================================
//
#ifndef MAINWINDOW_HPP_DEFINED
#define MAINWINDOW_HPP_DEFINED

#include <QWidget>
#include <vector>


class QAction;
class QGraphicsView;
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
//--------------------------------------------------------------------------------------------------
//
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QSize sizeHint() const Q_DECL_OVERRIDE;

protected:
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void UpdateClock();


private:
    using RectContainer = std::vector<QGraphicsRectWidget*>;

    QGraphicsView        *mpGraphicsView;
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
    QGraphicsLinearLayout *mpTopLevelLayout;


    QTimer    *mpTimer;
    QPoint     mDragPosition;

    void CreateActions();
    void CreateLamps();
    void CreateSceneLayout();

};

#endif // MAINWINDOW_HPP_DEFINED
