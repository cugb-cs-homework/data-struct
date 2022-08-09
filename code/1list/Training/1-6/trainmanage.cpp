#include "trainmanage.h"

trainmanage::trainmanage()
{
    std::cout << "Welcome to the train management system." << std::endl;
}

trainmanage::~trainmanage()
{
    std::cout << "Thanks for using the train management system." << std::endl;
}

void trainmanage::search()
{
    std::cout << "Input train id: ";
    std::string s;
    std::cin >> s;
    train temp(s);
    int pos = M.DbList::search(temp);

    if (pos == -1) {
        std::cout << "failed to search train." << std::endl;
        return;
    }
    M.DbList::getData(pos, temp);
    std::cout << "id\tstarttime\tendtime\tstart\tend" << std::endl;
    showInfo(temp);
    std::cout << "search train succeed." << std::endl;
}

void trainmanage::change()
{
    std::cout << "Input train id: ";
    std::string s;
    std::cin >> s;
    train temp(s);
    int pos = M.DbList::search(temp);

    if (pos == -1) {
        std::cout << "failed to change train." << std::endl;
        return;
    }
    temp = getInfo();
    M.setData(pos, temp);
    std::cout << "change train succeed." << std::endl;
}

void trainmanage::display()
{
    std::cout << "id\tstarttime\tendtime\tstart\tend" << std::endl;

    train temp;

    for (int i = 1; i <= M.length(); ++i) { // 效率有点低了其实重载输出运算符更好
        M.getData(i, temp);
        showInfo(temp);
    }
}

train trainmanage::getInfo()
{
    std::string id, starttime, endtime, start, end;
    std::cout << "Input id: ";
    std::cin.ignore();
    std::cin >> id;
    std::cout << "Input starttime: ";
    std::cin.ignore();
    std::cin >> starttime;
    std::cout << "Input endtime: ";
    std::cin.ignore();
    std::cin >> endtime;
    std::cout << "Input start: ";
    std::cin.ignore();
    std::cin >> start;
    std::cout << "Input end: ";
    std::cin.ignore();
    std::cin >> end;

    return train { id, starttime, endtime, start, end };
}

void trainmanage::showInfo(train &e)
{
    std::cout << e.id << "\t" << e.starttime << "\t\t" << e.endtime << "\t"
              <<e.start << "\t" << e.end << std::endl;
}

void trainmanage::menu()
{
    std::cout << "================================" << std::endl;
    std::cout << "****  train manage system   ****" << std::endl;
    std::cout << "****    [0] exit            ****" << std::endl;
    std::cout << "****    [1] add train       ****" << std::endl;
    std::cout << "****    [2] remove train    ****" << std::endl;
    std::cout << "****    [3] search train    ****" << std::endl;
    std::cout << "****    [4] change train    ****" << std::endl;
    std::cout << "****    [5] all train       ****" << std::endl;
    std::cout << "================================" << std::endl;
    std::cout << "Input your choice: ";
}

void trainmanage::add()
{
    std::cout << "Input train information: " << std::endl;
    train temp = getInfo();

    if (M.search(temp) != -1) {
        std::cout << "Add train failed." << std::endl;
        return;
    }
    M.push_back(temp);
    std::cout << "Add train succeed." << std::endl;
}

void trainmanage::remove()
{
    std::cout << "Input train id: ";
    std::cin.ignore();
    std::string s;
    std::cin >> s;
    train temp(s);
    int pos = M.DbList::search(temp);

    if (pos == -1) {
        std::cout << "failed to remove train." << std::endl;
        return;
    }
    M.DbList::remove(pos, temp);
    std::cout << "id\tstarttime\tendtime\tstart\tend" << std::endl;
    showInfo(temp);
    std::cout << "remove train succeed." << std::endl;
}
