#include "shape.h"

Circle::Circle(qreal radius): _radius(radius){}
/*!
 * \brief Метод возврата типа фигуры
 * \return строка с типом
 */
QString Circle::type() const {return "Круг";}
/*!
 * \brief Установка параметра радиуса
 * \return параметры
 */
QMap<QString, QVariant> Circle::parameters() const
{
    QMap<QString, QVariant> params;
    params["Радиус"] = QVariant(_radius);
    return params;
}
/*!
 * \brief Расчёт площади круга
 * \return площадь круга
 */
qreal Circle::area() const
{
    return M_PI * _radius * _radius;
}
//---------------------------------------------------------------------------------------
Rectangle::Rectangle(qreal height, qreal weight): _height(height), _width(weight){}
/*!
 * \brief Метод возврата типа фигуры
 * \return строка с типом
 */
QString Rectangle::type() const {return "Прямоугольник";}
/*!
 * \brief Установка параметров ширины и длины
 * \return параметры
 */
QMap<QString, QVariant> Rectangle::parameters() const
{
    QMap<QString, QVariant> params;
    params["Высота"] = QVariant(_height);
    params["Ширина"] = QVariant(_width);
    return params;
}
/*!
 * \brief Расчёт площади прямоугольника
 * \return площадь прямоугольника
 */
qreal Rectangle::area() const
{
    return _width * _height;
}
