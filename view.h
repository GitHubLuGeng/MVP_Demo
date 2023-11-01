#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class View : public QWidget
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);

    void updateImage(const QString& path);
    void updateMessage(const QString& message);

signals:
    void buttonClicked();

private:
    QLabel label;
    QLabel image_label;
    QPushButton button;
};

#endif // VIEW_H
