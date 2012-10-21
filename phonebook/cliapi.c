#include "cliapi.h"

void cliapi_printHeader()
{
	printf("########## TELEFONKONYV ##########\nSegitseghez irja be 'help'!\n");
}

char* cliapi_waitForCommand()
{
	char line[1024];
	printf("\n> ");
	scanf("%s",line);
	return line;
}