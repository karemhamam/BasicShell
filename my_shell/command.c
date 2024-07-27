/* *******************************************************
   * @File                 : command.c
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
#include "command.h"

/* **************** Include section End *************** */

/* **************** Macros section start *************** */

#define Max_Data_Size (1024)
#define Max_Arg       (10)


/* **************** Macros section End ****************** */



/* **************** Definition section start *************** */

void Data_IN(char *input , char **args)
{
    int i = 0 ; 
    for ( i = 0 ; i < Max_Arg ; i++)
    {
        args[i] = strsep(&input ," ");
        if (args[i] == NULL ) break;
    }
}

void prompt()
{
    printf("jamayka :$ ");
}

void pwd ()
{
    char cwd [1024];
    if (getcwd(cwd , sizeof(cwd)) != NULL)
    {
        printf("%s\n", cwd);
    }else
    {
        perror("Feh ERROR Hena");
    }
}

void echo (char **args)
{
    int i = 0 ; 
    for ( i = 1 ; args[i] != NULL ; i++)
    {
        printf("%s ", args[i]);
    }
    printf("\n");
}

void cp (char **args)
{
    char *source = args[1];
    char *target = args[2];

    if (!source || !target)
    {
        fprintf(stderr , "Usage: cp [-a] source target\n");
        return;
    }

    int source_fd = open (source , O_RDONLY);
    if (source_fd < 0 )
    {
        perror ("Feh ERROR Hena");
        return;
    }

    int target_fd ;
    target_fd = open(target , O_WRONLY | O_CREAT | O_EXCL , 0644);
    
    if (target_fd < 0 )
    {
        perror("Feh ERROR Hena");
        close(source_fd);
        return;
    }

    char buffer[1024];
    ssize_t bytes; 
    while ((bytes = read(source_fd , buffer ,sizeof(buffer))) > 0 )
    {
        if (write (target_fd ,buffer , bytes) != bytes)
        {
            perror("Feh ERROR Hena");
            close (source_fd);
            close (target_fd);
            return;
        }    
        if (bytes < 0 )
        {
            perror("Feh ERROR Hena");
        }
        close (source_fd);
        close (target_fd);
    }

}

void mv (char **args)
{
    char *source = args[1];
    char *target = args[2];

    if (!source || !target)
    {
        fprintf(stderr , "Usage: mv source target \n");
        return;
    }
    if (rename(source,target) < 0 )
    {
        perror("Feh ERROR Hena");
    }
}

void help()
{
    printf("Supported Commands are :\n");
    printf("1) pwd : print working directory \n");
    printf("2) echo : print a user input string on a stdout\n");
    printf("3) cp : copy a file to another place \n");
    printf("4) mv : move a file to another place \n");
    printf("5) exit : terminate the shell\n");
    printf("6) help : pirnt all the supported commands \n");

}


void Wrong_Command()
{
    printf("Command not found. Type 'help' for a list of commands.\n");
}

/* ************** Definition section End ************************ */



/* *******************************************************
   @User                 @Date             @version
   *******************************************************
   mohamed hamam         25july2024         1.0 
   mohamed hamam         26july2024         1.1 
*/

