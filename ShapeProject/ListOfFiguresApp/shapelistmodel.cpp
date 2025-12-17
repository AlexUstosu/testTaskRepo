#include "shapelistmodel.h"

ShapeListModel::ShapeListModel(QObject *parent) : QAbstractListModel(parent) {}

/*!
 * \brief Перегруженный метод для количества фигур в модели
 * \param parent ссылка на родителя
 * \return количество элементов
 */
int ShapeListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return shapes.size();
}
/*!
 * \brief Перегруженный метод для возвращения данных для указанной ячейки
 * \param index порядковый номер ячейки
 * \param role роль, для чего используется
 * \return параметры фигуры
 */
QVariant ShapeListModel::data(const QModelIndex &index, int role) const
{
    // при наличии объекта и если его значение не превышает размера контейнера
    if (!index.isValid() || index.row() >= shapes.size())
        return QVariant();

    // взятие текущей фигуры из списка
    auto shape = shapes.at(index.row());

    // при отображении информации об объекте
    if(role == Qt::DisplayRole)
    {
        QStringList paramStrs;
        auto params = shape->parameters();                                      //сохраняем текущую ссылку
        for (auto i = params.begin(); i != params.end(); ++i)                   //используем итераторы
            paramStrs << i.key() + "=" + QString::number(i.value().toDouble()); //ищем значение
        return shape->type() + "[" + paramStrs.join(", ") + "]";                //склеиваем в строку через запятую
    }
    return QVariant();
}
/*!
 * \brief Метод для добавления новых фигур в коллекцию
 * \param shape фигура
 */
void ShapeListModel::addShape(std::shared_ptr<Shape> shape)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());             //добавление в модель
    shapes.append(shape);                                               //добавление в контейнер
    endInsertRows();                                                    //базофвый метод для завершения добавления в модель
}
/*!
 * \brief Возврат фигуры
 * \param index номер ячейки
 * \return фигура
 */
std::shared_ptr<Shape> ShapeListModel::getShape(const QModelIndex &index) const
{
    // при наличии объекта и если его значение не превышает размера контейнера
    if (index.isValid() && index.row() < shapes.size())
        return shapes.at(index.row());

    return nullptr;
}
