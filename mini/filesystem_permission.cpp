//需要gcc-8 以上编译器
// https://cppsecrets.com/users/70910911997100105108101485164103109971051084699111109/C00-Boostfilesystempermissions.php

#include <iostream>
#include<fstream>
#include <filesystem>
namespace fs=std::filesystem;
void tperms(fs::perms p)
{
     std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
             << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
              << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
              << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
              << '\n';
}
int main()
{
    fs::create_directories("/home/wss/minieye/mini/level1");
    std::ofstream("/home/wss/minieye/mini/level1/a.txt");
    std::cout<<"Initial permisssions : ";
    tperms(fs::status("/home/wss/minieye/mini/level1/a.txt").permissions());
    fs::permissions("/home/wss/minieye/mini/level1/a.txt",fs::perms::owner_all | fs::perms::group_all,
    fs::perm_options::add);
    std::cout << "After adding o+rwx and g+rwx: ";
    tperms(fs::status("/home/wss/minieye/mini/level1/a.txt").permissions());
    fs::remove("/home/wss/minieye/mini/level1/a.txt");
    return 0;
}
