QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testshape.cpp \
    shape.cpp \
    shapelistmodel.cpp

HEADERS += \
    shape.h \
    shapelistmodel.h

win32: QMAKE_POST_LINK += windeployqt $$OUT_PWD/$${DESTDIR}release
