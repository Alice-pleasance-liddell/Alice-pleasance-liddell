/*
 * @Descripttion: 
 * @version: 
 * @Author: Chester
 * @Date: 2021-11-26 14:44:32
 * @LastEditors: Chester
 * @LastEditTime: 2021-11-30 16:37:29
 */
#pragma once
#include <iostream>
#include <fstream>
#include "Worker.h"
#define FILENAME "stafffile.txt"

/**
 * @brief: 工人类头文件
 * @param {*}
 * @return {*}
 * m_workernum  记录职工人数
 * m_workerarray  指向职工数组的指针
 */
class WorkerManage
{
public:
    int m_workernum;
    bool m_fileisempty;
    Worker ** m_workerarray;

    WorkerManage();
    ~WorkerManage();

    int  readfile(std::ifstream& ifs);
    int  isexist(int id);
    void save();
    void initstaff();

    void quitsystem();  //退出函数声明
    void showmenu();    //显示菜单函数声明
    void addworker();   //添加职工信息函数声明
    void showstaffinfo();   //显示职工信息函数声明
    void delstaffinfo();    //删除职工信息函数声明
    void modifystaff(); //修改职工信息函数声明
    void findstaff();   //查找职工函数声明
    void sortstaffid();  //职工排序函数声明
    void cleanfile(); //清空文件按函数声明

};