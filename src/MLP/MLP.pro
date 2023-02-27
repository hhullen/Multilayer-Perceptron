QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS=-finline-functions

INCLUDE_DIR = ../MLP/include
MODEL_DIR = ../MLP/Model_module
VIEW_DIR = ../MLP/View_module
CONTROLLER_DIR = ../MLP/Controller_module

INCLUDEPATH += $$INCLUDE_DIR $$MODEL_DIR $$VIEW_DIR $$CONTROLLER_DIR

ICON = Resources/photosurface.icns

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cc \
    $$VIEW_DIR/mainwindow.cc \
    $$VIEW_DIR/inputarea.cc \
    $$VIEW_DIR/classifier.cc \
    $$VIEW_DIR/main_menu.cc \
    $$VIEW_DIR/option.cc \
    $$VIEW_DIR/testing.cc \
    $$VIEW_DIR/progressbar.cc \
    $$VIEW_DIR/testtablerow.cc \
    $$VIEW_DIR/training.cc \
    $$VIEW_DIR/graph.cc \
    $$VIEW_DIR/confirmationdialog.cc \
    $$MODEL_DIR/mlp_model.cc \
    $$MODEL_DIR/matrix_implementation/perceptron.cc \
    $$MODEL_DIR/graph_implementation/g_perceptron.cc \
    $$CONTROLLER_DIR/mlp_controller.cc \
    $$INCLUDE_DIR/matrix_lib/matrix.cc

HEADERS += \
    $$VIEW_DIR/mainwindow.h \
    $$VIEW_DIR/inputarea.h \
    $$VIEW_DIR/classifier.h \
    $$VIEW_DIR/main_menu.h \
    $$VIEW_DIR/option.h \
    $$VIEW_DIR/testing.h \
    $$VIEW_DIR/progressbar.h \
    $$VIEW_DIR/testtablerow.h \
    $$VIEW_DIR/training.h \
    $$VIEW_DIR/graph.h \
    $$VIEW_DIR/confirmationdialog.h \
    $$MODEL_DIR/mlp_model.h \
    $$MODEL_DIR/matrix_implementation/perceptron.h \
    $$MODEL_DIR/matrix_implementation/perceptron_layer.h \
    $$MODEL_DIR/graph_implementation/g_neuron.h \
    $$MODEL_DIR/graph_implementation/g_perceptron.h \
    $$MODEL_DIR/const.h \
    $$CONTROLLER_DIR/mlp_controller.h \
    $$INCLUDE_DIR/matrix_lib/matrix.h

FORMS += \
    $$VIEW_DIR/mainwindow.ui \
    $$VIEW_DIR/classifier.ui \
    $$VIEW_DIR/main_menu.ui \
    $$VIEW_DIR/option.ui \
    $$VIEW_DIR/testing.ui \
    $$VIEW_DIR/progressbar.ui \
    $$VIEW_DIR/testtablerow.ui \
    $$VIEW_DIR/training.ui \
    $$VIEW_DIR/graph.ui \
    $$VIEW_DIR/confirmationdialog.ui

TRANSLATIONS += \
    MLP_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
