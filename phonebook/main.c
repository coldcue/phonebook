#include <stdio.h>
#include <string.h>

#include "cliapi.h"


int main()
{
	char* command;
	int first = 1;

	cliapi_printHeader();
	do
	{
		if(!first) printf("Hibas parancs! Segitseghez ird be 'help'!");
		first=0;

		command = cliapi_waitForCommand();
	}
	while(strcmp(command,"help")!=0);


	return 0;
}