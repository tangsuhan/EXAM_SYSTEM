#include "database_common.h"

// 创建表
bool SQLiteDB::createTable() {
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
bool SQLiteDB::insertData(const std::string& result, const std::string& description) {
    const char* sql = "INSERT INTO jieguo (jieguo, miaoshu) VALUES (?, ?)";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, result.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, description.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    return rc == SQLITE_DONE;
}

// 查询所有数据
void SQLiteDB::getAllResults() {
    const char* sql = "SELECT * FROM jieguo";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        return;
    }

    std::cout << "所有数据：" << std::endl;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* jieguo = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        const char* miaoshu = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

        std::cout << "ID:" << id << " 结果:" << jieguo << " 描述:" << miaoshu << std::endl;
    }

    sqlite3_finalize(stmt);
}