#include <string>
#include <fstream>
#include <iostream>
#include "sqlite3.h"

using namespace std;

int InsertFile(const string& db_name)
{
    ifstream file("example.png", ios::in | ios::binary);
    if (!file) 
	{
        cerr << "An error occurred opening the file\n";
        return -1;
    }
    file.seekg(0, ifstream::end);
    streampos size = file.tellg();
    file.seekg(0);

    char* buffer = new char[size];
    file.read(buffer, size);

    sqlite3 *db = NULL;
    int rc = sqlite3_open(db_name.c_str(), &db);
    if (rc != SQLITE_OK) 
	{
        cerr << "db open failed: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);		
		return -1;
    } 

	sqlite3_stmt *stmt = NULL;
	rc = sqlite3_prepare_v2(db,
							"INSERT INTO TEST(path,real)"
							" VALUES('/data/data/xx',?)",
							-1, &stmt, NULL);
	if (rc != SQLITE_OK) 
	{
		cerr << "prepare failed: " << sqlite3_errmsg(db) << endl;
		return -1;			
	} 

	// SQLITE_STATIC because the statement is finalized
	// before the buffer is freed:
	rc = sqlite3_bind_blob(stmt, 1, buffer, size, SQLITE_STATIC);
	if (rc != SQLITE_OK) 
	{
		cerr << "bind failed: " << sqlite3_errmsg(db) << endl;
		return -1;
	} 
	else 
	{
		rc = sqlite3_step(stmt);
		if (rc != SQLITE_DONE)
		{
			cerr << "execution failed: " << sqlite3_errmsg(db) << endl;					
			return -1;
		}
	}

	sqlite3_finalize(stmt);
    sqlite3_close(db);

    delete[] buffer;
	return 0;
}

int main(void)
{
	string dbName="temp.db";
	return InsertFile(dbName);
}

