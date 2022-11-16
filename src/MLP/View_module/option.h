#ifndef OPTION_H
#define OPTION_H

#include <QWidget>
#include <QFileDialog>
#include <QComboBox>
#include <QSysInfo>
#include <QCoreApplication>
#include <fstream>
#include <string>

using std::ifstream;
using std::string;
using std::getline;

namespace Ui {
class Option;
}

namespace s21 {

enum WeightsMode { RANDOM, FILE };

class Option : public QWidget
{
    Q_OBJECT

public:
    explicit Option(QWidget *parent = nullptr);
    ~Option();
    QComboBox *GetImplementationSwitcher();
    QComboBox *GetLayersSwitcher();
    QString GetConfigPath();
    void ClearConfigPath();

signals:
    void BackSignal();
    void ConfigChosen();

private:
    Ui::Option *ui_;

    void OpenConfigFile();
    void SetSystemInfo();
    void SwitchButtonState(int index);
};

}

#endif // OPTION_H
