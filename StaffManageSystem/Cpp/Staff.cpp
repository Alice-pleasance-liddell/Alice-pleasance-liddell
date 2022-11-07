/*
 * @Descripttion: 职工类函数实现
 * @version: 
 * @Author: Chester
 * @Date: 2021-11-27 15:14:25
 * @LastEditors: Chester
 * @LastEditTime: 2021-11-28 17:16:01
 */
#include "../header/Staff.h"

/**
 * @brief: 职工类构造函数，赋值id， name job
 * @param {int} id
 * @param {string} name
 * @param {string} job
 * @return {*}
 */
Staff::Staff(int id, std::string name, int job)
{
    m_id = id;
    m_name = name;
    m_job = job;
}


Staff::~Staff()
{

}

/**
 * @brief: 输出职工信息， id，name
 * @param {*}
 * @return {*}
 */
void Staff::showinfo()
{
    std::cout << "职工编号：" << m_id << '\t';
    std::cout << "职工姓名：" << m_name << '\t';
    std::cout << "职工岗位：" << this->getjob() << '\n';
}

/**
 * @brief: 返回岗位
 * @param {*}
 * @return {*}
 */
std::string Staff::getjob()
{
    return std::string("员工");
}