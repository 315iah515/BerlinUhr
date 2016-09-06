//==================================================================================================
//  File Name:
//      qgraphics_roundwidget.hpp
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
#ifndef QGRAPGICS_ROUNDWIDGET_HPP_DEFINED
#define QGRAPGICS_ROUNDWIDGET_HPP_DEFINED

#include <QGraphicsWidget>
//--------------------------------------------------------------------------------------------------
//  Class:
//      QGraphicsRoundWidget
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

QColor inline
QGraphicsRoundWidget::fillColor() const
{
    return mFillColor;
}

void inline
QGraphicsRoundWidget::setFillColor(QColor color)
{
    mFillColor = color;
}


#endif //- QGRAPGICS_ROUNDWIDGET_HPP_DEFINED
