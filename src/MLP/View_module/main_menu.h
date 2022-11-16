#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QWidget>
#include <QAbstractButton>
#include <QButtonGroup>

namespace Ui {
class MainMenu;
}

namespace s21 {

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();
    QButtonGroup *GetMenuItemsGroup();

private:
    Ui::MainMenu *ui_;
};

}

#endif // MAIN_MENU_H