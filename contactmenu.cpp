#include <iostream>
#include <string>
#include <regex>
#define MAXitme 1000
void ShowMenu(void);
void Quitmenu(void);
void ShowContact(struct contactmenu * contactmenu);
void addcontacter(struct contactmenu * contactmenu);
void DeleteContact(struct contactmenu * contactmenu);
void ModifyContacter(struct contactmenu * contactmenu);
int FoundContact(struct contactmenu * contactmenu, std::string name);
void ModifyName(struct contactmenu * contactmenu, int flag);
void ModifySex(struct contactmenu * contactmenu, int flag);
void Modifyage(struct contactmenu * contactmenu, int flag);
void ModifyPhoneNumber(struct contactmenu * contactmenu, int flag);
void ModifyAddress(struct contactmenu * contactmenu, int flag);
void Nullcontact(struct contactmenu * contactmenu);

struct contacter
{
    int age;
    int sex;
    std::string name;
    std::string phonenumber;
    std::string address;
};

struct contactmenu
{
    int size;
    struct contacter contacterarray[MAXitme];
};

int main(void) 
{
    int select = 0;
    std::string name;
    contactmenu contactmenu;
    contactmenu.size = 0;

    while(1)
    {
        ShowMenu();
        std::cout << "请选择：" << " ";
        std::cin >> select;
        
        switch (select)
        {
            case 1:         //1.显示通讯录
                ShowContact(&contactmenu);
                break;
            case 2:         //2.添加联系人
                addcontacter(&contactmenu);
                break;
            case 3:         //3.查找联系人
                std::cout << "请输入查找的姓名：";
                std::cin >> name;
                FoundContact(&contactmenu, name);
                std::cin.get();
                std::cin.get();
                system("CLS");
                break;
            case 4:         //4.删除联系人
                DeleteContact(&contactmenu);
                break;
            case 5:         //5.修改联系人
                ModifyContacter(&contactmenu);
                break;
            case 6:         //6.清空通讯录
                Nullcontact(&contactmenu);
                break;
            case 7:         //7.退出通讯录
                Quitmenu();
                return 0;
                break;
            default:
                break;
        }
    }

    return 0;
}

void ShowMenu (void)
{
    std::cout << "1.显示通讯录" << "\n";
    std::cout << "2.添加联系人" << "\n";
    std::cout << "3.查找联系人" << "\n";
    std::cout << "4.删除联系人" << "\n";
    std::cout << "5.修改联系人" << "\n";
    std::cout << "6.清空通讯录" << "\n";
    std::cout << "7.退出通讯录" << "\n";
}

void Quitmenu(void)
{
    std::cout << "Bye." << "\n";
}

void addcontacter(struct contactmenu * contactmenu)
{
    int flag = contactmenu->size;

    if (contactmenu->size == MAXitme) {
        std::cout << "通讯录已满！" << "\n";
        return;
    } else {
        ModifyName(contactmenu, flag);
        ModifySex(contactmenu, flag);
        Modifyage(contactmenu, flag);
        ModifyPhoneNumber(contactmenu, flag);
        ModifyAddress(contactmenu, flag);

        contactmenu->size++;
        std::cout << "添加成功！" << '\n';

        std::cin.get();
        std::cin.get();
        system("CLS");
    }
}

void ShowContact(struct contactmenu * contactmenu)
{
    if (contactmenu->size == 0)
        std::cout << "当前没有联系人！" << '\n';
    else {
        for (int i = 0; i < contactmenu->size; i++) {
            std::cout << contactmenu->contacterarray[i].name << '\t';
            std::cout << contactmenu->contacterarray[i].sex << '\t';
            std::cout << contactmenu->contacterarray[i].age << '\t';
            std::cout << contactmenu->contacterarray[i].phonenumber << '\t';
            std::cout << contactmenu->contacterarray[i].address << '\n';
        }
    }
    
    std::cin.get();
    std::cin.get();
    system("CLS");
}

void DeleteContact(struct contactmenu * contactmenu)
{
    int i;
    std::string name;

    std::cout << "请输入要修改的联系人：";
    std::cin >> name;
    i = FoundContact(contactmenu, name);

    if ( i != -1) {
        std::cout << "查询结果：成功" << '\n';
        for (i; i <= contactmenu->size; i++)
            contactmenu->contacterarray[i] = contactmenu->contacterarray[i+1];
        contactmenu->size--;
        std::cout << "删除结果：成功" << '\n';
    } else
        std::cout << "查询结果：失败" << '\n';

    std::cin.get();
    std::cin.get();
    system("CLS");
}

int FoundContact(struct contactmenu * contactmenu, std::string name)
{
    for (int i = 0; i <= contactmenu->size; i++) {
        if (contactmenu->contacterarray[i].name == name) {
            std::cout << contactmenu->contacterarray[i].name << '\t';
            std::cout << contactmenu->contacterarray[i].sex << '\t';
            std::cout << contactmenu->contacterarray[i].age << '\t';
            std::cout << contactmenu->contacterarray[i].phonenumber << '\t';
            std::cout << contactmenu->contacterarray[i].address << '\n';

            return i;
        }
    }

    return -1;
}

void ModifyContacter(struct contactmenu * contactmenu)
{
    int i, select;
    std::string name;

    std::cout << "请输入要修改的联系人：";
    std::cin >> name;
    i = FoundContact(contactmenu, name);
    if (i != -1) {
        std::cout << "请选择修改1-姓名，2-性别，3-年龄，4-电话号码，5-住址：";
        std::cin >> select;
        switch (select) {
            case 1:
                ModifyName(contactmenu, i);
                break;
            case 2:
                ModifySex(contactmenu, i);
                break;
            case 3:
                Modifyage(contactmenu, i);
                break;
            case 4:
                ModifyPhoneNumber(contactmenu, i);
                break;
            case 5:
                ModifyAddress(contactmenu, i);
                break;
            default:
                break;
        }
    } else 
        std::cout << "没有这个联系人";

    std::cin.get();
    std::cin.get();
    system("CLS");
    
}

void ModifySex(struct contactmenu * contactmenu, int flag)
{
    int sex;

    std::cout << "请输入性别：";
    std::cout << "1.男" << '\t';
    std::cout << "2.女" << ' ';
    while (1) {
        std::cin >> sex;
        if ( std::cin.good() == 1) {
            if (!(sex == 1 || sex == 2)) {
                std::cout << "请输入代码（1=男，2=女）：" << '\n';
                std::cin.clear();
                std::cin.ignore(1024, '\n');
            } else {
                contactmenu->contacterarray[flag].sex = sex;
                break;
            }
        }else {
                std::cout << "数据类型异常" << '\n';
                std::cin.clear();
                std::fflush(stdin);
        }
    }
}

void Modifyage(struct contactmenu * contactmenu, int flag)
{
    int age;

    while (1) {
        std::cout << "请输入年龄：";
        std::cin >> age;
        if (std::cin.good() == 1) {
            if (age >= 0 && age <= 120) {
                contactmenu->contacterarray[flag].age =age;
                std::fflush(stdin);
                break;
            } else
                std::cout << "年龄段异常" << '\n';
        }else {
            std::cout << "数据类型异常" << '\n';
            std::cin.clear();
            std::fflush(stdin);
        }
    }
}

void ModifyPhoneNumber(struct contactmenu * contactmenu, int flag)
{
    std::string phonenumber;

    while (1) {
        std::cout << "请输入电话：";
        std::cin >> phonenumber;
        std::regex str_reg("^1(3\\d|47|5([0-3]|[5-9])|8(0|2|[5-9]))\\d{8}$");
        if (std::regex_match(phonenumber, str_reg)) {
            contactmenu->contacterarray[flag].phonenumber = phonenumber;
            break;
        }else
            std::cout << "不是合法的电话号码" << '\n';
    }
}

void ModifyAddress(struct contactmenu * contactmenu, int flag)
{
    std::string address;

    std::cout << "请输入住址：";
    std::cin >> address;
    contactmenu->contacterarray[flag].address = address;
}

void ModifyName(struct contactmenu * contactmenu, int flag)
{
    std::string name;

    std::cout << "请输入姓名：";
    std::cin >> name;
    contactmenu->contacterarray[flag].name = name;
}

void Nullcontact(struct contactmenu * contactmenu)
{
    contactmenu->size = 0;
    std::cout << "目录已清空" << '\n';
    std::cin.get();
    std::cin.get();
    system("CLS");
}