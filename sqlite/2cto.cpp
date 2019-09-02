#include "sqlite3.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <string.h>
 
#define DEMO_DB     "demo.db"
#define DEMO_TABLE  "bb"
 
struct employee_s {
    int empno;
    char ename[32];
    char job[16];
    int deptno;
};
 
int sqlite3_db_blob_insert()
{
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    char sql[1024]={0};
    int ret = 0;
    struct employee_s emp = {1, "tom", "programmer", 1035};
	do
	{
		ret = sqlite3_open(DEMO_DB, &db);
		if (ret != SQLITE_OK) {
			fprintf(stderr, "db open fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
			sqlite3_close(db);
			ret=-1;
			break;
		}
	 
		memset(sql, 0, sizeof(sql));
		sprintf(sql, "insert into %s values(?, ?)", DEMO_TABLE);
		printf("sql insert: \"%s\"\n", sql);
		ret = sqlite3_prepare(db, sql, strlen(sql), &stmt, NULL);
		if (ret != SQLITE_OK) {
			fprintf(stderr, "db prepare fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
			sqlite3_close(db);
			ret=-1;
			break;
		}
	 
		/* 绑定id值 */
		ret = sqlite3_bind_int(stmt, 1, 1001);
		if (ret != SQLITE_OK) {
			fprintf(stderr, "db bind fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
			sqlite3_close(db);
			ret=-1;
			break;
		}
	 
		/* 绑定content值 */
		ret = sqlite3_bind_blob(stmt, 2, &emp, sizeof(emp), NULL);
		if (ret != SQLITE_OK) {
			fprintf(stderr, "db bind fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
			sqlite3_close(db);
			ret=-1;
			break;
		}
	 
		ret = sqlite3_step(stmt);
		if (ret != SQLITE_DONE) {
			fprintf(stderr, "db insert fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
			sqlite3_close(db);
			ret=-1;
		}
    }while(0);
	
    sqlite3_finalize(stmt);
    return ret;
}
 
int sqlite3_db_blob_select()
{
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    char sql[1024]={0};
    int ret = 0;
 
    ret = sqlite3_open(DEMO_DB, &db);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "db open fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }
 
    memset(sql, 0, sizeof(sql));
    sprintf(sql, "select id, content from %s", DEMO_TABLE);
    printf("sql select: \"%s\"\n", sql);
    ret = sqlite3_prepare(db, sql, strlen(sql), &stmt, NULL);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "db prepare fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }
 
    for ( ; ; ) {
        ret = sqlite3_step(stmt);
        if (ret == SQLITE_ROW) {
            int id, len;
            void *content = NULL;
            struct employee_s *emp = NULL;
            int empno, deptno;
            char ename[32], job[16];
 
            /* 索引从0开始 */
            id = sqlite3_column_int(stmt, 0);
            content = (void *)sqlite3_column_blob(stmt, 1);
            len = sqlite3_column_bytes(stmt, 1);
            emp = (struct employee_s *)content;
            empno = emp->empno;
            strcpy(ename, emp->ename);
            strcpy(job, emp->job);
            deptno = emp->deptno;
 
            printf("len=%d, sizeof(employee_s)=%d\n", len, sizeof(struct employee_s));
            printf("id=%d, empno=%d, ename=%s, job=%s, deptno=%d\n",
                    id, empno, ename, job, deptno);
        } else if (ret == SQLITE_DONE) {
            printf("select done!\n");
            break;
        } else {
            fprintf(stderr, "db step fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
            break;
        }
    }
 
    sqlite3_finalize(stmt);
    return 0;
}
 
int sqlite3_db_table_exist(char *dbfile, const char *tablename)
{
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    char sql[1024]={0};
    int ret = 0, rows = 0;
 
    ret = sqlite3_open(dbfile, &db);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "db open fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
        sqlite3_close(db);
        return 0;
    }
 
    memset(sql, 0, sizeof(sql));
    sprintf(sql, "select count(1) from sqlite_master where type='table' and name='%s'", tablename);
    ret = sqlite3_prepare(db, sql, strlen(sql), &stmt, NULL);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "db prepare fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }
 
    ret = sqlite3_step(stmt);
    if (ret == SQLITE_ROW)  {
        rows = sqlite3_column_int(stmt, 0);
    } else if (ret == SQLITE_DONE) {
        printf("no data!\n");
        rows = 0;
    } else {
        fprintf(stderr, "db step fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
        rows = 0;
    }
 
    sqlite3_finalize(stmt);
    sqlite3_close(db);
 
    if (rows > 0) {
        return 1;
    } else {
        return 0;
    }
}
 
int sqlite3_db_create()
{
    sqlite3 *db = NULL;
    char sql[1024]={0};
    char *errmsg = NULL;
    int ret = 0;
 
    if (sqlite3_db_table_exist(DEMO_DB, DEMO_TABLE)) {
        printf("table exist\n");
        return 0;
    }
 
    ret = sqlite3_open(DEMO_DB, &db);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "db open fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }
 
    memset(sql, 0, sizeof(sql));
    sprintf(sql, "create table %s ("\
                 "id int(4) not null, "\
                 "content blob)", DEMO_TABLE);
 
    printf("sql create: \"%s\"\n", sql);
    ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "create table fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
        sqlite3_free(errmsg);
        errmsg = NULL;
        sqlite3_close(db);
        return -1;
    }
 
    sqlite3_close(db);
    return 0;
}
 
int main()
{
    sqlite3_db_create();
    sqlite3_db_blob_insert();
    sqlite3_db_blob_select();
    return 0;
}