#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <stdint.h>

class Interface {
  public:
    virtual ~Interface() {};
    virtual void update_image(const std::string path) = 0;
    virtual void update_message(const std::string data) = 0;
};

#endif // INTERFACE_H
