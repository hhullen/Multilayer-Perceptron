#include "main_menu.h"

#include "ui_main_menu.h"

namespace s21 {

MainMenu::MainMenu(QWidget *parent) : QWidget(parent), ui_(new Ui::MainMenu) {
  ui_->setupUi(this);
}

MainMenu::~MainMenu() { delete ui_; }

QButtonGroup *MainMenu::GetMenuItemsGroup() { return ui_->group_btns; }

}  // namespace s21
