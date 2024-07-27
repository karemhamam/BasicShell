#ifndef COMMANDS_H
#define  COMMANDS_H

void prompt();
void Data_IN(char *input , char **args);
void pwd();
void echo (char **args);
void cp (char **args);
void mv (char **args);
void help ();
void Wrong_Command ();

#endif