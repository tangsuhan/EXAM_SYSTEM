#include "exam_system.h"

void show::show_main() {
    while (1) {
        show_login();
        //���ݽ�ɫ��ţ�ѡ�������Ӧ�Ĺ�����
        if (g_role == 1) {

        }
        else if (g_role == 2) {

        }
    }
}
int show::show_login() {
    int role_temp;

    // ������ʾ
    while (1) {
        system("cls");
        show_title();
        std::cout << "��ѡ���ɫ:\n1 ����Ա\n2 �ο���Ա\n��";

        // ���봦��
        if (!(std::cin >> role_temp)) {
            // ����ʧ�ܣ������֣�
            std::cin.clear(); // �������״̬
            std::cin.ignore(10000, '\n'); // ������뻺����
            std::cout << "����������������֣�" << std::endl;
            std::cout << "���س�������..." << std::endl;
            std::cin.get();
            return -1;
        }

        // ��֤���뷶Χ
        if (role_temp == 1 || role_temp == 2) {
            this->g_role =  role_temp; // ������Ч�Ľ�ɫ���
            return role_temp;
        }
        else {
            std::cout << "��������ȷ�Ľ�ɫ��ţ�1��2����" << std::endl;
            std::cout << "���س�������..." << std::endl;
            std::cin.ignore(10000, '\n'); // ��ջ�����
            std::cin.get(); // �ȴ��û�����
            return -1;
        }
    }

}
void show::show_title() {
    std::cout << YELLOW;
    for (int i = 0; i < 20; i++) {
        std::cout << "===";
    }
    std::cout << RESET << "\n��ӭʹ��<ѡ���⿼��ϵͳ>,�����ڵĽ�ɫ�ǣ�";
    if (g_role == 1) {
        std::cout << MAGENTA << "����Ա" << RESET << "��ctrl+c�˳���¼" << std::endl;
    }
    else if (g_role == 2) {
        std::cout << MAGENTA << "�ο���Ա" << RESET << "��ctrl+c�˳���¼" << std::endl;
    }
    else {
        std::cout << MAGENTA << "�ȴ���¼��" << RESET << "��ctrl+c�˳�ϵͳ" << std::endl;
    }
    std::cout << YELLOW;
    for (int i = 0; i < 20; i++) {
        std::cout << "===";
    }
    std::cout << RESET << std::endl;
}

int show::show_admin() {//����Ա��¼�ɹ�������ʾ
    while (1) {
        system("cls");
        show_title();
        // ������ʾ
        for (int i = 0; i < 15; i++) {
            std::cout << "===";
        }
        std::cout << std::endl;
        std::cout << "ѡ���⿼��ϵͳ--����Աģʽ" << std::endl;
        std::cout << "��ѡ����:\n1 �޸�����\n2 ����ϵͳ\n3 ���뿼��\n4 �����\n5 �鿴����\n6 ɾ�����ԣ�";
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
        else {
            std::cout << "��������ȷ�Ĺ��ܱ�ţ�1��2����" << std::endl;
            std::cout << "���س�������..." << std::endl;
            std::cin.ignore(10000, '\n'); // ��ջ�����
            std::cin.get(); // �ȴ��û�����
            return -1;
        }
    }
}