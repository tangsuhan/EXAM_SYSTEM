#pragma once

#include <iostream>
#include <string>
#include <limits>


#ifdef _WIN32 //��ƽ̨����
	#include <Windows.h>
	#include <conio.h>
#else
	#include <termios.h>
	#include <unistd.h>
#endif

//����������������������������������������������������������������
//����������������������������������������������������������������

std::string inputpassword();//�������빤�ߣ�ʹ���벻�ɼ�