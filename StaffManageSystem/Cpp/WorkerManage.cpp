/*
 * @Descripttion: workermanage类函数的实现
 * @version: 
 * @Author: Chester
 * @Date: 2021-11-26 14:45:00
 * @LastEditors: Chester
 * @LastEditTime: 2021-11-30 17:48:00
 */

#include "../header/WorkerManage.h"
#include "../header/Worker.h"
#include "../header/Staff.h"
#include "../header/Manager.h"
#include "../header/Boss.h"


/**
 * @brief: 工人类构造函数实现
 * @param {*}
 * @return {*}
 */
WorkerManage::WorkerManage()
{
	//尝试打开用户文件，并根据打开结果执行操作
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	//如果没有打开文件
	std::cout << "初始化.../" << '\n';
	if (!ifs.is_open())
	{
		std::cout << "用户文件不存在！" << '\n';
		m_workernum = 0;
		m_workerarray = NULL;
		m_fileisempty = true;
		ifs.close();
		
		std::cout << "Press any key to continue..." << '\n';
		std::cin.get();

		return;
	} // end if

	//如果打开了文件且为空
	if (ifs.peek() == EOF)
	{
		std::cout << "用户文件为空！" << '\n';
		m_workernum = 0;
		m_workerarray = NULL;
		m_fileisempty = true;
		ifs.close();

		std::cout << "Press any key to continue..." << '\n';
		std::cin.get();

		return;
	} //end if

	// 如果打开文件且不为空 创建抽象类型的父类数组存放
	m_fileisempty = false;
	m_workernum = readfile(ifs);
	m_workerarray = new Worker * [m_workernum];
	std::cout << "当前职工人数为" << m_workernum << '\n';

	initstaff(); //将文件中数据初始化到堆区当中

	for (int i = 0; i < m_workernum; i++)
	{
		m_workerarray[i]->showinfo();
		// std::cout << m_workerarray[i]->m_id << " ";
		// std::cout << m_workerarray[i]->m_name << " ";
		// std::cout << m_workerarray[i]->m_job << '\n';
	}

	std::cout << "Press any key to continue..." << '\n';
	std::cin.get();
	system("CLS");
} // end func


/**
 * @brief:工人类析构实现
 * @param {*}
 * @return {*}
 */
WorkerManage::~WorkerManage()
{
	if (m_workerarray != NULL)
	{
		delete[] m_workerarray;
		m_workerarray = NULL;
	}
}


/**
 * @brief: 退出函数实现
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
	std::cout<< "*********   欢迎使用职工管理系统！ **********" << '\n';
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


/**
 * @brief: 添加员工函数实现
 * @param {*}
 * @return {*}
 */
void WorkerManage::addworker()
{
	int addnum = 0;		//新增职员信息条数
	int newsize = 0;	//新空间大小

	std::cout << "请输入添加员工的数量：";
	std::cin >> addnum;

	if (std::cin.good() && addnum > 0)
	{
		newsize = m_workernum + addnum;
		Worker ** newspace = new Worker *[newsize];	//声明新指针指向堆区数组

		//将原来的数组复制到新数组
		if (m_workerarray != NULL) {
			for (int i = 0; i< m_workernum; i++) {
				newspace[i] = this->m_workerarray[i];
			} // end for
		}  	//end if

		//添加新职员
		for (int i = 0; i < addnum; i++)
		{
			int id;
			int jobchioce;
			std::string name;

			while (1)
			{
				std::cout << "请输入第 " << i+1 << " 个新职员的编号：";
				std::cin >> id;

				if (std::cin.good() && id >= 0) {
					if (isexist(id) != -1) {
						std::cout << "已存在编号为 " << id << " 的职员, 请重新输入。\n";
                		std::fflush(stdin);
						continue;
					} else {
						break;
					}
				} else {
					std::cout << "数据类型不合法或数据不合理，请重新输入。\n";
					std::cin.clear();
                	std::fflush(stdin);
				}//end if
			} // end while
			
			while (1)
			{
				std::cout << "请输入第 " << i+1 << " 个新职员的姓名：";
				std::cin >> name;

				if (std::cin.good()) {
					break;
				} else {
					std::cout << "数据类型不合法或数据不合理，请重新输入。\n";
					std::cin.clear();
                	std::fflush(stdin);
				} //end if
			}// end while

			while (1)
			{
				std::cout << "请选择第 " << i+1 << " 个新职员的岗位(1.职员, 2.经理, 3.老板)：";
				std::cin >> jobchioce;

				if (std::cin.good() && jobchioce >= 1 && jobchioce <= 3) {
					break;
				} else {
					std::cout << "数据类型不合法或数据不合理，请重新输入。'\n'";
					std::cin.clear();
                	std::fflush(stdin);
				}//end if
			}// end while


			Worker * worker = NULL; //指向单个职员的指针

			switch (jobchioce)
			{
			case 1:
				worker = new Staff(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newspace[this->m_workernum + i] = worker;

		} // end for

		delete[] this->m_workerarray;	//释放原来的数组
		this->m_workerarray = newspace;	//指向新的数组
		this->m_workernum = newsize;	//更新数组大小

		save(); //保存到文件
		m_fileisempty = false;
		std::cout << "成功添加 " << addnum << " 个员工。";

		std::cin.get();
		std::cin.get();
		system("CLS");
		
	} else {
		std::cout << "数据类型不合法或数据不合理。";
	} // end if
} // end func


/**
 * @brief: 保存到文件
 * @param {*}
 * @return {*}
 */
void WorkerManage::save()
{
	std::fstream ofs(FILENAME, std::ios::out);

	for (int i = 0; i < m_workernum; i++)
	{
		ofs << m_workerarray[i]->m_id << " "
			<< m_workerarray[i]->m_name << " "
			<< m_workerarray[i]->m_job << '\n';
	} //end for

	ofs.close();
} // end func


/**
 * @brief: 从文件中读取用户信息 
 * @param {*}
 * @return {*}
 */
int WorkerManage::readfile(std::ifstream& ifs)
{
	int num; //统计人数
	
	std::string templine;

	//while (ifs >> id && ifs >> name && ifs >> job)
	while (std::getline(ifs, templine, '\n')) {
		num++;
	}

	return num;
} //end func


/**
 * @brief: 初始化员工数组 
 * @param {*}
 * @return {*}
 */
void WorkerManage::initstaff()
{
	int id = 0;
	int job = 0;
	std::string name;

	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> job)
	{
		Worker * worker = NULL;

		if (job == 1){
			worker = new Staff(id, name, job);
		} else if (job == 2){
			worker = new Manager(id, name, job);
		} else{
			worker = new Boss(id, name, job);
		}

		m_workerarray[index]  = worker;
		index++;
	}// end while

	ifs.close();
} //end func


/**
 * @brief: 显示职工信息
 * @param {*}
 * @return {*}
 */
void WorkerManage::showstaffinfo()
{
	if (m_fileisempty) 
	{
		std::cout << "文件不存在或记录为空。" << '\n';
	} else {
		for (int i = 0; i < m_workernum; i++) {
			m_workerarray[i]->showinfo();
		} // end for
	} // end if

	std::cin.get();
	std::cout << "Press any key to continue..." << '\n';
	std::cin.get();
	system("CLS");	
} //end func


/**
 * @brief: 判断职员是否存在
 * @param {int} id
 * @return {int} index 存在返回其下标，不存在返回-1
 */
int WorkerManage::isexist(int id)
{
	int index = -1;

	for (int i = 0; i < m_workernum; i++)
	{
		if (m_workerarray[i]->m_id == id) {
			index = i;
			break;
		}
	} // end for

	return index;
} // end func


/**
 * @brief: 删除职员信息函数实现
 * @param {*}
 * @return {*}
 */
void WorkerManage::delstaffinfo()
{
	int id = 0; //需要删除职员的id
	int index = 0; //接收查询结果

	if (!m_workerarray)
	{
		std::cout << "文件不存在或记录为空。" << '\n';
	} else {
		std::cout << "请输入想要删除的职工编号：";
		std::cin >> id;

		index = isexist(id); // 查找id是否存在并返回结果

		if(index != -1)
		{
			for ( ; index < m_workernum; index++){
				m_workerarray[index] = m_workerarray[index+1]; //向前覆盖
			}

			m_workernum--; //更新数组大小
			save();

			std::cout << "删除成功。" << '\n';
		} else {
			std::cout << "删除失败，未找到该职工" << '\n';
		} // end if
	} // end if

	std::cin.get();
	std::cout << "Press any key to continue..." << '\n';
	std::cin.get();
	std::system("CLS");

} // end func

/**
 * @brief: 修改职员函数实现
 * @param {*}
 * @return {*}
 */
void WorkerManage::modifystaff()
{
	int id = 0; //需要修改信息的职员id
	int ret = 0; //接收查询结果

	if (m_fileisempty)
	{
		std::cout << "文件不存在或记录为空。" << '\n';
	} else {
		std::cout << "请输入要修改的职工编号：";
		std::cin >> id;

		ret = isexist(id);
		if (ret != -1) //如果员工存在
		{
			int newid = 0;
			int newjob = 0;
			std::string newname = "";

			delete m_workerarray[ret];

			while (1)
			{
				std::cout << "找到 " << id << " 号员工，请输入职员的新编号：";
				std::cin >> newid;

				if (std::cin.good() && newid >= 0) {
					break;
				} else {
					std::cout << "数据类型不合法或数据不合理，请重新输入。";
				}//end if
			} // end while
			
			while (1)
			{
				std::cout << "请输入新姓名：";
				std::cin >> newname;

				if (std::cin.good()) {
					break;
				} else {
					std::cout << "数据类型不合法或数据不合理，请重新输入。";
				} //end if
			}// end while

			while (1)
			{
				std::cout << "请选择职员的新岗位(1.职员, 2.经理, 3.老板)：";
				std::cin >> newjob;

				if (std::cin.good() && newjob > 1 && newjob < 3) {
					break;
				} else {
					std::cout << "数据类型不合法或数据不合理，请重新输入。";
				}//end if
			}// end while

			Worker * worker = NULL;
			if (newjob == 1) {
				worker = new Staff(id, newname, newjob);
			} else if (newjob == 2) {
				worker = new Manager(id, newname, newjob);
			} else {
				worker = new Boss(id, newname, newjob);
			}

			m_workerarray[ret] = worker;
			std::cout << "修改成功。" << '\n';
		} else {
			std::cout << "修改失败，没有找到用户。" << '\n';
		}// end if
	} // end if

	std::cin.get();
	std::cout << "Press any key to continue..." << '\n';
	std::cin.get();
	system("CLS");
}


/**
 * @brief: 查找员工函数的实现 
 * @param {*}
 * @return {*}
 */
void WorkerManage::findstaff()
{
	if (m_fileisempty)
	{
		std::cout << "文件不存在或记录为空。" << '\n';
	} else {
		int select = 0;

		std::cout << "1.按照职工的编号查找" << '\n';
		std::cout << "2.按照职工的姓名查找" << '\n';
		std::cout << "请输入查找方式：";
		std::cin >> select;

		if (std::cin.good() && select == 1) {
			int id;

			std::cout << "请输入职工编号：";
			std::cin >> id;
			int ret = isexist(id);
			if (ret != -1)
			{
				std::cout << "已找到该员工" << '\n';
				m_workerarray[ret]->showinfo();
			} else {
				std::cout << "查找失败，没有该员工'\n'";
			}
		} else if (select == 2) {
			std::string name;
			bool flag = false;

			std::cout << "请输入职工姓名：";
			std::cin >> name;
			
			for (int i = 0; i < m_workernum; i++) {
				if (m_workerarray[i]->m_name == name) {
					std::cout << "已找到该员工" << '\n';
					m_workerarray[i]->showinfo();
					flag = true;
				}
			} // end for
			
			if (flag == false) {
				std::cout << "查找失败，没有该员工";
			}// end if
		} else {
			std::cout << "输入有误。" << '\n';
		} // end if
	} //end if

	std::cin.get();
	std::cout << "Press any key to continue..." << '\n';
	std::cin.get();
	system("CLS");
} // end func


/**
 * @brief: 职工排序函数实现 
 * @param {*}
 * @return {*}
 */
void WorkerManage::sortstaffid()
{
	if (m_fileisempty)
	{
		std::cout << "文件不存在或记录为空。" << '\n';
		std::cout << "Press any key to continue..." << '\n';
		std::cin.get();
		std::cin.get();
		system("CLS");
	} else {
		int select = 0;

		std::cout << "1.按照升序排列" << '\n';
		std::cout << "2.按照降序排列" << '\n';
		std::cout << "请输入排列方式：";
		std::cin >> select;
		
		//选择排序
		for (int i = 0; i < m_workernum; i++) {
			int minormax = i;
			for(int j = i + 1; j < m_workernum; j++) {
				if (select == 1) {
					if (m_workerarray[minormax]->m_id > m_workerarray[j]->m_id) {
						minormax = j;
					}
				} else {
					if (m_workerarray[minormax]->m_id < m_workerarray[j]->m_id) {
						minormax = j;
					}
				}
			}

			if (i != minormax) {
				Worker * temp = this->m_workerarray[i];
				m_workerarray[i] = m_workerarray[minormax];
				m_workerarray[minormax] = temp;
			}
		} // end for

		std::cout << "排序成功。" << '\n';

		save();
		showstaffinfo();
	} // end if
} //end func


/**
 * @brief:	清空职工信息文件函数实现
 * @param {*}
 * @return {*}
 */
void WorkerManage::cleanfile()
{
	int select = 0;

	std::cout << "确定清空职员信息吗？" << '\n';
	std::cout << "1. 确定\t" << "2. 返回\n" << ">>";
	std::cin >> select;

	if (std::cin.good() && select == 1)
	{
		std::ofstream ofs(FILENAME, std::ios::trunc); //文件存在则删除
		ofs.close();

		//如果先前操作数组，则清空内存中存在的数组数据
		if(m_workerarray != NULL) {
			for (int i = 0; i < m_workernum; i++) {
				delete m_workerarray[i];
				m_workerarray[i] = NULL;
			} // end for

			delete[] m_workerarray;
			m_workerarray = NULL;
			m_workernum = 0;
			m_fileisempty = true;
		} //end if

	std::cout << "已完成清空。" << '\n';
	} //end if


	std::cin.get();
	std::cout << "Press any key to continue..." << '\n';
	std::cin.get();
	system("CLS");
}// end func