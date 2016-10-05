//==================================================================================================
//  File Name:
//      qgraphics_roundwidget.hpp
//
//  Product:
//      BerlinUhr
//
//  Authors:
//      Ian Heaton
//
//==================================================================================================
//
#ifndef QGRAPGICS_ROUNDWIDGET_HPP_DEFINED
#define QGRAPGICS_ROUNDWIDGET_HPP_DEFINED

#include <QGraphicsWidget>
//--------------------------------------------------------------------------------------------------
//  Class:
//      QGraphicsRoundWidget
//
//  Summary:
//      Represent sthe lamp used to display seconds
//
//--------------------------------------------------------------------------------------------------
//
class QGraphicsRoundWidget : public QGraphicsWidget
{
     Q_OBJECT
     Q_PROPERTY(QColor color READ fillColor WRITE setFillColor)

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) Q_DECL_OVERRIDE;
    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    QColor fillColor() const;
    void setFillColor(QColor color);

private:
    QColor mFillColor;

};

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      fillColor()
//
//  Summary:
//      Retrieves the fill color of the seconds lamp instance
//
//  Returns:
//      A QColor instance
//
//--------------------------------------------------------------------------------------------------
//
QColor inline
QGraphicsRoundWidget::fillColor() const
{
    return mFillColor;
}

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      setFillColor()
//
//  Summary:
//      Assigns a color to be used to fill the seconds lamp
//
//
//  Parameters:
//      color -
//          [in] QColor instance
//
//
//--------------------------------------------------------------------------------------------------
//
void inline
QGraphicsRoundWidget::setFillColor(QColor color)
{
    mFillColor = color;
}


#endif //- QGRAPGICS_ROUNDWIDGET_HPP_DEFINED
