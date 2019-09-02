#pragma once
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include "sqlite3.h"

const char* ofDB = "of.db";
const char* img = "example.png";
const char* modelKey = "M1543196989607";
const char* path = "/data/data/cc.xx.yy/3.glb";

class OfSqlOperate
{

public:

    static int sqlite3_db_blob_insert(const char* ofDB, const char* img, const char* modelKey, const char* path);    

    static int sqlite3_db_table_exist(const char *dbfile, const char *tablename);
   
    static int sqlite3_db_create(const char* ofDB, const char* modelKey);
    
    static int sqlite3_db_blob_select(const char* ofDB, const char* modelKey, const char* path);

};