/*
 * @Descripttion: 职员头文件
 * @version: 
 * @Author: Chester
 * @Date: 2021-11-27 15:14:15
 * @LastEditors: Chester
 * @LastEditTime: 2021-11-27 16:01:47
 */
#pragma once
#include <iostream>
#include "Worker.h"

/**
 * @brief: 职员类，继承工人类，声明继承的虚函数 
 * @param {*}
 * @return {*}
 */
class Staff:public Worker
{
public:
    Staff(int id, std::string name, std::string job);
    ~Staff();

    virtual void showinfo();
    virtual std::string getjob();
};