#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new ShapeListModel(this))
{
    ui->setupUi(this);

    //установка значений в combobox
    QStringList typeOfShapesList;
    typeOfShapesList.append("Прямоугольник");
    typeOfShapesList.append("Круг");

    ui->typeShapeComboBox->insertItems(2, typeOfShapesList);

    //усттановка стартовой страницы для параметров
    ui->parametresStackedWidget->setCurrentIndex(0);

    //модель
    ui->shapeListView->setModel(model);

    //connects
    connect(ui->typeShapeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::slotChangeShapeInComboBox);
    connect(ui->addShapePushButton, &QPushButton::clicked, this, &MainWindow::slotAddShape);
    connect(ui->shapeListView->selectionModel(), &QItemSelectionModel::currentChanged,this, &MainWindow::slotChangeParametresVisionInList);
}

MainWindow::~MainWindow()
{

    delete ui;
}
/*!
 * \brief Слот для переключения набора виджетов параметров на форме
 * \param index текущий индекс в combobox
 */
void MainWindow::slotChangeShapeInComboBox(int index)
{
     ui->parametresStackedWidget->setCurrentIndex(index);
}
void MainWindow::slotAddShape()
{
    std::shared_ptr<Shape> currentShape;            //указатель на текущую фигуру

    if (ui->typeShapeComboBox->currentIndex() == 0) // прямоугольник
    {
        //взятие значений с формы
        qreal width = ui->widthDoubleSpinBox->value();
        qreal height = ui->heightDoubleSpinBox->value();

        //при отрицательных или нулевых значений ширины и высоты
        if (width <= 0 || height <= 0)
        {
            QMessageBox::warning(this, "Внимание", "Параметры фигуры имеют некорректные значения!");
            return;
        }
        //
        currentShape = std::make_shared<Rectangle>(height, width);  //вариант безопасной аллокации
    }
    else // круг
    {
        //взятие значения радиуса с формы
        qreal radius = ui->radiusDoubleSpinBox->value();

        //при отрицательных или нулевых значений радиуса
        if (radius <= 0)
        {
            QMessageBox::warning(this, "Внимание", "Радиус не может иметь отрицательное значение!");
            return;
        }
        currentShape = std::make_shared<Circle>(radius);            //вариант безопасной аллокации
    }

    if (currentShape)                   //проверка на успешность создания умного указателя
        model->addShape(currentShape);
}
void MainWindow::slotChangeParametresVisionInList(const QModelIndex &current, const QModelIndex &previous)
{
    //проверка на наличие модели
    if (!current.isValid())
    {
        ui->numberAreaLabel->clear();//очистка лейбла
        return;
    }

    auto shape = model->getShape(current);          //взятие текущей фигуры
    if (shape)
        ui->numberAreaLabel->setText(QString::number(shape->area()));   //установка значений площади
    else
        ui->numberAreaLabel->clear();
}
