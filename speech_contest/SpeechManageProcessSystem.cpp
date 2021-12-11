/*
 * @Descripttion: 
 * @version: 
 * @Author: Chester
 * @Date: 2021-12-10 15:10:50
 * @LastEditors: Chester
 * @LastEditTime: 2021-12-11 18:20:48
 */

#include <iostream>
#include "speech_management.h"

int main(void)
{
    SpeechManagement sm;
    int choose = 0;

    sm.showMenu();
    while (1)
    {
        std::cout << "Please input your choose: ";
        std::cin >> choose;

        if (std::cin.good() && choose >= 0 && choose <= 3)
        {    
            switch (choose)
            {
            case 1: // begin match
                sm.starSpeech();
                break;
            case 2: //show lastest match record
                sm.showRecord();
                break;
            case 3: // clear match record
                sm.delRecord();
                break;
            case 0:
                sm.quit();
                break;
            default:
                system("CLS");
                break;
            } //end switch
        } else {
            std::cout << "Error type or Invalid value.\n";

            std::cin.clear();
            std::fflush(stdin);
            continue;
        } // end if

        sm.showMenu();
    } //end while

    return 0;
}