#pragma once
//数据库无加密版本
#include <sqlite3.h>
#include <iostream>
#include <string>

/*    SQLiteDB数据库操作类，使用示意
int main() {
    SQLiteDB database("demo.db");

    // 创建表
    if (database.createTable()) {
        std::cout << "表创建成功" << std::endl;
    }

    // 插入示例数据
    database.insertData("扫地", "今天需要扫地");
    database.insertData("拖地", "今天需要拖地");

    // 查询数据
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
            std::cerr << "无法打开数据库: " << sqlite3_errmsg(db) << std::endl;
        }
        else {
            std::cout << "数据库打开成功!" << std::endl;
        }
    }

    ~SQLiteDB() {
        if (db) {
            sqlite3_close(db);
        }
    }

    // 创建表
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
            std::cerr << "SQL错误: " << err_msg << std::endl;
            sqlite3_free(err_msg);
            return false;
        }
        return true;
    }

    // 插入数据
    bool insertData(const std::string& result, const std::string& description);

    // 查询所有数据
    void getAllResults(); lite3_finalize(stmt);
    }
};

