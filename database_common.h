#pragma once
//���ݿ��޼��ܰ汾
#include <sqlite3.h>
#include <iostream>
#include <string>

/*    SQLiteDB���ݿ�����࣬ʹ��ʾ��
int main() {
    SQLiteDB database("demo.db");

    // ������
    if (database.createTable()) {
        std::cout << "�����ɹ�" << std::endl;
    }

    // ����ʾ������
    database.insertData("ɨ��", "������Ҫɨ��");
    database.insertData("�ϵ�", "������Ҫ�ϵ�");

    // ��ѯ����
    database.getAllResults();

    return 0;
}*/
class SQLiteDB {
private:
    sqlite3* db;
public:
    SQLiteDB(const std::string& db_name) : db(nullptr) {
        int rc = sqlite3_open(db_name.c_str(), &db);
        if (rc) {
            std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        }
        else {
            std::cout << "���ݿ�򿪳ɹ�!" << std::endl;
        }
    }

    ~SQLiteDB() {
        if (db) {
            sqlite3_close(db);
        }
    }

    // ������
    bool createTable() {
        const char* sql = R"(
            CREATE TABLE IF NOT EXISTS jieguo (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                jieguo TEXT,
                miaoshu TEXT
            )
        )";

        char* err_msg = nullptr;
        int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

        if (rc != SQLITE_OK) {
            std::cerr << "SQL����: " << err_msg << std::endl;
            sqlite3_free(err_msg);
            return false;
        }
        return true;
    }

    // ��������
    bool insertData(const std::string& result, const std::string& description);

    // ��ѯ��������
    void getAllResults(); lite3_finalize(stmt);
    }
};

