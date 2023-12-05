#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>     //библиотека для картинок

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/1.jpg");  //создаем объект типа картинка с именем любым
    int w = ui->image->width();  // image (переменованный label)для удобства
    int h = ui->image->height();

    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    // используем setPixmap
    // в параметрах указываем объект pix
    // у него метод scaled
    // там размеры указываем
    // и Qt::KeepAspectRatio - что бы подстраивалась под изменения расширений??
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString login = ui->login->text();                         // login (переменованный line edite) берем с него текстовую информацию
      QString password = ui->pass->text();                 // аналогично  pass это второй line edite , с него берем пароль

      if(login == "Grib"  && password == "test")       // проверяем совпадают ли с заданными
      {
         // QMessageBox::information(this, "Ура", "Вы успешно авторизовались");
          ui->statusbar->showMessage("Вы успешно авторизовались");
      }
      else
      {
         // QMessageBox::warning(this, "Авторизация", "Вы НЕ успешно авторизовались");
          ui->statusbar->showMessage("Вы НЕ успешно авторизовались");
      }
}

