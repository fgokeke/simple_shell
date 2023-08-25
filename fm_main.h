#ifndef FM_MAIN_H
#define FM_MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

void err_msg(char *program, int count_cmd, char *cmd);

extern char **environ;
int exit_num;
int exec(char **avs, char **av);
int full_exec(char **avs, char **av, char *complete_cmd);
char *fm_complete_path(char *paths, char *cmd);
char *pathenv(void);
void handle_comments(char *lineptr);
int fm_builtins_handler(char **avs, char *lineptr);
char **tokenize_str(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
char *_strchr(const char *str, char c);
char *_strdup(char *s);
int _strncmp(char *s1, char *s2, size_t n);
int _strcmp(char *s1, char *s2);
size_t _strcspn(const char *str, const char *set);
char *_strtok(char *str, const char *delim);
char *_strcat(char *dest, char *src);

#endif
