#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include<string>
#include<iostream>
#include <sys/stat.h>

static int callback(void *data, int argc, char **argv, char **azColName)
{
   int i;
   fprintf(stderr, "%s: \n", (const char*)data);
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

inline bool exists_test3 (const std::string& name) 
{
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

int main(int argc, char* argv[])
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	std::string sql;
	const char* data = "Callback function called";

	if(!exists_test3("test.db"))
	{
	   std::cout<<"not exist test.db" <<std::endl;
	   //return -1;
	}
	else
	{
		std::cout<<"exists test.db" <<std::endl;		
	}
	
	/* Open database */
	rc = sqlite3_open("test.db", &db);
	if( rc ){
	  fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(db));
	  exit(0);
	}else{
	 fprintf(stderr, "opened database successfully\n");
	}

	/* Create SQL statement */
    sql =  "UPDATE COMPANY set SALARY = 7000.00 where ID=3; " \
		"SELECT * from COMPANY;"   \
		"DELETE from COMPANY where ID=3; " \
		"SELECT * from COMPANY;";

    std::cout<<"["<<sql <<"]"<<std::endl;

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
	if( rc != SQLITE_OK ){
	  fprintf(stderr, "SQL error: %s\n", zErrMsg);
	  sqlite3_free(zErrMsg);
	}else{
	  fprintf(stdout, "Operation done successfully\n");
	}
	sqlite3_close(db);
	return 0;
}
