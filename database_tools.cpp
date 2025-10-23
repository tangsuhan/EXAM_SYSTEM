#include "database_common.h"

// ������
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
        std::cerr << "SQL����: " << err_msg << std::endl;
        sqlite3_free(err_msg);
        return false;
    }
    return true;
}

// ��������
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

// ��ѯ��������
void SQLiteDB::getAllResults() {
    const char* sql = "SELECT * FROM jieguo";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        return;
    }

    std::cout << "�������ݣ�" << std::endl;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* jieguo = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        const char* miaoshu = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

        std::cout << "ID:" << id << " ���:" << jieguo << " ����:" << miaoshu << std::endl;
    }

    sqlite3_finalize(stmt);
}