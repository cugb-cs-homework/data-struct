#ifndef TRAINMANAGE_H
#define TRAINMANAGE_H
#include "dblist.h"
#include <iostream>
#include <string>

class train
{
public:

    train() = default;
    train(std::string id, std::string starttime = "00:00", std::string endtime = "00:00",
          std::string start = "", std::string end = "") :
        id(id),
        starttime(starttime),
        endtime(endtime),
        start(start),
        end(end)
    {
    }

    bool operator==(const train &T) const
    {
        return this->id == T.id;
    }

    std::string id, starttime, endtime, start, end;
};

class trainmanage
{
public:

    trainmanage();
    ~trainmanage();
    void menu();
    void add();
    void remove();
    void search();
    void change();
    void display();

private:

    DbList<train> M;
    train getInfo(); // 辅助函数
    void  showInfo(train &e);
};

#endif // TRAINMANAGE_H
