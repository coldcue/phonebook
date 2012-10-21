#include <stdio.h>
#include "cliapi.h"

int main()
{
	char name[32] = {0};
	cliapi_printHeader("TELEFONKONYV");

	scanf("%s",name);
	printf("Hello %s",name);
	
	return 0;
}