#include "cliapi.h"

void cliapi_printHeader()
{
	printf("########## TELEFONKONYV ##########\nSegitseghez ird be 'help'!\n");
}

char* cliapi_waitForCommand()
{
	char line[1024], *pos;

	pos=line;
	printf("\n> ");
	while((*pos++=(char)getchar())!='\n');
	*--pos=0;
	return line;
}

void cliapi_printContact(Contact *cntct)
{
	printf("#### ID: %d ####\n",cntct->id);
	printf("# Nev:      %s \n",cntct->name);
	printf("# Telefon:  %s \n",cntct->number);
	printf("# E-mail:   %s \n",cntct->email);
	printf("# Foglalk.: %s \n",cntct->occptn);
	printf("################\n");
}