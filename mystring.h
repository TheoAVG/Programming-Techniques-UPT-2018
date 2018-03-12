#ifndef _MYSTRING_H
#define _MYSTRING_H
#define _GNU_SOURCE
#include <stdlib.h>
int strcmp(const char *s1,const char *s2);
char *strcpy(char *dest,const char *src);
int strncmp(const char *s1,const char *s2,int len);
char *strncpy(char *dest,const char *src,int n);
size_t strlen(char *s);
char *strstr(const char *haystack,const char *needle);
char *strcat(char *dest,const char *src);
char *strncat(char *dest,const char* src,size_t n);
char *strfry(char *str);
char *strdup(const char *s);
char *strpbrk(const char *s,const char *accept);
char *strrchr(const char *s,int c);
void *memchr(const void *s,int c,size_t n);
void *memrchr(const void *s,int c,size_t n);
void *rawmemchr(const void *s,int c);
void strToUpper(char *s);
void strToLower(char *s);
int strnspn(char *s,const char *acc);
int strcspn(char *s,const char *rej);
#endif
