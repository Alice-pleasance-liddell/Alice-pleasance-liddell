/*
 * @Descripttion:  主函数
 * @version: 
 * @Author: Chester
 * @Date: 2021-11-27 14:32:27
 * @LastEditors: Chester
 * @LastEditTime: 2021-11-27 17:55:03
 */

#include <iostream>
#include "WorkerManage.h"
#include "Worker.h"
#include "Staff.h"
#include "Boss.h"
#include "Manager.h"

int main(void)
{
    // Worker * worker = NULL;
    // worker = new Staff(1, "zhangsan", "1");
    // worker->showinfo();

    // Worker * manager = NULL;
    // manager = new Manager(1, "zhangsan", "1");
    // manager->showinfo();

    // Worker *  boss = NULL;
    // boss = new Boss(1, "zhangsan", "1");
    // boss->showinfo();

    int choice = 0;
    WorkerManage workermanage;

    while (1)
    {
        workermanage.showmenu();
        std::cout << "请输入选择：";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            workermanage.quitsystem();
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            system("CLS");
            break;
        }
    }
    

    return 0;
}