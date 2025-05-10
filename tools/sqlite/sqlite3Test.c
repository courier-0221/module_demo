#include <stdio.h>
#include "sqlite3.h"

#define STOR_FAIL -1
#define STOR_OK 0

int stor_searchdb_set_version(sqlite3*db,int user_verion)
{
    int ret = STOR_FAIL;
    sqlite3_stmt* stmt = NULL;
    char buf[64] = {0};
    if(!db)
    {
        return STOR_FAIL;
    }
    snprintf(buf,sizeof(buf),"PRAGMA user_version=%d;",user_verion);
    if(sqlite3_prepare_v2(db,buf,-1,&stmt,NULL) != SQLITE_OK)
    {
        return STOR_FAIL;
    }
    if(sqlite3_step(stmt) != SQLITE_DONE)
    {
        ret = STOR_FAIL;
        goto EXIT;
    }
    ret = STOR_OK;
EXIT:
    sqlite3_finalize(stmt);
    return ret;
}

static int stor_searchdb_trans_create_column(char *column_buff, int column_buff_size)
{
	int ret = STOR_FAIL;
	char* p_buffer = NULL;
	char* p_end_buffer = NULL;

	if(!column_buff)
	{
		printf("input param is NULL !!!\n");
		ret = STOR_FAIL;
		goto EXIT;
	}

	p_buffer = column_buff;
	p_end_buffer = column_buff + column_buff_size;
	p_buffer += snprintf(p_buffer, p_end_buffer-p_buffer, "id INTEGER PRIMARY KEY AUTOINCREMENT");
	p_buffer += snprintf(p_buffer, p_end_buffer-p_buffer, ", track_id INTEGER");
	p_buffer += snprintf(p_buffer, p_end_buffer-p_buffer, ", left INTEGER");
	p_buffer += snprintf(p_buffer, p_end_buffer-p_buffer, ", top INTEGER");
	p_buffer += snprintf(p_buffer, p_end_buffer-p_buffer, ", right INTEGER");
	p_buffer += snprintf(p_buffer, p_end_buffer-p_buffer, ", bottom INTEGER");

	ret = STOR_OK;

EXIT:
	return ret;
}

static int stor_searchdb_create(char *filename, char* table_name, sqlite3 **search_db)
{
	int ret = STOR_FAIL;
	char *err_msg = NULL;
	char cmd_buff[1024] = {};
	char column_buff[1024] = {};

	ret = sqlite3_open(filename, search_db);
	if(ret != SQLITE_OK)
	{
	   printf("sqlite3_open %s error, ret = %d, err_msg=%s!!!\n",
	   										filename, ret, sqlite3_errmsg(*search_db));
	   ret = STOR_FAIL;
	   goto EXIT;
	}

	ret = stor_searchdb_trans_create_column(column_buff, sizeof(column_buff));
	if(ret != STOR_OK)
	{
		printf("stor_searchdb_trans_create_column error !!!\n");
		ret = STOR_FAIL;
		goto EXIT;
	}

	snprintf(cmd_buff, sizeof(cmd_buff), "CREATE TABLE %s(%s);", table_name, column_buff);
	
	printf("cmd_buff.%s\n", cmd_buff);

	ret = sqlite3_exec(*search_db, cmd_buff, NULL, NULL, &err_msg);
	if(ret != SQLITE_OK)
	{
	   printf("sqlite3_exec %s error, ret = %d, errmsg = %s!\n", cmd_buff, ret, err_msg);
	   sqlite3_free(err_msg);
	   ret = STOR_FAIL;
	   goto EXIT;
	}

	printf("run cmd:%s !!!\n", cmd_buff);


	stor_searchdb_set_version(*search_db, 0x010108);

	
	ret = STOR_OK;

EXIT:
	return ret;
}

static int stor_searchdb_begin(sqlite3 *search_db)
{
	int ret = STOR_FAIL;
	char *err_msg  = NULL;

	if(!search_db)
	{
		printf("input param is NULL !!!\n");
		ret = STOR_FAIL;
		goto EXIT;
	}
	
	ret = sqlite3_exec(search_db, "begin;", NULL, NULL, &err_msg);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_exec [begin;] error, ret = %d, errmsg = %s!\n", ret, err_msg);
		sqlite3_free(err_msg);
        ret = STOR_FAIL;
        goto EXIT;
    }
	
	ret = STOR_OK;
EXIT:
	return ret;
}

static int stor_searchdb_rollback(sqlite3 *search_db)
{
	int ret = STOR_FAIL;
	char *err_msg  = NULL;

	if(!search_db)
	{
		printf("input param is NULL !!!\n");
		ret = STOR_FAIL;
		goto EXIT;
	}

	ret = sqlite3_exec(search_db, "rollback;", NULL, NULL, &err_msg);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_exec [rollback;] error, ret = %d, errmsg = %s!\n", ret, err_msg);
		sqlite3_free(err_msg);
        ret = STOR_FAIL;
        goto EXIT;
    }
	
	printf("stor_searchdb_rollback\n");
	
	ret = STOR_OK;
EXIT:
	return ret;
}

static int stor_searchdb_commit(sqlite3 *search_db)
{
	int ret = STOR_FAIL;
	char *err_msg  = NULL;

	if(!search_db)
	{
		printf("input param is NULL !!!\n");
		ret = STOR_FAIL;
		goto EXIT;
	}

	ret = sqlite3_exec(search_db, "commit;", NULL, NULL, &err_msg);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_exec [commit;] error, ret = %d, errmsg = %s!\n", ret, err_msg);
		sqlite3_free(err_msg);
        ret = STOR_FAIL;
        goto EXIT;
    }
	
	ret = STOR_OK;
EXIT:
	return ret;
}

int stor_searchdb_insert(sqlite3 *search_db)
{
	char sqlBuf[1024] = {0};
	char *err_msg  = NULL;
	int i = 0;
	int ret = STOR_OK;
	for (i = 0; i < 100; i++)
	{
		stor_searchdb_begin(search_db);
		snprintf(sqlBuf, 1024, "insert into table_01 (id,track_id,left,top,right,bottom) values (%d,%d,%d,%d,%d,%d);", i, i+1, i+2, i+3, i+4, i+5);
		ret = sqlite3_exec(search_db, sqlBuf, NULL, NULL, &err_msg);
		if(ret != SQLITE_OK)
		{
			printf("sqlite3_exec error, ret = %d, errmsg = %s!\n", ret, err_msg);
			sqlite3_free(err_msg);
			ret = STOR_FAIL;
			
			goto EXIT;
		}
		printf("stor_searchdb_insert %d\n", i);
		if (STOR_FAIL == stor_searchdb_commit(search_db))
		{
			stor_searchdb_rollback(search_db);
		}
	}
EXIT:
	return ret;
}

int stor_searchdb_get(sqlite3 *search_db)
{
	sqlite3_stmt		*stmt							= NULL;
	char sqlBuf[1024] = {0};
	snprintf(sqlBuf, 1024, "select count(*) from table_01;");


	if (SQLITE_OK != sqlite3_prepare_v2(search_db, sqlBuf, -1, &stmt, NULL))
	{
		printf("sqlite3_prepare_v2 fail ,err is %s !!!\n", sqlite3_errmsg(search_db));
		goto EXIT;
	}
	
	int ret_code = 0;
	ret_code = sqlite3_step(stmt);
	if (ret_code == SQLITE_DONE)
	{
	}
	else if (ret_code != SQLITE_ROW)
	{
		goto EXIT;
	}

	int value = sqlite3_column_int(stmt, 0);
	
	printf("stor_searchdb_get value.%d\n", value);


EXIT:
	sqlite3_finalize(stmt); 
	return STOR_OK;
}

int main()
{
	sqlite3 *search_db;
	
	stor_searchdb_create("./sqlite3Test.db", "table_01", &search_db);
	
	stor_searchdb_insert(search_db);
	
	
	for (int i = 0; i < 10; i++)
	{
		stor_searchdb_get(search_db);
	}
	
	return 0;
}
