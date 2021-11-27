/*
 * @Descripttion: workermanage类函数的实现
 * @version: 
 * @Author: Chester
 * @Date: 2021-11-26 14:45:00
 * @LastEditors: Chester
 * @LastEditTime: 2021-11-27 20:24:48
 */

#include "WorkerManage.h"
#include "Worker.h"

WorkerManage::WorkerManage()
{
	m_workernum = 0;
	m_workerarray = NULL;
}

WorkerManage::~WorkerManage()
{

}

/**
 * @brief: 退出功能
 * @param {*}
 * @return {*}
 */
void WorkerManage::quitsystem()
{
	std::cout << "欢迎下次使用！" << '\n';

	exit(0);
}

/**
 * @brief: 主界面
 * @param {*}
 * @return {*}
 */
void WorkerManage::showmenu()
{
	std::cout<< "********************************************" << '\n';
	std::cout<< "*********  欢迎使用职工管理系统！ **********" << '\n';
	std::cout<< "*************  0.退出管理程序  *************" << '\n';
	std::cout<< "*************  1.增加职工信息  *************" << '\n';
	std::cout<< "*************  2.显示职工信息  *************" << '\n';
	std::cout<< "*************  3.删除离职职工  *************" << '\n';
	std::cout<< "*************  4.修改职工信息  *************" << '\n';
	std::cout<< "*************  5.查找职工信息  *************" << '\n';
	std::cout<< "*************  6.按照编号排序  *************" << '\n';
	std::cout<< "*************  7.清空所有文档  *************" << '\n';
	std::cout<< "********************************************" << '\n';
	std::cout<< '\n';
}


void WorkerManage::addworker(int id, std::string, std::string)
{
	int addnum = 0;
	int newsize = 0;

	std::cout << "请输入添加员工的数量：";
	std::cin >> addnum;

	if(addnum > 0)
	{
		int newsize = m_workernum + addnum;
		Worker ** newspace = new Worker *[newsize];
		if (m_workerarray != NULL)
		{
			for (int i = 0; i< m_workernum; i++)
			{
				newspace
			}
		}
	} else {

	}
}