#include "model.h"
#include<time.h>
#include <thread>
#include <unistd.h>

Model::Model(Interface *i) : m_interface(i)
{
    image_path = "D:/WorkSpace/QT/MvpTest/";
    data = "Hello MVP!!!";

    //启动一个线程
    run();
}

std::string Model::get_data()
{
    return data;
}

static int count = 0;
void Model::work()
{
    while (1) {
        sleep(1);
        time_t result = time(NULL);
        data = std::to_string(result);
        if(count++ % 5 == 0)
        {
            m_interface->update_message("Auto:"+data);  //更新界面显示
            if(count % 2 == 0) {
                m_interface->update_image(image_path+"picture_normal.jpg");
            }
            else{
                m_interface->update_image(image_path+"picture_blue.jpg");
            }
        }
    }
}

void Model::run()
{
    std::thread work_thread(std::bind(&Model::work, this));
    work_thread.detach();
}


