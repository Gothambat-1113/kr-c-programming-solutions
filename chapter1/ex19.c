#include <stdio.h>
#define MAXLENGTH 1000 


int get_line(char line[] , int maxlength); 
void reverse(char line[]); 


int main(){

char  line[MAXLENGTH]; 

while(get_line(line , MAXLENGTH) > 0){
   reverse(line);
   printf("%s" , line); 
}




return 0; 
}


int get_line(char s[] , int lim ){

int c , i , j; 
j = 0; 

for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
if (i < lim - 2)
{
s[j] = c;
++j; 
}

if(c == '\n')
{
s[j] = c;
++j; 
++i; 
}

s[j] = '\0'; 

 return i; 
}

void  reverse (char s[]){

int i , j ; 
char temp; 
i = 0;  


while  (s[i] != '\0')
++i;

--i;

if (s[i] == '\n')
--i; 

j = 0; 
while(j < i){
temp = s[i]; 
s[i] = s[j]; 
s[j] = temp; 
--i; 
++j; 

}



}

