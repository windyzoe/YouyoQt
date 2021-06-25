﻿#include "LineEditLabel.h"

#include <QFile>
#include <QHBoxLayout>
#include <QPushButton>
#include <QApplication>

LineEditLabel::LineEditLabel(QWidget *parent) :
  QLineEdit(parent)
{
  pb_passwordvisible = new QPushButton(this);
  pb_passwordvisible->setCursor(Qt::PointingHandCursor);
  pb_passwordvisible->setCheckable(true);
  pb_passwordvisible->setObjectName("pb_password");


  //初始设置密码不可见
  setEchoMode(QLineEdit::Password);


  //信号槽
  connect(pb_passwordvisible,&QPushButton::toggled,[this](bool checked){
      if(checked)
        {
          setEchoMode(QLineEdit::Normal);
        }
      else{
          setEchoMode(QLineEdit::Password);
        }
    });

  QHBoxLayout *layout = new QHBoxLayout();
  layout->addStretch();
  layout->addWidget(pb_passwordvisible);
  layout->setContentsMargins(0,0,0,0);
  setLayout(layout);

  //设置样式
  //只有对qApp才可以直接用"file:///:/qss/files/application.css"设置
  QFile styleSheet(":/qss/res/qss/defaultstyle/LineEditLabel.css");

  if (!styleSheet.open(QIODevice::ReadOnly)) {
    qWarning("Unable to open :/files/LineEditLabel.qss");
    return;
  }

  this->setStyleSheet(styleSheet.readAll());

}
