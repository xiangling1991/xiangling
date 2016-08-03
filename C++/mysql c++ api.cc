#连接数MySQL
1. MYSQL* mysql_real_connect(MYSQL* mysql, const char* host, const char* user,
                         const char* passwd, const char* db, unsigned int port,
                         const char* unix_socket, unsigned int client_flag);

#连接数据库
2. int mysql_select_db(MYSQL* mysql, const char* db);

#进行查询接口
#query：查询语句
#length：查询语句长度
3. int mysql_real_query(MYSQL* mysql, const char* query, unsigned int length);

#获取查询的结果
4. MYSQL_RES* mysql_store_result(MYSQL* mysql);

#获取所有的行
5. MYSQL_ROW mysql_fetch_row(MYSQL_RES* res);  

#获取某一行中的数据
6. unsigned int mysql_num_fields(MYSQL_RES* res);        

7. void mysql_free_result(MYSQL_RES*);

8. void mysql_close(MYSQL*);
