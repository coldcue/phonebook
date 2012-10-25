#include "database.h"

int db_save(Contact * cntct)
{
	assert(cntct->id==0);
}

char* db_convertToCsv(Contact *cntct) 
{
	char * buf = (char*) calloc(512,sizeof(char));
	char * result;
	sprintf(buf,"%d,\"%s\",\"%s\",\"%s\"\n",cntct->id,cntct->name,cntct->number,cntct->occptn);
	result = (char*) calloc(strlen(buf)+1,sizeof(char));
	strcpy(result,buf);
	free(buf);
	return result;
}