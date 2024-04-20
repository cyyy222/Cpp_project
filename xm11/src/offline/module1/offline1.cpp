#include "SplitTool.h"
#include "DictProducer.h"
#include "Configuration.h"
#include <chrono>


using namespace std;
using namespace wdcpp;
void test0()
{

    string cnYuliaoPath = Configuration::getInstance()->getConfigMap()["cnDir"];
    string enYuliaoPath = Configuration::getInstance()->getConfigMap()["enDir"];

    // string cnYuliaoPath = Configuration::getInstance()->getConfigMap()["cnTest"];
    // string enYuliaoPath = Configuration::getInstance()->getConfigMap()["enTest"];

    auto start1 = chrono::steady_clock::now();//开始时间
    SplitTool tool;
    DictProducer endict1(cnYuliaoPath, &tool);
    auto end1 = chrono::steady_clock::now();//结束时间
    cout << "花费时间: "
         << chrono::duration_cast<chrono::milliseconds>(end1 - start1).count()
         << " ms" <<endl;



    auto start2 = chrono::steady_clock::now();//开始时间
    DictProducer endict2(enYuliaoPath);
    auto end2 = chrono::steady_clock::now();//结束时间
    cout <<"花费时间为: "
         << chrono::duration_cast<chrono::milliseconds>(end2-start2).count()
         << " ms" <<endl;
}

int main()
{

    test0();
    return 0;
}
