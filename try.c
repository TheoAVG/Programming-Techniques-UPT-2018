#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
  //STRSTR
  char *s1="ana are mere si maria are mure";
  char *find="mure";
  printf("%s\n%s\n",strstr(s1,find),strstr(s1,find));
  //Both work STRCAT
  char s2[100]="ana are mere";
  char *ap=" si maria are mure";
  printf("%s\n%s\n",strncat(s2,ap,5),strncat(s2,ap,5));
  //WORKS STRFRY
  char s3[100]="ana are mere";
  printf("%s\n%s\n",strfry(s3),strfry(s3));
  // STRDUP WORKS#include <mystring.c>
  char *s4="ana are mere";
  printf("%s\n%s\n%s\n",strdup(s4),s4,strdup(s4));
  // STRPBRK WORKS
  char *s5="ana are merke";
  char *acc="kldsfm";
  printf("%s\n%s\n",strpbrk(s5,acc),strpbrk(s5,acc));
  // WORKS STRRCHR
  char *s6="ana are merke si maria are mursl";
  printf("%s\n%s\n",strrchr(s6,'l'),strrchr(s6,'l'));
  // WORKS MEMCHR
  char *s7="ana are merke";
  char *l=memchr(s7,'u',strlen(s7));
  char *l2=memchr(s7,'u',strlen(s7));
  printf("%s\n%s\n",l,l2);
  // Upper and Lower case string transform
  char s8[]="ana are mere";
  printf("%s\n",s8);
  //strToUpper(s8);
  // strToLower(s8);
  printf("%s\n",s8);
}
