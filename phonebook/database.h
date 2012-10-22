#ifndef DATABASE_H
#define DATABASE_H


/* Entity structures */
typedef struct {
	int id,
	char *name, *number, *occptn;

} Contact;

int db_save(Contact * cntct);
int db_update(Contact * cntct);
int db_delete(Contact * cntct);

#endif