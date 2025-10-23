#include "exam_system.h"
#include "common_tools.h"


void admin_function::show_title() {
    std::cout << YELLOW;
    for (int i = 0; i < 20; i++) {
        std::cout << "====";
    }
    std::cout << RESET << "\n��ӭʹ��<ѡ���⿼��ϵͳ>,�����ڵĽ�ɫ�ǣ�";
    if (system_role == admin_role) {
        std::cout << MAGENTA << "����Ա" << RESET << "��ctrl+c�˳�ϵͳ" << std::endl;
    }
    else if (system_role == user_role) {
        std::cout << MAGENTA << "�ο���Ա" << RESET << "��ctrl+c�˳�ϵͳ" << std::endl;
    }
    else {
        std::cout << MAGENTA << "�ȴ���¼��" << RESET << "��ctrl+c�˳�ϵͳ" << std::endl;
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
        // ������ʾ
        for (int i = 0; i < 15; i++) {
            std::cout << "===";
        }
        std::cout << std::endl;
        std::cout << "ѡ���⿼��ϵͳ--����Աģʽ" << std::endl;
        print_c("��ѡ����", YELLOW);
        std::cout <<":\n1 �޸�����\n2 ����ϵͳ\n3 ���뿼��\n4 �����\n5 �鿴����\n6 ɾ������\n7 �˳���¼��";
        int func_select;
        // ���봦��
        if (!(std::cin >> func_select)) {
            // ����ʧ�ܣ������֣�
            std::cin.clear(); // �������״̬
            std::cin.ignore(10000, '\n'); // ������뻺����
            std::cout << "����������������֣�" << std::endl;
            std::cout << "���س�������..." << std::endl;
            std::cin.get();
            return -1;
        }

        // ��֤���뷶Χ
        if (func_select == 1) {
            //return func_select; // ������Ч�Ľ�ɫ���
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
            std::cout << "��������ȷ�Ĺ��ܱ�ţ�1��2����" << std::endl;
            std::cout << "���س�������..." << std::endl;
            std::cin.ignore(10000, '\n'); // ��ջ�����
            std::cin.get(); // �ȴ��û�����
            return -1;
        }
    }
}
int admin_function::show_admin_login() {
    // ������뻺����,�����Ļ���������ʾ"�������,���������룡"���س������������������
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    while(1){
        system("cls");
        show_title();
        std::cout << "���������Ա���루����-1�˳�����Ա��ɫ����";
        std::string input_pass = inputpassword();
        if (input_pass == "433215") {
            return 1;
        }
        else if(input_pass != "-1") {
            std::cout << "�������,���������룡";
            system("pause");
        }
        else {
            system_role = no_role;
            return -1;
        }
    }
    
}
