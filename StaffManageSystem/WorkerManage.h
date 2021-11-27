/*
 * @Descripttion: 
 * @version: 
 * @Author: Chester
 * @Date: 2021-11-26 14:44:32
 * @LastEditors: Chester
 * @LastEditTime: 2021-11-27 19:45:15
 */
#pragma once
#include <iostream>
#include "Worker.h"

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
    Worker ** m_workerarray;

    WorkerManage();
    ~WorkerManage();

    void quitsystem();
    void showmenu();
    void addworker(int id, std::string, std::string);

};