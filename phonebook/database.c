#include "database.h"

int db_isEmpty(FILE* db)
{
	fpos_t pos;

	fseek(db,0,SEEK_END);
	pos = ftell(db);

	return pos?0:1;
}

unsigned db_getBiggestId(FILE* db)
{
	unsigned id;

	if(db_isEmpty(db)) return 0;
	fseek(db,-sizeof(Contact),SEEK_END);
	fread(&id,sizeof(int),1,db);

	return id;
}

int db_save(Contact * cntct)
{
	FILE* db;
	
	db = fopen(DBFILE,"rb");
	cntct->id = db_getBiggestId(db)+1;
	fclose(db);

	db = fopen(DBFILE,"ab");
	
	fwrite(cntct,sizeof(Contact),1,db);
	fclose(db);

	return 1;
}

unsigned db_countEntities(FILE *db)
{
	unsigned r;

	fseek(db,0,SEEK_END);
	r = ftell(db)/sizeof(Contact);
	return r;
}

unsigned db_getIdFromPos(FILE* db, const fpos_t *pos)
{
	unsigned id;
	fsetpos(db,pos);
	fread(&id,sizeof(unsigned),1,db);
	return id;
}

int db_getPosOfEntity(unsigned id, FILE *db, fpos_t *cur)
{
	unsigned min_id, max_id, cur_id;
	fpos_t min, max;

	fseek(db,0,SEEK_SET);

	/*Get the min, max and cur*/
	min = ftell(db);
	min_id = db_getIdFromPos(db,&min);

	max = min+(db_countEntities(db)-1)*sizeof(Contact);
	max_id = db_getIdFromPos(db,&max);

	*cur = (min/sizeof(Contact)+max/sizeof(Contact))/2*sizeof(Contact);
	cur_id = db_getIdFromPos(db,cur);

	while(cur_id != id && min_id <= max_id)
	{
		if(cur_id<id){
			min = *cur+sizeof(Contact);
			min_id = db_getIdFromPos(db,&min);
		}
		else {
			max = *cur-sizeof(Contact);
			max_id = db_getIdFromPos(db,&max);
		}
		*cur = (min/sizeof(Contact)+max/sizeof(Contact))/2*sizeof(Contact);
		cur_id = db_getIdFromPos(db,cur);
	}

	if(cur_id==id) return 1;
	return 0;
}

int db_read(FILE *db, Contact * cntct, const fpos_t *pos)
{
	Contact buf;
	fsetpos(db,pos);
	fread(&buf,sizeof(Contact),1,db);
	*cntct = buf;
	return 1;
}

int db_get(unsigned id, Contact *cntct)
{
	FILE* db;
	fpos_t pos;
	int r=0;

	db = fopen(DBFILE,"rb");
	if(db_isEmpty(db)) return 0;

	if(db_getPosOfEntity(id,db,&pos))
	{
		db_read(db,cntct,&pos);
		r=1;
	}

	fclose(db);
	return r;
}

