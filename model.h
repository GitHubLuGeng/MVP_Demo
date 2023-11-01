#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <functional>
#include "interface.h"

class Model
{
public:
    explicit Model(Interface *i = 0);
    std::string get_data();
public:
    void run();
    void work();

private:
    std::string image_path;
    std::string data;
    Interface *m_interface; //m_interface 指针指向的是栈上或全局/静态内存中的对象不需要手动释放内存。只有在使用 new 关键字动态分配内存时，才需要手动释放内存。
};

#endif // MODEL_H
