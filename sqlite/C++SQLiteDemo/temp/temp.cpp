// temp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include "sqlite3.h"
#include <fstream>
#include <iostream>
using namespace std;


int InsertFile(const string& db_name)
{
    ifstream file("1.jpg", ios::in | ios::binary);
    if (!file) {
        cerr << "An error occurred opening the file\n";
        return 12345;
    }
    file.seekg(0, ifstream::end);
    streampos size = file.tellg();
    file.seekg(0);

    char* buffer = new char[size];
    file.read(buffer, size);

    sqlite3 *db = NULL;
    int rc = sqlite3_open_v2(db_name.c_str(), &db, SQLITE_OPEN_READWRITE, NULL);
    if (rc != SQLITE_OK) {
        cerr << "db open failed: " << sqlite3_errmsg(db) << endl;
    } else {
        sqlite3_stmt *stmt = NULL;
        rc = sqlite3_prepare_v2(db,
                                "INSERT INTO TEST(ID, FILE)"
                                " VALUES(NULL, ?)",
                                -1, &stmt, NULL);
        if (rc != SQLITE_OK) {
            cerr << "prepare failed: " << sqlite3_errmsg(db) << endl;
        } else {
            // SQLITE_STATIC because the statement is finalized
            // before the buffer is freed:
            rc = sqlite3_bind_blob(stmt, 1, buffer, size, SQLITE_STATIC);
            if (rc != SQLITE_OK) {
                cerr << "bind failed: " << sqlite3_errmsg(db) << endl;
            } else {
                rc = sqlite3_step(stmt);
                if (rc != SQLITE_DONE)
                    cerr << "execution failed: " << sqlite3_errmsg(db) << endl;
            }
        }
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);

    delete[] buffer;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string dbName="test.db";
	InsertFile(dbName);
	return 0;
}

