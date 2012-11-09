#include "database.h"

int db_isEmpty(FILE* db)
{
	unsigned pos;

	db = fopen(DBFILE,"r");
	fseek(db,0,SEEK_END);
	pos = ftell(db);

	return pos?0:1;
}

unsigned db_getBiggestId(FILE* db)
{
	unsigned id;

	db = fopen(DBFILE,"r");

	if(db_isEmpty(db)) return 0;
	fseek(db,-sizeof(Contact),SEEK_END);
	fread(&id,sizeof(int),1,db);

	return id;
}

int db_save(Contact * cntct)
{
	FILE* db;

	db = fopen(DBFILE,"a");
	cntct->id = db_getBiggestId(db)+1;

	fwrite(cntct,sizeof(Contact),1,db);
	fclose(db);

	return 1;
}

unsigned db_countEntities()
{
	FILE* db;
	unsigned r;

	db = fopen(DBFILE,"r");
	fseek(db,0,SEEK_END);
	r = ftell(db)/sizeof(Contact);
	fclose(db);
	return r;
}

unsigned db_getIdFromPos(FILE* db, const fpos_t *pos)
{
	unsigned id;
	fsetpos(db,pos);
	fread(&id,sizeof(unsigned),1,db);
	return id;
}

void db_getPosOfEntity(unsigned id, FILE *db, fpos_t *pos)
{
	fseek(db,0,SEEK_SET);
	*pos = ftell(db);

	while(id != db_getIdFromPos(db,pos))
	{
		*pos+=(fpos_t)sizeof(Contact);
	}
}

Contact db_read(FILE *db, const fpos_t *pos)
{
	Contact cntct;
	fsetpos(db,pos);
	fread(&cntct,sizeof(Contact),1,db);
	return cntct;
}

int db_get(unsigned id, Contact *cntct)
{
	FILE* db;
	fpos_t pos;

	db = fopen(DBFILE,"r");
	if(db_isEmpty(db)) return 0;

	db_getPosOfEntity(id,db,&pos);
	db_read(db,&pos);

	fclose(db);
	return 1;
}

