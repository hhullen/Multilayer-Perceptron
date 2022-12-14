#include "main_menu.h"

#include "ui_main_menu.h"

namespace s21 {

MainMenu::MainMenu(QWidget *parent) : QWidget(parent), ui_(new Ui::MainMenu) {
  ui_->setupUi(this);
}

MainMenu::~MainMenu() {
  if (ui_) delete ui_;
  ui_ = nullptr;
}

QButtonGroup *MainMenu::GetMenuItemsGroup() { return ui_->group_btns; }

void MainMenu::LockTraining(bool state) {
  ui_->btn_learning->setDisabled(state);
}

void MainMenu::LockTesting(bool state) { ui_->btn_testing->setDisabled(state); }

void MainMenu::LockClassifier(bool state) {
  ui_->btn_classifying->setDisabled(state);
}

void MainMenu::LockAll(bool state) {
  LockTraining(state);
  LockTesting(state);
  LockClassifier(state);
}

}  // namespace s21
