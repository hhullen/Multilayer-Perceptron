#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QAbstractButton>
#include <QButtonGroup>
#include <QWidget>

namespace Ui {
class MainMenu;
}

namespace s21 {

class MainMenu : public QWidget {
  Q_OBJECT

 public:
  explicit MainMenu(QWidget *parent = nullptr);
  ~MainMenu();
  QButtonGroup *GetMenuItemsGroup();
  void LockTraining(bool state);
  void LockTesting(bool state);
  void LockClassifier(bool state);
  void LockAll(bool state);

 private:
  Ui::MainMenu *ui_;
};

}  // namespace s21

#endif  // MAIN_MENU_H
