cmake_minimum_required(VERSION 3.5)

project(MLP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Charts)

set(TS_FILES MLP_en_US.ts)

set(PROJECT_SOURCES
        main.cc
        View_module/mainwindow.cc
        View_module/mainwindow.h
        View_module/mainwindow.ui
        View_module/inputarea.h
        View_module/inputarea.cc
        View_module/classifier.h
        View_module/classifier.cc
        View_module/classifier.ui
        View_module/main_menu.h
        View_module/main_menu.cc
        View_module/main_menu.ui
        View_module/option.h
        View_module/option.cc
        View_module/option.ui
        View_module/testing.h
        View_module/testing.cc
        View_module/testing.ui
        View_module/progressbar.h
        View_module/progressbar.cc
        View_module/progressbar.ui
        View_module/testtablerow.h
        View_module/testtablerow.cc
        View_module/testtablerow.ui
        View_module/training.h
        View_module/training.cc
        View_module/training.ui
        View_module/graph.h
        View_module/graph.cc
        View_module/graph.ui
        View_module/confirmationdialog.h
        View_module/confirmationdialog.cc
        View_module/confirmationdialog.ui

        Model_module/mlp_model.h
        Model_module/mlp_model.cc
        Model_module/matrix_implementation/perceptron.h
        Model_module/matrix_implementation/perceptron.cc
        Model_module/matrix_implementation/perceptron_layer.h

        include/matrix/matrix.h
        include/matrix/matrix.cc
        Controller_module/mlp_controller.h
        Controller_module/mlp_controller.cc

        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MLP
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MLP APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(MLP SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MLP
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(MLP PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(MLP PRIVATE Qt6::Gui)
target_link_libraries(MLP PRIVATE Qt6::Charts)

set_target_properties(MLP PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MLP)
endif()
