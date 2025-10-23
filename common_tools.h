#pragma once

#include <iostream>
#include <string>
#include <limits>


#ifdef _WIN32 //睡峠岬圭宛
	#include <Windows.h>
	#include <conio.h>
#else
	#include <termios.h>
	#include <unistd.h>
#endif

//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
//！！！！！！垢醤曝！！！！！！！！！！！！！！！！！！！！！！！

std::string inputpassword();//畜鷹補秘垢醤�妻絞簇覯賛票�