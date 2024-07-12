#include "textUtils.h"

string onCenter(string input, int width = 113) { 
   return string((width - input.length()) / 2, ' ') + input;
}

string changeColor(string txt, char color){
   string code = "37"; //by default white
   switch(color){
      case 'R':   code = "31";   break;
      case 'G':   code = "32";   break;
      case 'Y':   code = "33";   break;
      case 'B':   code = "34";   break;
      case 'M':   code = "35";   break;
      case 'C':   code = "36";   break;
      case 'W':   code = "37";   break;
   }

   return ("\x1B[" + code + "m" + txt + "\033[0m");

}


// printf("\x1B[31mTexting\033[0m\t\t");
//     printf("\x1B[32mTexting\033[0m\t\t");
//     printf("\x1B[33mTexting\033[0m\t\t");
//     printf("\x1B[34mTexting\033[0m\t\t");
//     printf("\x1B[35mTexting\033[0m\t\t");
    
//     printf("\x1B[36mTexting\033[0m\t\t");
//     printf("\x1B[36mTexting\033[0m\t\t");
//     printf("\x1B[36mTexting\033[0m\t\t");
//     printf("\x1B[37mTexting\033[0m\t\t");
//     printf("\x1B[93mTexting\033[0m\t\t");
    
//     printf("\033[3;42;30mTexting\033[0m\t\t");
//     printf("\033[3;43;30mTexting\033[0m\t\t");
//     printf("\033[3;44;30mTexting\033[0m\t\t");
//     printf("\033[3;104;30mTexting\033[0m\t\t");
//     printf("\033[3;100;30mTexting\033[0m\t\t");

//     printf("\033[3;47;35mTexting\033[0m\t\t");
//     printf("\033[2;47;35mTexting\033[0m\t\t");
//     printf("\033[1;47;35mTexting\033[0m\t\t");