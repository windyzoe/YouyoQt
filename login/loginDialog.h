﻿#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

#include "login\LineEditLabel.h"

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog {
  Q_OBJECT

public:
  explicit loginDialog(QWidget *parent = nullptr);
  ~loginDialog();

  //自定义控件
  LineEditLabel *linePassword;

private slots:

private:
  void minimumSize();

  void checkLogin();

private:
  Ui::loginDialog *ui;
};

#endif // LOGINDIALOG_H
