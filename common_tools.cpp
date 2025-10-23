#include "common_tools.h"

// �����ն����벻����
void setStdinEcho(bool enable = true) {
#ifdef _WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    if (!enable)
        mode &= ~ENABLE_ECHO_INPUT;
    else
        mode |= ENABLE_ECHO_INPUT;
    SetConsoleMode(hStdin, mode);
#else
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if (!enable)
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}

std::string inputpassword() {
    std::string password;

    //std::cout << "����������: ";

    // �رջ���
    setStdinEcho(false);

    // ��ȡ����
    std::getline(std::cin, password);

    // �ָ�����
    setStdinEcho(true);

    std::cout << std::endl;
    return password;
}