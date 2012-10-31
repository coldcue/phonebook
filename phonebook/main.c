#include <stdio.h>
#include <string.h>

#include "cliapi.h"


int main()
{
	int err = 0, exit = 0;

	cliapi_printHeader();

	do
	{
		char* command;

		if(err){ 
			printf("Hibas parancs! Segitseghez ird be 'help'!");
			err=0;
		}
		command = cliapi_waitForCommand();

		if(strcmp(command,"help")==0)printf("Segitseg...\n");
		else if(strcmp(command,"exit")==0)exit=1;
		else err=1;

	}
	while(!exit);


	return 0;
}