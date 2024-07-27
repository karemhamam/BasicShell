/* *******************************************************
   * @File                 : My_shell.c
   * @Author               : mohamed bahget hamam
   * @Brief                : shell v1.1
   *******************************************************
*/


/* **************** Include section start *************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>

/* **************** Include section End *************** */

/* **************** macros section start *************** */

#define Max_Data_Size (1024)
#define Max_Arg       (10)

/* **************** macros section End *************** */



int main()
{
    char input[Max_Data_Size];
    char *args[Max_Arg];
    while (1)
    {
        prompt();
        if (fgets(input , Max_Data_Size , stdin) == NULL)
        {
            perror("Feh ERROR Hena");
            continue;
        }   
        
        input[strcspn(input,"\n")] = 0 ;

        if (strcmp (input , "") == 0 ) continue;
        Data_IN(input, args);
        if (strcmp (args[0],"pwd") == 0)
        {
            pwd();
        }else if (strcmp (args[0] , "echo") == 0)
        {
            echo(args);
        }else if (strcmp (args[0], "cp") == 0 )
        {
            cp(args);
        }else if (strcmp (args[0], "mv") == 0 )
        {
            mv(args);
        }else if (strcmp (args[0] , "exit") == 0)
        {
            printf("Come Back Soon ^_- \n");
            break;
        }else if ( strcmp (args[0], "help") == 0 )
        {
            help();
        }else
        {
            Wrong_Command();
        }
        
    }


  return 0 ;
}


/* **************** Definition section start *************** */



/* ************** Definition section End *************** */



/* *******************************************************
   @User                 @Date             @version
   *******************************************************
   mohamed hamam         25july2024         1.0 
   mohamed hamam         26july2024         1.1 
*/

