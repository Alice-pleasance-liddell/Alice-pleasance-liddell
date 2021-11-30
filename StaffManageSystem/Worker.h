/*
 * @Descripttion: 工人类头文件
 * @version: 
 * @Author: Chester
 * @Date: 2021-11-27 15:16:09
 * @LastEditors: Chester
 * @LastEditTime: 2021-11-28 17:20:53
 */
#pragma once
#include <iostream>

/**
 * @brief: 工人抽象类，所有职位的基类
 * @param: id, name
 * 虚函数showinfo() 返回个人信息
 * 虚函数getjob() 返回岗位
 */
class Worker
{
public:
    int m_id;
    std::string m_name;
    int m_job;

    virtual void showinfo() = 0;
    virtual std::string getjob() =0;
};