#include "PageLib.h"
#include "Configuration.h"
#include <chrono>

using namespace wdcpp;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{

    auto start = chrono::steady_clock::now();//开始时间
    PageLib lib(Configuration::getInstance()->getConfigMap()["pages"]);
    lib.create();
    lib.store();
    auto end = chrono::steady_clock::now();//结束时间

    cout << "花费总时间为: "
         << chrono::duration_cast<chrono::milliseconds>(end-start).count()
         << " ms"<< endl;

    return 0;
}
