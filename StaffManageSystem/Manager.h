/*
 * @Descripttion: 
 * @version: 
 * @Author: Chester
 * @Date: 2021-11-27 16:11:13
 * @LastEditors: Chester
 * @LastEditTime: 2021-11-27 16:26:48
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
    Manager(int id, std::string name, std::string job);
    ~Manager();

    virtual void showinfo();
    virtual std::string getjob();
};