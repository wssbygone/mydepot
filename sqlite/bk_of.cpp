#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <memory>
#include "sqlite3.h"
using namespace std;
 
const char* ofDB = "of.db";
const char* img = "example.png";
const char* modelKey = "M1543196989607";
const char* path = "/data/data/cc.xx.yy/3.glb";
 
int getFileLength(const char* filename)
{
    FILE* fp = fopen(filename,"rb");
    fseek(fp, 0, SEEK_END);
    int length = ftell(fp);
    fclose(fp);
    return length;
} 
 
int sqlite3_db_blob_insert(const char* ofDB, const char* img, const char* modelKey, const char* path)
{
	std::ifstream file(img, std::ios::in | std::ios::binary);
    if (!file) 
	{
        std::cerr << "An error occurred opening the file\n";
        return -1;
    }
    file.seekg(0, std::ifstream::end);
    std::streampos size = file.tellg();
    file.seekg(0);
    std::cout<<"size:"<<size<<std::endl;
    char * buffer = new char[size];		
    file.read(buffer, size);
	
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    char sql[1024]={0};
    int ret = 0;
	
	do
	{
		ret = sqlite3_open(ofDB, &db);
		if (ret != SQLITE_OK) {
			fprintf(stderr, "db open fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
			//sqlite3_close(db);
			ret=-1;
			break;
		}
	 
		sprintf(sql, "insert or replace into %s values(?, ?)", modelKey);
		printf("sql insert: \"%s\"\n", sql);
		ret = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
		if (ret != SQLITE_OK) {
			fprintf(stderr, "1 db prepare fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
			//sqlite3_close(db);
			ret=-1;
			break;
		}
	 
		/* 绑定path值 */
		ret = sqlite3_bind_text(stmt, 1, path, strlen(path), NULL);
		if (ret != SQLITE_OK) {
			fprintf(stderr, "1 db bind fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
			//sqlite3_close(db);
			ret=-1;
			break;
		}
	 
		/* 绑定data值 */
		ret = sqlite3_bind_blob(stmt, 2, buffer, size, NULL);
		if (ret != SQLITE_OK) {
			fprintf(stderr, "2 db bind fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
			//sqlite3_close(db);
			ret=-1;
			break;
		}
	 
		ret = sqlite3_step(stmt);
		if (ret != SQLITE_DONE) {
			fprintf(stderr, "db insert fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
			//sqlite3_close(db);
			ret=-1;
		}
    }while(0);
	
    sqlite3_finalize(stmt);
	sqlite3_close(db);	
    delete[] buffer;
	
    return ret;
}
 
int sqlite3_db_table_exist(const char *dbfile, const char *tablename)
{
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    char sql[1024]={0};
    int ret = 0, rows = 0;
 
    ret = sqlite3_open(dbfile, &db);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "db open fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }
 
    sprintf(sql, "select count(1) from sqlite_master where type='table' and name='%s'", tablename);
    ret = sqlite3_prepare(db, sql, strlen(sql), &stmt, NULL);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "2 db prepare fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
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
 
int sqlite3_db_create(const char* ofDB, const char* modelKey)
{
    sqlite3 *db = NULL;
    char sql[1024]={0};
    char *errmsg = NULL;
    int ret = sqlite3_db_table_exist(ofDB, modelKey);
    if ( ret>0 ) 
	{
        printf("table exist\n");
        return 0;
    }
	else if( -1==ret)
	{
		return -1;
	}
 
    ret = sqlite3_open(ofDB, &db);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "db open fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }
				 
	sprintf(sql, "CREATE TABLE IF NOT EXISTS `%s` ("\
                 "path TEXT PRIMARY KEY NOT NULL, data blob)", modelKey);				 
				 //"constraint pk_t2 PRIMARY KEY (path,data) )", modelKey);	 
 
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

int sqlite3_db_blob_select(const char* ofDB, const char* modelKey, const char* path)
{
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    char sql[1024]={0};
    int ret = SQLITE_OK;
 
    ret = sqlite3_open(ofDB, &db);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "db open fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }
 
    sprintf(sql, "select path, data from %s where path=\'%s\'", modelKey, path);
    printf("sql select: \"%s\"\n", sql);
    ret = sqlite3_prepare(db, sql, strlen(sql), &stmt, NULL);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "3 db prepare fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }	
	
    //char str[1024]={0};
	//sprintf(str,"new%d.png",cnt++);
	
    //for ( ; ; ) {	
	ret = sqlite3_step(stmt);
	if (ret == SQLITE_ROW) 
	{
		/* 索引从0开始 */
		//const unsigned char * path = sqlite3_column_text(stmt,0);
		auto path = sqlite3_column_text(stmt,0);			
		void *content =(void *)sqlite3_column_blob(stmt, 1);
		int len = sqlite3_column_bytes(stmt, 1);

		std::cout<<"path:"<<path <<" len:"<<len<<std::endl;		
		/*	
		std::ofstream file(str, std::ios::binary);
		if (!file) 
		{
			std::cerr << "An error occurred opening the file\n";
			continue;
		}
		file.write(static_cast<char*>(content), len); */
		//std::cout<<"========select row"<<std::endl;
	
	} else if (ret == SQLITE_DONE) {
		printf("select done!\n");
		//break;

	} else {
		fprintf(stderr, "db step fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
		//break;
	}
	//}
 
    sqlite3_finalize(stmt);
    return ret;
}


int sqlite3_db_del(const char* ofDB)
{
    sqlite3 *db = NULL;
	char *zErrMsg = 0;	
    sqlite3_stmt *stmt = NULL;
    char sql[1024] = { 0 };
    int ret = 0;
	const unsigned char* arr=nullptr;
	char tblName[1024]={0};

    do
    {
        ret = sqlite3_open(ofDB, &db);
        if (ret != SQLITE_OK) {
            fprintf(stderr, "db open fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
            //sqlite3_close(db);
            ret = -1;
            break;
        }
       //////////////////
        sprintf(sql, "select tbl_name from sqlite_master where type='table' limit 1");
        printf("sql : \"%s\"\n", sql);
        ret = sqlite3_prepare(db, sql, strlen(sql), &stmt, NULL);
        if (ret != SQLITE_OK) {
            fprintf(stderr, "3 db prepare fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
            //sqlite3_close(db);
            ret = -1;
            break;
        }
        ret = sqlite3_step(stmt);
        if (ret == SQLITE_ROW)
        {
            arr = sqlite3_column_text(stmt, 0);
            std::cout << "del arr: " << arr << std::endl;
			int len=0;
			for(int i=0;arr[i]!='\0';i++)
			{
				len++;
			}
			memcpy(tblName,arr,len);
        }
        else if (ret == SQLITE_DONE) 
        {
            printf("select done!\n");
        }
        else
        {
            fprintf(stderr, "db step fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
        }
        //////////////////
        sqlite3_finalize(stmt);  //??????
		
		memset(sql,0,1024);
        sprintf(sql, "DROP TABLE IF EXISTS '%s';", tblName);
        printf("sql: \"%s\"\n", sql);
		
		/*
        ret = sqlite3_prepare(db, sql,strlen(sql), &stmt, NULL);
        if (ret != SQLITE_OK) {
            fprintf(stderr, "1 db prepare fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
            ret = -1;
            break;
        }

        ret = sqlite3_step(stmt);
        if (ret != SQLITE_DONE) {
            fprintf(stderr, "db del fail, errcode[%d], errmsg[%s]\n", ret, sqlite3_errmsg(db));
			std::cout<<"del table fail"<<std::endl;			
            ret = -1;
			break;
        } */
		ret = sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);
		if( ret != SQLITE_OK ){
		  fprintf(stderr, "SQL error: %s\n", zErrMsg);
		  sqlite3_free(zErrMsg);
		}else{
		  fprintf(stdout, "Operation done successfully\n");
		}
    } while (0);

    //sqlite3_finalize(stmt);
    sqlite3_close(db);

    return ret;
}

int main()
{
    int ret=-2;
	/**/
	ret=sqlite3_db_create(ofDB, modelKey);
	std::cout<<__LINE__<<" ret:"<<ret<<"\n"<<std::endl;
	
	//ret=sqlite3_db_blob_insert(ofDB, img, modelKey, path);
	//std::cout<<__LINE__<<" ret:"<<ret << "\n"<<std::endl; 
	
    //ret=sqlite3_db_blob_select(ofDB, modelKey, path);
	//std::cout<<__LINE__<<" ret:"<<ret << "\n" <<std::endl;	
	
	sqlite3_db_del(ofDB);

    return 0;
}