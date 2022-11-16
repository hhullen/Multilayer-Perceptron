#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "View_module/mainwindow.h"

using s21::MainWindow;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  QTranslator translator;
  const QStringList uiLanguages = QLocale::system().uiLanguages();
  for (const QString &locale : uiLanguages) {
    const QString baseName = "MLP_" + QLocale(locale).name();
    if (translator.load(":/i18n/" + baseName)) {
      a.installTranslator(&translator);
      break;
    }
  }
  MLPModel model;
  MLPController controller(&model);
  MainWindow view(&controller);
  view.setWindowTitle("Multilayer perceptron");
  view.show();
  return a.exec();
}
