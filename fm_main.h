#ifndef FM_MAIN_H
#define FM_MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void exe_cmmd(char **av);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int fm_tokenize(char *lineptr, const char *delimtr);
char **av_cmmd(char *lineptr_cpy, const char *delimtr, char **av,
int count_token);
int mem_alloc_error(char *s);
char *locate_cmmd(char *cmmd);
char *fm_getenv(char *var_name);
extern char **environ;
char *_strncpy(char *dest, char *src, int n);
char *_strchr(const char *str, char c);
char *_strdup(char *s);
int _strncmp(char *s1, char *s2, size_t n);
void fm_builtin(char *input);
int _strcmp(char *s1, char *s2);
size_t _strcspn(const char *str, const char *set);
char *_strtok(char *str, const char *delim);

#endif
