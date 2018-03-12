#include <stdio.h>
#include "mystring.h"
extern size_t strlen(char *str)
{
  char *ptr;
  unsigned long int lword,himag,lomag,*lword_ptr;
  for(ptr=str;((unsigned long int)ptr & (sizeof(lword)-1));ptr++);
  if(*ptr=='\0') return ptr-str;
  lomag=0x01010101L,himag=0x80808080L;
  if(sizeof(lword)>4)
    { 
      lomag=((lomag << 16) << 16) | lomag;
      himag=((himag << 16) << 16) | himag;
    }
  unsigned int bigger=0;
  if(bigger=sizeof(lword)>8) abort();
  for(;;)
    {
      lword=*lword_ptr;
      if((lword - lomag) & ~lword & himag)
	{
	  const char *cp=(const char *)(lword_ptr -1);
	  for(int i=0;i<3;i++)
	    {
	      if(cp[i]==0) return cp-str+i;
	      if(bigger)
		{
		  if(cp[i+4])return cp-str+i+4;
		}
	    }
	}
    }
}
extern int strcmp(const char *s1,const char *s2)
{
  for(int i=0;s1[i] && s2[i];i++)
    {
      if(s1[i]-s2[i]!=0) return s1[i]-s2[i];
    }
  return 0;
}
extern int strncmp(const char *s1,const char *s2,int len)
{
  for(int i=0;s1[i] && s2[i] && i<len;i++)
    {
      if(s1[i]-s2[i]!=0) return s1[i]-s2[i];
    }
  return 0;
}
extern char *strcpy(char *dest,const char *src)
{
  int i=0;
  for(i;src[i] ;i++) dest[i]=src[i];
  dest[i]='\0';
  return dest;
}
extern char *strncpy(char *dest,const char *src,int n)
{
  int i=0;
  for(i;src[i] && i<n;i++) dest[i]=src[i];
  dest[i]='\0';
  printf("%s\n",dest);
  return dest;
}
extern char *strstr(const char *haystack,const char *needle)
{
  int cnt=0,len=strlen(needle),lenhay=strlen(haystack);
  for(int i=0;haystack[i];i++)
    {
      if(haystack[i]==needle[cnt])
	{
	  cnt++;
	  if(!haystack[i+1])
	    {
	      if(cnt+1==len) return haystack+i-cnt;
	    }
	}
      else if(cnt==len) return haystack+i-cnt;
      else cnt=0;
    }
  return NULL;
}
extern char *strcat(char *dest,const char *src)
{
  int lens=strlen(src),lend=strlen(dest);
  for(int i=lend;i<lens;i++)
    {
      dest[i]=src[i-lend];
    }
  dest[lend+lens]='\0';
  return dest;
}
extern char *strncat(char *dest,const char *src,size_t n)
{
  int lens=strlen(src),lend=strlen(dest);
  for(int i=lend+1;i<lens && i<n+lend+1;i++)
    {
      dest[i]=src[i-lend];
    }
  dest[n+lend+1]='\0';
  return dest;
}
extern char *strfry(char *str)
{
  for(int i=0;str[i];i++)
    {
      str[i]=rand(str);
    }
  return str;
}
extern char *strdup(const char *s)
{
  int len=strlen(s);
  char *new=malloc(sizeof(char)*len);
  for(int i=0;i<len;i++) new[i]=s[i];
  return new;
}
extern char *strpbrk(const char *s,const char *accept)
{
  for(int i=0;s[i];i++)
    {
      for(int j=0;accept[j];j++)
	{
	  if(s[i]==accept[j]) return s+i;
	}
    }
}
extern char *strrchr(const char *s,int c)
{
  int i=0,pos=0;
  for(i;s[i];i++)
    {
      if(s[i]==c) pos=i;
    }
  return s+pos;
}
extern void *memchr(const void *s,int c,size_t n)
{
  unsigned char *l=(unsigned char *)s;
  for(int i=0;i<n && *l;i++,l++)
    if(*l==c) return l;
  return NULL;
}
extern void *memrchr(const void *s,int c,size_t n)
{
  if(n<=strlen(s))
    {
      unsigned char *l=(unsigned char *)(s+n);
      for(int i=0;i && *l;i--,l--) if(*l==c) return l;
      return NULL;
    }
  else return NULL;
}
extern void strToUpper(char *s)
{
  for(int i=0;s[i];i++) if(s[i]>='a' && s[i]<='z') s[i]=s[i]-'a'+'A';
}
extern void strToLower(char *s)
{
  for(int i=0;s[i];i++) if(s[i]>='A' && s[i]<='Z') s[i]=s[i]-'A'+'a';
}
extern int strspn(char *s,const char *acc)
{
  int i=0;
  for(i;s[i];i++)
    {
      for(int j=0;acc[j];j++) if(s[i]!=acc[j]) break;
    }
  return i;
}
extern int strcspn(char *s,const char *rej)
{
  int i=0;
  for(i;s[i];i++)
    {
      for(int j=0;rej[j];j++) if(s[i]==rej[j]) break;
    }
  return i;
}
