/*
 * @Descripttion: 
 * @version: 
 * @Author: Chester
 * @Date: 2021-12-10 14:48:52
 * @LastEditors: Chester
 * @LastEditTime: 2021-12-11 18:19:57
 */

#include "speech_management.h"
#include <algorithm>
#include <deque>
#include <random>
#include <ctime>
#include <functional>
#include <numeric>
#include <fstream>


/**
 * @brief: 构造函数
 * @param {*}
 * @return {*}
 */
SpeechManagement::SpeechManagement()
{
    //初始化容器与属性
    initSpeech();
    CreatSpeaker();
    loadRecord();
}


/**
 * @brief: 析构函数
 * @param {*}
 * @return {*}
 */
SpeechManagement::~SpeechManagement()
{
    
}


/**
 * @brief: 主菜单函数实现
 * @param {*}
 * @return {*}
 */
void SpeechManagement::showMenu()
{
	std::cout << "********************************************" << '\n';
	std::cout << "*************  欢迎参加演讲比赛 ************" << '\n';
	std::cout << "*************  1.开始演讲比赛  *************" << '\n';
	std::cout << "*************  2.查看往届记录  *************" << '\n';
	std::cout << "*************  3.清空比赛记录  *************" << '\n';
	std::cout << "*************  0.退出比赛程序  *************" << '\n';
	std::cout << "********************************************" << '\n' << '\n';
}


/**
 * @brief: 退出函数实现
 * @param {*}
 * @return {*}
 */
void SpeechManagement::quit()
{
    std::cout << "Welcome to next time, Bye!";
    
    exit(0);
}


/**
 * @brief: 初始化函数实现，置空容器，属性
 * @param {*}
 * @return {*}
 */
void SpeechManagement::initSpeech()
{
    v1.clear();
    v2.clear();
    v3.clear();
    mSperker.clear();
    mRecord.clear();

    mIndex = 1;
}


/**
 * @brief: 创建选手函数实现
 * @param {*}
 * @return {*}
 */
void SpeechManagement::CreatSpeaker()
{
    std::string nameSeed = "ABCDEFGHIJKL";  //选手名称种子

    //初始化选手信息容器，第一轮选手编号容器
    for (int i = 0; i < nameSeed.size(); i++) {
        Speaker sp;

        std::string name = "选手: ";
        name += nameSeed[i];
        sp.mName = name;

        for (int j = 0; j < 2; j++)
            sp.mScore[j] = 0;

        v1.push_back(i + 10001); //第一轮选手编号容器
        mSperker.insert(std::make_pair(i + 10001, sp)); //选手信息map

    }
}


/**
 * @brief: 开始流程函数实现
 * @param {*}
 * @return {*}
 */
void SpeechManagement::starSpeech()
{
    //抽签
    draw();
    //比赛
    speechContest();
    //显示晋级结果
    showSocre();
    //第二轮比赛
    mIndex++;
    //抽签
    draw();
    //比赛
    speechContest();
    //显示晋级结果
    showSocre();
    //保存记录
    saveRecord();
    loadRecord();

    //重置比赛
    initSpeech();
    CreatSpeaker();


    std::cout << "本届比赛完毕" << '\n';
    std::cin.get();
    system("CLS");
}


/**
 * @brief: 抽签函数实现
 * @param {*}
 * @return {*}
 */
void SpeechManagement::draw()
{
    std::cout << "第 " << mIndex << " 轮比赛选手抽签..." << '\n';
    std::cout << "抽签后演讲顺序如下: " << '\n';

    std::random_device rd;
    std::mt19937 g(rd());

    if (mIndex == 1)
    {
        std::shuffle(v1.begin(), v1.end(), g);
        for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
            std::cout << *it << " ";
    } else {
        std::shuffle(v2.begin(), v2.end(), g);
        for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
            std::cout << *it << " ";
    } //end if

    std::cout << '\n';
    std::cin.get();
    std::cin.get();
}


/**
 * @brief: 比赛函数实现
 * @param {*}
 * @return {*}
 */
void SpeechManagement::speechContest()
{
    std::cout << "---------第 " << mIndex << " 轮比赛正式开始---------" << '\n';

    std::multimap<double, int, std::greater<double>> groupScore;
    int num = 0;
    std::vector<int> vSrc;

    //第几轮
    if (mIndex == 1)
    {
        vSrc = v1;
    } else {
        vSrc = v2;
    }

    //选手进行比赛
    for (std::vector<int>::iterator it = vSrc.begin(); it != vSrc.end(); it++)
    {
        std::deque<double> d;
        num++;

        //评委随机打分
        std::random_device rd;  //linux真随机
        std::default_random_engine e1(rd()); //linux
        //std::minstd_rand e1(std::time(NULL)); //msvn才能真随机
        std::uniform_int_distribution<int> dist(600, 1000); //600 -1000
        for (int i = 0; i < 10; i++) {
            double score = dist(e1) / 10.0;
            std::cout << score << " ";
            d.push_back(score);
        } //end for
        std::cout << '\n';

        std::sort(d.begin(), d.end(), std::greater<double>()); //sort
        d.pop_back();
        d.pop_front();

        double sum = 0.0; //total score
        double avg = 0.0; //average score
        sum = std::accumulate(d.begin(), d.end(), 0.0f);
        avg = (int)(((sum / (double)d.size()) + 0.005) * 100) / 100.00;
        mSperker[*it].mScore[mIndex-1] = avg;

        //取前三
        groupScore.insert(std::make_pair(avg, *it));

        if (num % 6 == 0) {
            int count = 0;
            std::cout << "第 " << num / 6 << " 小组比赛名次：\n";

            for (std::multimap<double, int, std::greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {
                std::cout << "编号: " << it->second << " 姓名: " << mSperker[it->second].mName << " 成绩: " << mSperker[it->second].mScore[mIndex - 1] << '\n';

                if (mIndex == 1 && count < 3) {
                    v2.push_back((*it).second);
                    count++;
                } else if (mIndex == 2 && count < 3) {
                    v3.push_back((*it).second);
                    count++;
                } //end if
            } //end for

            groupScore.clear();
        } //end if
    } // end for
    std::cout << "第 " << mIndex << " 轮比赛完结\n";
}


/**
 * @brief:  显示晋级结果
 * @param {*}
 * @return {*}
 */
void SpeechManagement::showSocre()
{
    std::cout << "第 " << mIndex << " 轮晋级选手如下: " << '\n';

    std::vector<int> v;
    if (mIndex == 1) {
        v = v2;
    } else {
        v = v3;
    }

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        std::cout << "id: " << *it << " name: " << mSperker[*it].mName << " score: " << mSperker[*it].mScore[mIndex - 1] << '\n';
}


/**
 * @brief: 保存记录函数实现
 * @param {*}
 * @return {*}
 */
void SpeechManagement::saveRecord()
{
    std::ofstream ofs("speech.csv", std::ios::out | std::ios::app);

    for (std::vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
    {
        ofs << *it << "," << mSperker[*it].mScore[1] << ",";
    }
    ofs << '\n';
    ofs.close();
    std::cout << "记录已保存";

    fileIsEmpty = false;
}


/**
 * @brief: //加载往届记录函数实现
 * @param {*}
 * @return {*}
 */
void SpeechManagement::loadRecord()
{
    std::ifstream ifs("speech.csv", std::ios::in);

    if (!ifs.is_open()) {
        fileIsEmpty = true;
        ifs.close();

        return;
    } //end if

    if (ifs.peek() == EOF) {   
        fileIsEmpty = true;
        ifs.close();

        return;
    } //end if
    
    fileIsEmpty = false;
    int index = 1;
    std::vector<std::string> v;
    std::string data = "";

    while (ifs >> data) {
        int pos = -1;
        int start = 0;
        
        while (1) {
            pos = data.find(",", start);
            if (pos == -1) {
                break;
            }

            v.push_back(data.substr(start, pos - start));
            start = pos + 1;
        }

        mRecord.insert(make_pair(index, v));
        index++;
    } //end while

    ifs.close();
}



/**
 * @brief: 显示往届记录函数实现
 * @param {*}
 * @return {*}
 */
void SpeechManagement::showRecord()
{
    if (fileIsEmpty == true) {
        std::cout << "file is NULL or is not exist";

    }
    else {
        int i = 0;

        for (std::map<int, std::vector<std::string>>::iterator it = mRecord.begin(); it != mRecord.end(); it++, i += 2) {
            std::cout << it->first << "冠军: " << it->second[i] << " 得分: " << it->second[i + 1] << '\n';
            //std::cout << mRecord[i][0];
        }

    }
    
    std::cin.get();
    std::cin.get();
    system("CLS");
}


/**
 * @brief: 清空记录函数实现
 * @param {*}
 * @return {*}
 */
void SpeechManagement::delRecord()
{
    int choose = 0;

    std::cout << "确认清空？" << '\n';
    std::cout << "1.是\t2.否" << '\n';
    std::cin >> choose;

    if (std::cin.good() && choose >= 1 && choose <= 2) {
        if (choose == 1) {
            std::ofstream ofs("speech.csv", std::ios::trunc);
            std::cout << "ok\n" ;

            initSpeech();
            CreatSpeaker();
            loadRecord();

            ofs.close();
        }
        else
            system("CLS");
            return;
    } else {
        system("CLS");
        return;
    } //end if

}
