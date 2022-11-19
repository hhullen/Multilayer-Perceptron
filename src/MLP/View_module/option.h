#ifndef OPTION_H
#define OPTION_H

#include <QComboBox>
#include <QCoreApplication>
#include <QFileDialog>
#include <QSysInfo>
#include <QWidget>
#include <fstream>
#include <string>

using std::getline;
using std::ifstream;
using std::string;

namespace Ui {
class Option;
}

namespace s21 {

enum class WeightsMode { RANDOM, FILE };

class Option : public QWidget {
  Q_OBJECT

 public:
  explicit Option(QWidget *parent = nullptr);
  ~Option();
  QComboBox *GetImplementationSwitcher();
  QComboBox *GetLayersSwitcher();
  QComboBox *GetWCFGMode();
  QString GetConfigPath();
  void ClearConfigPath();
  void Lock(bool state);

 signals:
  void BackSignal();
  void ConfigChosen();

 private:
  Ui::Option *ui_;
  bool is_locked_;

  void OpenConfigFile();
  void SetSystemInfo();
  void SwitchButtonState(int index);
  void CheckFilePath();
};

}  // namespace s21

#endif  // OPTION_H
