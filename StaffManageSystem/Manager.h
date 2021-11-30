/*
 * @Descripttion: 
 * @version: 
 * @Author: Chester
 * @Date: 2021-11-27 16:11:13
 * @LastEditors: Chester
 * @LastEditTime: 2021-11-28 17:16:09
 */
#include <iostream>
#include "Worker.h"

/**
 * @brief: 
 * @param {*}
 * @return {*}
 */
class Manager:public Worker
{
public:
    Manager(int id, std::string name, int job);
    ~Manager();

    virtual void showinfo();
    virtual std::string getjob();
};