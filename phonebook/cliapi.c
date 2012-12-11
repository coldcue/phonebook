#include "cliapi.h"

/**
Prints out the header
*/
void cliapi_printHeader()
{
	printf("########## TELEFONKONYV ##########\nSegitseghez ird be 'help'!\n");
}

/**
Waits for a command
*/
void cliapi_waitForCommand(char buf[])
{
	char *pos;
	pos=buf;
	printf("\n> ");
	while((*pos++=(char)getchar())!='\n');
	*--pos=0;
}

/**
Prints out a contact
*/
void cliapi_printContact(Contact *cntct)
{
	printf("#### ID: %d ####\n",cntct->id);
	printf("# Nev:      %s \n",cntct->name);
	printf("# Telefon:  %s \n",cntct->number);
	printf("# E-mail:   %s \n",cntct->email);
	printf("# Foglalk.: %s \n",cntct->occptn);
	printf("################\n");
}

/**
Asks for details
*/
void cliapi_askDetail(const char name[], char dest[], const size_t maxsize)
{
	int temp, count=0;
	printf("# %s: ",name);
	while((temp=getchar())!='\n' && count<maxsize) dest[count++]=temp;
	dest[count] = '\0';
}

/**
Asks for new details
*/
Contact * cliapi_askNewDetails()
{
	Contact * cntct;

	cntct = (Contact*) calloc(1,sizeof(Contact));

	cliapi_askDetail("Nev",cntct->name,64);
	cliapi_askDetail("Telefon",cntct->number,32);
	cliapi_askDetail("E-mail",cntct->email,256);
	cliapi_askDetail("Foglalk.",cntct->occptn,32);

	return cntct;
}

void cliapi_askModDetail(const char name[], char dest[], const size_t maxsize)
{
	int temp, count=0;
	char buf[256];
	printf("# %s: ",name);
	while((temp=getchar())!='\n' && count<maxsize) buf[count++]=temp;
	buf[count] = '\0';
	if(strlen(buf)) strcpy(dest,buf);
}


void cliapi_askModDetails(Contact * cntct)
{
	printf("# Nev:      %s \n",cntct->name);
	cliapi_askModDetail("Uj nev",cntct->name,64);
	printf("# Telefon:  %s \n",cntct->number);
	cliapi_askModDetail("Uj telefon",cntct->number,32);
	printf("# E-mail:   %s \n",cntct->email);
	cliapi_askModDetail("Uj e-mail",cntct->email,256);
	printf("# Foglalk.: %s \n",cntct->occptn);
	cliapi_askModDetail("Uj foglalk.",cntct->occptn,32);
}

