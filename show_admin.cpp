#include "exam_system.h"
#include "common_tools.h"


void admin_function::show_title() {
    std::cout << YELLOW;
    for (int i = 0; i < 20; i++) {
        std::cout << "====";
    }
    std::cout << RESET << "\n欢迎使用<选择题考试系统>,你现在的角色是：";
    if (system_role == admin_role) {
        std::cout << MAGENTA << "管理员" << RESET << "。ctrl+c退出系统" << std::endl;
    }
    else if (system_role == user_role) {
        std::cout << MAGENTA << "参考人员" << RESET << "。ctrl+c退出系统" << std::endl;
    }
    else {
        std::cout << MAGENTA << "等待登录中" << RESET << "。ctrl+c退出系统" << std::endl;
    }
    std::cout << YELLOW;
    for (int i = 0; i < 20; i++) {
        std::cout << "====";
    }
    std::cout << RESET << std::endl;
}
int admin_function::show_admin_function() {
    while (1) {
        system("cls");
        show_title();
        // 界面显示
        for (int i = 0; i < 15; i++) {
            std::cout << "===";
        }
        std::cout << std::endl;
        std::cout << "选择题考试系统--管理员模式" << std::endl;
        print_c("请选择功能", YELLOW);
        std::cout <<":\n1 修改密码\n2 重置系统\n3 导入考试\n4 导入答案\n5 查看考试\n6 删除考试\n7 退出登录：";
        int func_select;
        // 输入处理
        if (!(std::cin >> func_select)) {
            // 输入失败（非数字）
            std::cin.clear(); // 清除错误状态
            std::cin.ignore(10000, '\n'); // 清空输入缓冲区
            std::cout << "输入错误，请输入数字！" << std::endl;
            std::cout << "按回车键继续..." << std::endl;
            std::cin.get();
            return -1;
        }

        // 验证输入范围
        if (func_select == 1) {
            //return func_select; // 返回有效的角色编号
            //change_admin_password();
        }
        else if (func_select == 2) {
            //reset_system();
        }
        else if (func_select == 3) {
            std::string path;
            //import_exam(path);
        }
        else if (func_select == 4) {
            //import_answer_key();
        }
        else if (func_select == 5) {
            //view_exams();
        }
        else if (func_select == 6) {
            //delete_exam();
        }
        else if (func_select == 7) {
            system_role = no_role;
            login_state = -1;
            return -1;
        }
        else {
            std::cout << "请输入正确的功能编号（1或2）！" << std::endl;
            std::cout << "按回车键继续..." << std::endl;
            std::cin.ignore(10000, '\n'); // 清空缓冲区
            std::cin.get(); // 等待用户按键
            return -1;
        }
    }
}
int admin_function::show_admin_login() {
    // 清空输入缓冲区,不做的话，会先显示"密码错误,请重新输入！"，回车后才能重新输入密码
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    while(1){
        system("cls");
        show_title();
        std::cout << "请输入管理员密码（输入-1退出管理员角色）：";
        std::string input_pass = inputpassword();
        if (input_pass == "433215") {
            return 1;
        }
        else if(input_pass != "-1") {
            std::cout << "密码错误,请重新输入！";
            system("pause");
        }
        else {
            system_role = no_role;
            return -1;
        }
    }
    
}
