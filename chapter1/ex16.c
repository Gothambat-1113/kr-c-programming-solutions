#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[] , int maxline); 
void copy(char to[] , char from[]);

int main(){

int len; 
int maxlen; 
char  line[MAXLINE];
char  longest[MAXLINE];




maxlen = 0; 
while ( (len = get_line(line , MAXLINE)) > 0){
printf("%s\t   %d\n"  , line , len);


   if (len > maxlen ){
    maxlen = len; 
    copy(longest , line);
   }
}
if(maxlen > 0)
   printf("%s" , longest);







return 0; 
}


int get_line(char s[] , int lim){
int i , c ,  j; 

j = 0;

for(i = 0; ( c = getchar()) != EOF  && c != '\n'; i++ )
if (i < lim - 2 )
{
s[j] = c; 
j++; 
}

if( c == '\n')
{
s[j] = c; 
j++; 
i++; 
}
s[j] = '\0';

return i; 


}

void copy (char to [] , char from[])

{
  
int i; 
 i = 0; 

while ((to[i] = from[i]) != '\0')
++i; 

}
