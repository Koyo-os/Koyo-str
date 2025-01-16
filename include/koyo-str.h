#ifdef FACEKID_H
#define FACEKID_H

char * to_upper(char * text);
char * to_lower(char * text);
int index_s(char s, char * text);
char * trim_left(int index, char * text);
char * trim_right(int index, char * text);
float alike(char * text1, char * text2);
void free_crush_result(char **result);
void change(char old, char new_s, char * text);
void delete_simbol(char simbol, char * text);
char ** crush(char s, char * text);

#endif