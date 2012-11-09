#include <stdio.h>
#include <string.h>

#include "cliapi.h"
#include "database.h"
#include "main.h"


int main()
{
	int err = 0, exit = 0, i;

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
		else if(strcmp(command,"test")==0){
			Contact cntct,cntct2;
			for(i=0; i<874; i++){
			strcpy(cntct.email,"coldcue@gmail.com");
			strcpy(cntct.name,"Andrew Szell");
			strcpy(cntct.number,"06202094988");
			strcpy(cntct.occptn,"Programmer");
			db_save(&cntct);
			}

			printf("%d",db_get(1345000,&cntct2));
			putchar('a');
		}
		else err=1;

	}
	while(!exit);


	return 0;
}