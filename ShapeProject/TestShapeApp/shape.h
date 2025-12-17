#ifndef SHAPE_H
#define SHAPE_H

#include <QString>
#include <QVariant>
#include <QMap>
#include <cmath>

/*!
 * \brief Абстрактный класс для фигур
 */
class Shape
{
public:
    virtual ~Shape() = default;
    virtual QString type() const = 0;
    virtual QMap<QString, QVariant> parameters() const = 0;
    virtual qreal area() const = 0;
};
/*!
 * \brief Класс сущности круг
 */
class Circle : public Shape
{
public:
    explicit Circle(qreal radius);
    QString type() const override;
    QMap<QString, QVariant> parameters() const override;
    qreal area()const override;

private:
    qreal _radius;
};
/*!
 * \brief Класс сущности прямоугольник
 */
class Rectangle : public Shape
{
public:
    explicit Rectangle(qreal height, qreal weight);
    QString type() const override;
    QMap<QString, QVariant> parameters() const override;
    qreal area() const override;

private:
    qreal _height;
    qreal _width;
};


#endif // SHAPE_H
