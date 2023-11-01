#ifndef PRESENTER_H
#define PRESENTER_H

#include <QObject>
#include "model.h"
#include "view.h"
#include "interface.h"

class Presenter : public QObject, public Interface
{
    Q_OBJECT
public:
    explicit Presenter(QObject *parent = nullptr);
    ~Presenter() override;
    void showView();
    //接口函数
    void update_image(const std::string path) override;
    void update_message(const std::string data) override;

public slots:
    void onButtonClicked();

private:
    Model *model = new Model(this);
    View view;
};

#endif // PRESENTER_H
