//#pragma once
#include <iostream>
#include <string>
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define admin_role 1 //管理员标识
#define user_role 2	//考生标识
#define no_role 0	//无人员角色标识


	/*学习记录：当试图在头文件中声明全局变量时，例如int system_role
	如果不在前面加extern，会报出"int system_role" (? system_role@@3HA) 已经在 main.obj 中定义错误
	原因是：这是一个典型的多重定义错误。问题出现在头文件中定义了全局变量，然后在多个源文件中包含这个头文件，导致变量被重复定义。*/

extern int system_role;//系统当前角色状态，初始值为no_role,1=admin_role为管理员，2=user_role为考生
extern int login_state;//系统当前角色登录状态，当system_role=admin_role，login_state=1表示已成功登录，非1表示未成功登录。system_role=user_role时用于存储考生输入的id
//登录显示界面，仅显示，不做数据处理
class show {
public:
	//int g_role = 0;//记录当前角色状态,1=admin_role为管理员，2=user_role为考生
	//int login_id = -1;//表示角色登录状态，当角色为管理员时，0表示已正确输入密码登录，其他数字无效。当角色为参考人员时，非0正数表示他的id号，其他数字无效
	//显示界面总控制
	void show_main();
	//登录界面显示
	int show_login();//登录界面显示
	//用于显示固定的title
	void show_title();//用于显示固定的title
	//已放弃：用于显示管理员界面，由管理员类进行功能实现
	int show_admin();//用于显示管理员界面
};

class admin_function {//管理员功能区，包括显示和数据处理
public:
	std::string password;
	//int g_role = 1;//记录当前角色状态
	//int login_id = -1;//表示角色登录状态，当角色为管理员时，0表示已正确输入密码登录，其他数字无效。当角色为参考人员时，非0正数表示他的id号，其他数字无效
	//用户登录成功后显示功能选择区
	int show_admin_function();
	//用于显示固定的title
	void show_title();
	//系统管理员登录界面及数据处理,登录结果返回login_state
	int show_admin_login();
};

//——————————————————————————————————————
//——————————————工具——————————————————
//——————————————————————————————————————
void print_(std::string out);
void print_c(std::string out, std::string color);


