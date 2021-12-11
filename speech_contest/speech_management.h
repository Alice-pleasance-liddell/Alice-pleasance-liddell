/*
 * @Descripttion: 
 * @version: 
 * @Author: Chester
 * @Date: 2021-12-10 14:51:03
 * @LastEditors: Chester
 * @LastEditTime: 2021-12-11 14:54:39
 */

#ifndef _SPEECH_H_
#define _SPEECH_H_

#include <iostream>
#include <vector>
#include <map>
#include "Speaker.h"

class SpeechManagement
{
public:
    explicit SpeechManagement();
    ~SpeechManagement();

    std::vector<int> v1;    //第一轮12位选手容器
    std::vector<int> v2;    //第二轮6位选手容器
    std::vector<int> v3;    //前三名容器
    std::map<int, Speaker> mSperker;    //选手信息容器
    std::map<int, std::vector<std::string>> mRecord; //往届记录容器

    int mIndex; //第几轮
    bool fileIsEmpty; //文件是否为空

    void initSpeech();  //初始化函数声明
    void showMenu();    //主菜单函数声明
    void CreatSpeaker(); //创建选手函数声明
    void quit();        //退出函数声明
    void starSpeech();  //开始流程函数声明
    void draw();    //抽签函数声明
    void speechContest();   //比赛函数声明
    void showSocre();   //显示晋级结果声明
    void saveRecord();  //保存记录函数声明
    void loadRecord();  //读取记录函数声明
    void showRecord();  //显示往届记录函数声明
    void delRecord();   //清空记录函数声明
};

#endif