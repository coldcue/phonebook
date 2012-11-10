#include "cliapi.h"

void cliapi_printHeader()
{
	printf("########## TELEFONKONYV ##########\nSegitseghez ird be 'help'!\n");
}

void cliapi_waitForCommand(char buf[])
{
	char *pos;
	pos=buf;
	printf("\n> ");
	while((*pos++=(char)getchar())!='\n');
	*--pos=0;
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