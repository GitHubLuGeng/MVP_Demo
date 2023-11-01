#include "view.h"
#include <QVBoxLayout>

View::View(QWidget *parent) : QWidget(parent)
{
    this->resize(800,600);  //设置窗口大小

    //设置背景色
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::lightGray);
    this->setPalette(palette);

    // 创建一个QFont对象，设置字体
    label.setFont(QFont("微软雅黑",42,QFont::Bold));
    // 设置对齐方式为居中对齐
    label.setAlignment(Qt::AlignCenter);
    // 设置文本内容
    label.setText("Hello MVP!");

    // 显示图片
    image_label.setScaledContents(true); //show all
    image_label.setPixmap(QPixmap("D:/WorkSpace/QT/MvpTest/picture_normal.jpg"));

    //设置按钮内容
    button.setText("Click me!");
    button.setStyleSheet("QPushButton { background-color: white; color: black; }");
    button.resize(50,30);

    //排版
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(&label);
    layout->addWidget(&image_label);
    layout->addWidget(&button);

    connect(&button, &QPushButton::clicked, this, &View::buttonClicked);
}

void View::updateImage(const QString& path)
{
    image_label.setScaledContents(true); //show all
    image_label.setPixmap(QPixmap(path));
}

void View::updateMessage(const QString& message)
{
    label.setText(message);
}
