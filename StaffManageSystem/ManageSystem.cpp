/*
 * @Descripttion:  主函数
 * @version: 
 * @Author: Chester
 * @Date: 2021-11-27 14:32:27
 * @LastEditors: Chester
 * @LastEditTime: 2021-11-30 17:55:14
 */

#include <iostream>
#include "header/WorkerManage.h"
#include "header/Worker.h"
#include "header/Staff.h"
#include "header/Boss.h"
#include "header/Manager.h"

int main(void)
{
    int choice = 0;
    WorkerManage workermanage;

    while (1)
    {
        workermanage.showmenu();
        std::cout << "请输入选择：";
        std::cin >> choice;

        if (std::cin.good() && choice >=0 && choice <=9) {
            switch (choice)
            {
            case 0:
                workermanage.quitsystem();
                break;
            case 1:
                workermanage.addworker();
                break;
            case 2:
                workermanage.showstaffinfo();
                break;
            case 3:
                workermanage.delstaffinfo();
                break;
            case 4:
                workermanage.modifystaff();
                break;
            case 5:
                workermanage.findstaff();
                break;
            case 6:
                workermanage.sortstaffid();
                break;
            case 7:
                workermanage.cleanfile();
                break;
            default:
                system("CLS");
                break;
            }
        } else {
            std::cout << "请输入正确选项。\n";
            std::cin.clear();
            std::fflush(stdin);
            std::cin.get();
        }//end if
    } //end while
    

    return 0;
}