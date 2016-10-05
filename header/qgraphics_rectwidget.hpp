//==================================================================================================
//  File Name:
//      qgraphics_rectwidget.hpp
//
//  Product:
//      BerlinUhr
//
//  Authors:
//      Ian Heaton
//
//==================================================================================================
//
#ifndef QGRAPGICS_RECTWIDGET_HPP_DEFINED
#define QGRAPGICS_RECTWIDGET_HPP_DEFINED

#include <QGraphicsWidget>
//--------------------------------------------------------------------------------------------------
//  Class:
//      QGraphicsRectWidget
//
//  Summary:
//      Represents a single lamp that is either in the On or Off state.
//
//
//--------------------------------------------------------------------------------------------------
//
class QGraphicsRectWidget : public QGraphicsWidget
{
     Q_OBJECT
     Q_PROPERTY(QColor color READ fillColor WRITE setFillColor)

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) Q_DECL_OVERRIDE;
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
//      Retrieves the fill color of a lamp instance
//
//  Returns:
//      A QColor instance
//
//--------------------------------------------------------------------------------------------------
//
QColor inline
QGraphicsRectWidget::fillColor() const
{
    return mFillColor;
}

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      setFillColor()
//
//  Summary:
//      Assigns a color to be used to fill the lamp
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
QGraphicsRectWidget::setFillColor(QColor color)
{
    mFillColor = color;
}


#endif //- QGRAPGICS_RECTWIDGET_HPP_DEFINED
