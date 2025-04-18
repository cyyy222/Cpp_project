#include "Configuration.h"
#include <stdlib.h>

#include "func.h"
//#include <ErrorCheck>
#include <iostream>
#include <fstream>
#include <sstream>
using std::ifstream;
using std::stringstream;

namespace wdcpp
{
// Configuration *Configuration::_pInstance = nullptr; // 饿汉
Configuration *Configuration::_pInstance = Configuration::getInstance(); // 懒汉

Configuration::Configuration(const string &filepath = "../conf/myconf.conf")
    : _filepath(filepath)
{
    loadConf();
}

/**
 *  加载配置文件，并将配置信息存入 _configMap
 */
void Configuration::loadConf()
{
    ifstream ifs(_filepath, ifstream::in);
    if (!ifs.good())
    {
       printf("不能打开文件");
    }

    string lines;
    string first, second;
    while (getline(ifs, lines))
    {
        stringstream ss(lines);
        ss >> first >> second;
        _configMap[first] = second;
    }

    std::cout << "[ 正在加载配置文件... ]\n"
              << std::endl;
    for (auto &item : _configMap)
    {
        std::cout << item.first << " " << item.second << std::endl;
    }
    std::cout << "\n[ 配置文件加载成功 ]\n"
              << std::endl;

    ifs.close();
}

Configuration *Configuration::getInstance()
{
    if (_pInstance == nullptr)
    {
        _pInstance = new Configuration();
        atexit(destroy);
    }

    return _pInstance;
}

void Configuration::destroy()
{
    using namespace std;
    cout << "void Configuration::destroy()" << endl;

    if (_pInstance)
    {
        delete _pInstance;
        _pInstance = nullptr;
    }
}

unordered_map<string, string> &Configuration::getConfigMap()
{
    return _configMap;
}
}; // namespace wdcpp
