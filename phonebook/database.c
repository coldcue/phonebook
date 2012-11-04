#include "database.h"

int db_save(Contact * cntct)
{
	FILE* db;

	assert(cntct->id==0);
	cntct->id = db_getBiggestId()+1;

	db = fopen(DBFILE,"a");
	fwrite(cntct,sizeof(Contact),1,db);
	fclose(db);
	return 1;
}

int db_getBiggestId()
{
	FILE* db;
	int id;

	if(db_isEmpty()) return 0;

	db = fopen(DBFILE,"r");
	fseek(db,-sizeof(Contact),SEEK_END);
	fread(&id,sizeof(int),1,db);
	fclose(db);

	return id;
}

int db_isEmpty()
{
	FILE* db;
	int pos;

	db = fopen(DBFILE,"r");
	fseek(db,0,SEEK_END);
	pos = ftell(db);
	fclose(db);

	return pos?0:1;
}