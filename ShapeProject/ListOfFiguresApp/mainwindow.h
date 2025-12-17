#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "shape.h"
#include "shapelistmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slotChangeShapeInComboBox(int index);
    void slotAddShape();
    void slotChangeParametresVisionInList(const QModelIndex &current, const QModelIndex &previous);





private:
    Ui::MainWindow *ui;
    ShapeListModel *model;

    void updateAreaLabel(const QModelIndex &index);
};
#endif // MAINWINDOW_H
