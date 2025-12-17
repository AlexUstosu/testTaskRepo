#ifndef SHAPELISTMODEL_H
#define SHAPELISTMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <memory>
#include "shape.h"
/*!
 * \brief Модель данных для списка фигур по паттерну MV
 */
class ShapeListModel : public QAbstractListModel
{
    Q_OBJECT
private:
    QList<std::shared_ptr<Shape>> shapes;           //список фигур
public:
    explicit ShapeListModel(QObject *parent = nullptr);
    enum Role {
        ShapeRole = Qt::UserRole + 1
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void addShape(std::shared_ptr<Shape> shape);
    std::shared_ptr<Shape> getShape(const QModelIndex &index) const;
};
#endif // SHAPELISTMODEL_H
