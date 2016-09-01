//==================================================================================================
//  File Name:
//      qgraphics_rectwidget.hpp
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
#ifndef QGRAPGICS_RECTWIDGET_HPP_DEFINED
#define QGRAPGICS_RECTWIDGET_HPP_DEFINED

#include <QGraphicsWidget>
//--------------------------------------------------------------------------------------------------
//  Class:
//      CLASS_NAME
//
//  Summary:
//      Does ...
//
//  C++ Syntax:
//      <code><![CDATA[
//      {Optional...}
//      ]]></code>
//
//  Remarks:
//      {Optional...}
//
//  See Also:
//      {Optional...}
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

QColor inline
QGraphicsRectWidget::fillColor() const
{
    return mFillColor;
}

void inline
QGraphicsRectWidget::setFillColor(QColor color)
{
    mFillColor = color;
}


#endif //- QGRAPGICS_RECTWIDGET_HPP_DEFINED
