#include "sqlite3.h"
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

int createDB(sqlite3* db)
{
    sqlite3_stmt * stmt = NULL;
    char sql[125] = "CREATE TABLE IF NOT EXISTS student(id INTEGER PRIMARY KEY,thumbnail BLOB)";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        printf("failed to prepare: %s \n", sqlite3_errmsg(db));
        return -1;
    }
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return 0;
}


void insert(int id, sqlite3 *db)
{
    sqlite3_stmt * stmt = NULL;
    char sql[125] = "INSERT INTO student VALUES(:1)";
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_zeroblob(stmt, 1, id);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

int my_FileLength(const char* filename)
{
    FILE* fp = fopen(filename,"rb");
    fseek(fp, 0, SEEK_END);
    int length = ftell(fp);
    fclose(fp);
    return length;
}

void update(sqlite3* db, int id)
{
    int length = my_FileLength("example.png");
    sqlite3_stmt * stmt = NULL;
    char sql[125] = "UPDATE student SET thumbnail= :1 WHERE id = :2";
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
   
    sqlite3_bind_zeroblob(stmt, 1, length);
	//sqlite3_bind_blob(stmt, 1, buffer, size, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, id);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

int my_PutBlob(sqlite3* db,   // db
    const char* which_db,     // NULL
    const char* which_table,  // "student"
    const char* which_column, // "thumbnail"
    int rowid,                // 1
    const char* filename)     // "example.png"
{
    sqlite3_blob* blob = NULL;
    int rc;

    // 以READ/WRITE（1）方式打开BLOB
    rc = sqlite3_blob_open(db, which_db, which_table, which_column, rowid, 1, &blob);
    if (rc != SQLITE_OK)
    {
        printf("1 Failed to open BLOB: %s \n", sqlite3_errmsg(db));
        return -1;
    }


    // 打开文件
    FILE* fp = NULL;
    fp=fopen(filename, "rb");
    if (!fp)
    {
        printf("failed to open file: %s \n", filename);
        return -1;
    }


    // 分段写入
    char buf[256];
    int offset = 0;
    while (!feof(fp))
    {
        int n = fread(buf, 1, 256, fp);
        if (n < 0) break;
        if (n == 0) continue;


        sqlite3_blob_write(blob, buf, n, offset);
        offset += n;
    }

    // 关闭
    fclose(fp);
    sqlite3_blob_close(blob);
    return 0;
}

int my_GetBlob(sqlite3* db,
    const char* which_db,
    const char* which_table,
    const char* which_column,
    int rowid,
    const char* filename)
{
    sqlite3_blob* blob = NULL;
    int rc;


    // 以READONLY（0）方式打开BLOB
    rc = sqlite3_blob_open(db, which_db, which_table, which_column, rowid, 0, &blob);
    if (rc != SQLITE_OK)
    {
        printf("2 Failed to open BLOB: %s \n", sqlite3_errmsg(db));
        return -1;
    }


    // 打开文件
    FILE* fp =fopen(filename, "wb");
    if (!fp)
    {
        printf("failed to open file: %s \n", filename);
        return -1;
    }


    // 取得BLOB数据长度
    int blob_length = sqlite3_blob_bytes(blob);

    // 分段读取
    char buf[256];
    int offset = 0;
    while (offset < blob_length)
    {
        int size = blob_length - offset;
        if (size > 256) size = 256;

        rc = sqlite3_blob_read(blob, buf, size, offset);
        if (rc != SQLITE_OK)
        {
            printf("failed to read BLOB!\n");
            break;
        }
        fwrite(buf, 1, size, fp);
        offset += size;
    }
    printf("blob length: %d, read %d bytes .\n",
        blob_length, offset);

    // 关闭
    fclose(fp);
    sqlite3_blob_close(blob);
    return 0;
}

int main()             ////////////////
{
    sqlite3 * db = NULL;
    int rc = sqlite3_open("example.db", &db);
    if (rc != 0)
    {
        printf("创建数据库失败");
    }

    if (1)
    {
        createDB(db);
        insert(1, db);
        update(db, 1);
        my_PutBlob(db, NULL, "student", "thumbnail", 1, "example.png");
    }

    if (1)
    {
        my_GetBlob(db, NULL, "student", "thumbnail", 1, "get.jpg");
    }

    sqlite3_close(db);
    getchar();
    return 0;
}