#include <stdio.h>
#include <string.h>

#include "cliapi.h"
#include "database.h"
#include "main.h"

int main()
{
	int err = 0, exit = 0, i;

	db_construct();

	cliapi_printHeader();

	do
	{
		char txt[1024], *command, *str;

		if(err){ 
			printf("Hibas parancs! Segitseghez ird be 'help'!");
			err=0;
		}
		cliapi_waitForCommand(txt);
		command = strtok(txt," ");

		/* Help command */
		if(strcmp(command,"help")==0)printf("Segitseg...\n");

		/* Open command */
		else if(strcmp(command,"open")==0) {
			char *tmp;
			unsigned id;
			Contact cntct;
			tmp = strtok(NULL," ");
			id = atoi(tmp);
			if(db_get(id,&cntct))
				cliapi_printContact(&cntct);
			else printf("# Nincs ilyen rekord!\n");
		}

		/* Search command */
		else if(strcmp(command,"search")==0) {
			ContactList *cntcts = NULL;
			char *tmp = txt+strlen(command)+1;

			cntcts = db_search(tmp);
			if(cntcts==NULL) printf("Nincs találat!");
			else {
				ContactList *p;
				for(p=cntcts;p!=NULL;p=p->next) cliapi_printContact(p->cntct);
			}
			list_free(&cntcts);
		}

		/* Delete command */
		else if(strcmp(command,"del")==0) {
			char *tmp;
			unsigned id;
			Contact cntct;
			tmp = strtok(NULL," ");
			id = atoi(tmp);
			if(db_get(id,&cntct)) {
				cliapi_printContact(&cntct);
				db_delete(id);
				printf("# Rekord torolve!\n");
			}
			else printf("# Nincs ilyen rekord!\n");
		}

		else if(strcmp(command,"exit")==0)exit=1;
		else if(strcmp(command,"test")==0){
			Contact cntct;

			for(i=0; i<2000; i++){
			strcpy(cntct.email,"coldcue@gmail.com");
			strcpy(cntct.name,"Andrew Szell");
			strcpy(cntct.number,"06202094988");
			strcpy(cntct.occptn,"Programmer");
			db_save(&cntct);
			}

			printf("%d",db_get(311,&cntct));
			strcpy(cntct.name,"Kukor Ica");
			printf("%d",db_update(&cntct));

			printf("%d",db_get(878,&cntct));
			strcpy(cntct.name,"Buz Ubul");
			printf("%d",db_update(&cntct));

			printf("%d",db_get(18,&cntct));
			strcpy(cntct.name,"Matr Ica");
			printf("%d",db_update(&cntct));

			printf("%d",db_get(97,&cntct));
			strcpy(cntct.name,"Vegh Bela");
			printf("%d",db_update(&cntct));

			printf("%d",db_get(55,&cntct));
			strcpy(cntct.name,"Kat Ica");
			printf("%d",db_update(&cntct));
		}
		else err=1;
	}
	while(!exit);


	return 0;
}