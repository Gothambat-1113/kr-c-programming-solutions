#include <stdio.h>


int main() {

int lower , upper , step; 
int celcius , frah; 

lower = 0; 
upper = 300; 
step  = 20; 


frah = lower; 

while(frah <= 300){
celcius = 5*(frah - 32) / 9; 
printf("%d\t  %d\n" , frah , celcius); 
frah = frah + 20; 




}



return 0; 


}


float celcius( float frah){

return (5.0/9.0) * (frah - 32.0); 

 



}

