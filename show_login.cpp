#include "exam_system.h"
int system_role = no_role;    // 实际定义，分配内存
int login_state = -1;         // 实际定义，分配内存
void show::show_main() {
    while (1) {
        show_login();
        //根据角色编号，选择进入相应的功能区
        if (system_role == admin_role) {
            admin_function admin_login;
            login_state = admin_login.show_admin_login();
            if (login_state == 1) {
                admin_login.show_admin_function();
            }
        }
        else if (system_role == user_role) {

        }
    }
}
int show::show_login() {
    int role_temp;

    // 界面显示
    while (1) {
        system("cls");
        show_title();
        std::cout << "请选择角色:\n1 管理员\n2 参考人员\n：";

        // 输入处理
        if (!(std::cin >> role_temp)) {
            // 输入失败（非数字）
            std::cin.clear(); // 清除错误状态
            std::cin.ignore(10000, '\n'); // 清空输入缓冲区
            std::cout << "输入错误，请输入数字！" << std::endl;
            std::cout << "按回车键继续..." << std::endl;
            std::cin.get();
            return -1;
        }

        // 验证输入范围
        if (role_temp == admin_role || role_temp == user_role) {
            system_role =  role_temp; // 返回有效的角色编号
            return role_temp;
        }
        else {
            std::cout << "请输入正确的角色编号（1或2）！" << std::endl;
            std::cout << "按回车键继续..." << std::endl;
            std::cin.ignore(10000, '\n'); // 清空缓冲区
            std::cin.get(); // 等待用户按键
            return -1;
        }
    }

}
void show::show_title() {
    std::cout << YELLOW;
    for (int i = 0; i < 20; i++) {
        std::cout << "====";
    }
    std::cout << RESET << "\n欢迎使用<选择题考试系统>,你现在的角色是：";
    if (system_role == admin_role) {
        std::cout << MAGENTA << "管理员" << RESET << "。ctrl+c退出登录" << std::endl;
    }
    else if (system_role == user_role) {
        std::cout << MAGENTA << "参考人员" << RESET << "。ctrl+c退出登录" << std::endl;
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
void print_c(std::string out, std::string color) {
    std::cout << color;
    std::cout << MAGENTA << out << RESET ;
}
int show::show_admin() {//管理员登录成功界面显示
    while (1) {
        system("cls");
        show_title();
        // 界面显示
        for (int i = 0; i < 15; i++) {
            std::cout << "===";
        }
        std::cout << std::endl;
        std::cout << "选择题考试系统--管理员模式" << std::endl;
        std::cout << "请选择功能:\n1 修改密码\n2 重置系统\n3 导入考试\n4 导入答案\n5 查看考试\n6 删除考试：";
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
        else {
            std::cout << "请输入正确的功能编号（1或2）！" << std::endl;
            std::cout << "按回车键继续..." << std::endl;
            std::cin.ignore(10000, '\n'); // 清空缓冲区
            std::cin.get(); // 等待用户按键
            return -1;
        }
    }
}