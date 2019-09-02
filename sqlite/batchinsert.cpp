#include <sqlite3.h>
#include <string.h>
#include <stdio.h>
 
int main()
{
	sqlite3* conn = NULL;
	int i,nCol;
	char *name = "tag";
	char *zErrMsg;
	const char *pzTail;
	/* open */
	int result = sqlite3_open("test.db", &conn);
	if(result != SQLITE_OK){
		sqlite3_close(conn);
		return -1;
	}
 
	const char* createTableSQL = 
		"CREATE TABLE TESTTABLE(int_col INT, float_col REAL, string_col TEXT)";
	/* create prepare object*/
	if(sqlite3_exec(conn, createTableSQL, NULL, NULL, &zErrMsg) != SQLITE_OK){
		printf("%s\n", zErrMsg);
		sqlite3_close(conn);
		return -1;
	}
	
 
	char* sql = "INSERT INTO TESTTABLE(int_col, float_col, string_col) VALUES(?,?,?);";
	sqlite3_stmt* stmt = NULL;
 
	sqlite3_prepare_v2(conn, sql, strlen(sql), &stmt, &pzTail);
 
	/* loop cycle */
	for (int i = 0; i < 10; i++)
	{
		nCol = 1;
		sqlite3_bind_int(stmt, nCol++, i);
		sqlite3_bind_double(stmt, nCol++, (float)(i*1.0));
		sqlite3_bind_text(stmt, nCol++, name, strlen(name),NULL);
 
		sqlite3_step(stmt);
		sqlite3_reset(stmt);
	}
 
	/*destory stmt */
	sqlite3_finalize(stmt);
 
	return 0;
}