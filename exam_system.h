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
#define admin_role 1 //����Ա��ʶ
#define user_role 2	//������ʶ
#define no_role 0	//����Ա��ɫ��ʶ


	/*ѧϰ��¼������ͼ��ͷ�ļ�������ȫ�ֱ���ʱ������int system_role
	�������ǰ���extern���ᱨ��"int system_role" (? system_role@@3HA) �Ѿ��� main.obj �ж������
	ԭ���ǣ�����һ�����͵Ķ��ض���������������ͷ�ļ��ж�����ȫ�ֱ�����Ȼ���ڶ��Դ�ļ��а������ͷ�ļ������±������ظ����塣*/

extern int system_role;//ϵͳ��ǰ��ɫ״̬����ʼֵΪno_role,1=admin_roleΪ����Ա��2=user_roleΪ����
extern int login_state;//ϵͳ��ǰ��ɫ��¼״̬����system_role=admin_role��login_state=1��ʾ�ѳɹ���¼����1��ʾδ�ɹ���¼��system_role=user_roleʱ���ڴ洢���������id
//��¼��ʾ���棬����ʾ���������ݴ���
class show {
public:
	//int g_role = 0;//��¼��ǰ��ɫ״̬,1=admin_roleΪ����Ա��2=user_roleΪ����
	//int login_id = -1;//��ʾ��ɫ��¼״̬������ɫΪ����Աʱ��0��ʾ����ȷ���������¼������������Ч������ɫΪ�ο���Աʱ����0������ʾ����id�ţ�����������Ч
	//��ʾ�����ܿ���
	void show_main();
	//��¼������ʾ
	int show_login();//��¼������ʾ
	//������ʾ�̶���title
	void show_title();//������ʾ�̶���title
	//�ѷ�����������ʾ����Ա���棬�ɹ���Ա����й���ʵ��
	int show_admin();//������ʾ����Ա����
};

class admin_function {//����Ա��������������ʾ�����ݴ���
public:
	std::string password;
	//int g_role = 1;//��¼��ǰ��ɫ״̬
	//int login_id = -1;//��ʾ��ɫ��¼״̬������ɫΪ����Աʱ��0��ʾ����ȷ���������¼������������Ч������ɫΪ�ο���Աʱ����0������ʾ����id�ţ�����������Ч
	//�û���¼�ɹ�����ʾ����ѡ����
	int show_admin_function();
	//������ʾ�̶���title
	void show_title();
	//ϵͳ����Ա��¼���漰���ݴ���,��¼�������login_state
	int show_admin_login();
};

//����������������������������������������������������������������������������
//�������������������������������ߡ�����������������������������������
//����������������������������������������������������������������������������
void print_(std::string out);
void print_c(std::string out, std::string color);


