/*
 * @Descripttion: 
 * @version: 
 * @Author: Chester
 * @Date: 2021-11-27 16:11:28
 * @LastEditors: Chester
 * @LastEditTime: 2021-11-28 17:16:07
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
    Boss(int id, std::string name, int job);
    ~Boss();

    virtual void showinfo();
    virtual std::string getjob();
};