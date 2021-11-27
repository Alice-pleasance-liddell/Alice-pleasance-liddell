/*
 * @Descripttion: 
 * @version: 
 * @Author: Chester
 * @Date: 2021-11-27 16:11:28
 * @LastEditors: Chester
 * @LastEditTime: 2021-11-27 17:48:46
 */
#pragma once
#include <iostream>
#include "Worker.h"

/**
 * @brief: 职员类，继承工人类，声明继承的虚函数 
 * @param {*}
 * @return {*}
 */
class Boss:public Worker
{
public:
    Boss(int id, std::string name, std::string job);
    ~Boss();

    virtual void showinfo();
    virtual std::string getjob();
};