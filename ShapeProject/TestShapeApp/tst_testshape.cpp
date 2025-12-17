#include <QtTest>
#include <cmath>
#include "shape.h"
#include "shapelistmodel.h"


class TestShape : public QObject
{
    Q_OBJECT

public:
    TestShape();
    ~TestShape();

private slots:
    void testCircleArea();
    void testRectangleArea();
    void testCircleParameters();
    void testRectangleParameters();
    void testShapeListModel();

};

TestShape::TestShape()
{

}

TestShape::~TestShape()
{

}

void TestShape::testCircleArea()
{
    Circle circle(15.0);
    QCOMPARE(circle.area(), M_PI * 225.0);
}

void TestShape::testRectangleArea()
{
    Rectangle rectangle(8.0, 10.6);
    QCOMPARE(rectangle.area(), 84.8);
}

void TestShape::testCircleParameters()
{
    Circle circle(5.5);
    auto params = circle.parameters();
    QVERIFY(params.contains("Радиус"));
    QCOMPARE(params["Радиус"].toDouble(), 5.5);

}

void TestShape::testRectangleParameters()
{
    Rectangle rectangle(7.0, 6.1);
    auto params = rectangle.parameters();
    QVERIFY(params.contains("Высота"));
    QVERIFY(params.contains("Ширина"));
    QCOMPARE(params["Высота"].toDouble(), 7.0);
    QCOMPARE(params["Ширина"].toDouble(), 6.1);
}

void TestShape::testShapeListModel()
{
    ShapeListModel model;
    QCOMPARE(model.rowCount(),0);

    auto circle = std::make_shared<Circle>(1.0);
    model.addShape(circle);
    QCOMPARE(model.rowCount(),1);

    auto rectangle = std::make_shared<Rectangle>(2.0, 8.6);
    model.addShape(rectangle);
    QCOMPARE(model.rowCount(),2);

    //проверка data()
    QModelIndex index = model.index(0,0);
    QVERIFY(index.isValid());
    QString str = model.data(index, Qt::DisplayRole).toString();
    QVERIFY(str.contains("Круг"));
    QVERIFY(str.contains("Радиус"));

    //проверка getShape()
    auto shape = model.getShape(index);
    QVERIFY(shape != nullptr);
    QCOMPARE(shape->type(), QString("Круг"));
}

QTEST_MAIN(TestShape)

#include "tst_testshape.moc"
