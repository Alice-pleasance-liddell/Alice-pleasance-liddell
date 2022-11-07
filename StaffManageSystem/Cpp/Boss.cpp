/*
 * @Descripttion: 
 * @version: 
 * @Author: Chester
 * @Date: 2021-11-27 16:11:33
 * @LastEditors: Chester
 * @LastEditTime: 2021-11-28 17:16:05
 */
#include "../header/Boss.h"

/**
 * @brief: 董事类构造函数，赋值id， name job
 * @param {int} id
 * @param {string} name
 * @param {string} job
 * @return {*}
 */
Boss::Boss(int id, std::string name, int job)
{
    m_id = id;
    m_name = name;
    m_job = job;
}


Boss::~Boss()
{

}

/**
 * @brief: 输出职工信息， id，name
 * @param {*}
 * @return {*}
 */
void Boss::showinfo()
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
std::string Boss::getjob()
{
    return std::string("董事");
}