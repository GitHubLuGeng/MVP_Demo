#include "presenter.h"

Presenter::Presenter(QObject *parent) : QObject(parent)
{
    //绑定按键指令和按键动作
    connect(&view, &View::buttonClicked, this, &Presenter::onButtonClicked);
}

Presenter::~Presenter()
{
    delete model;
}

void Presenter::showView()
{
    view.show();
}

/*
 * 通过信号和槽的方式，响应view层的按键指令，更新界面显示
 */
void Presenter::onButtonClicked()
{
    view.updateMessage(QString::fromStdString(model->get_data()));
}

/*
 * 通过接口的方式被model层调用，用于更新显示图片
 */
void Presenter::update_image(const std::string path)
{
    printf("path:%s\n",path.c_str());
    view.updateImage(QString::fromStdString(path));
}

/*
 * 通过接口的方式被model层调用，用于更新显示消息
 */
void Presenter::update_message(const std::string data)
{
    printf("data:%s\n",data.c_str());
    view.updateMessage(QString::fromStdString(data));
}
