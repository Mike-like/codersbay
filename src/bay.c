//
// Created by Michael Bockel on 24.11.22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdbool.h"
#include "verbose.h"

void codersbay(char* command_pointer, char *input);
char* read_file(char* file_name);
char* get_next_name(char* ptr, char* command);
char* move_ptr_previous(char* ptr);
void usage_check(int argc);

#define MAX_COMMAND_SIZE 10
#define DATASIZE 1001

char output_mode = 'c';
bool alex_mode = false;

int main(int argc, char *argv[]) {
    usage_check(argc);
    char* file;
    if (argv[1][0] == '-'){
        for (int i = 1; i < argc; i++){
            if (strcmp(argv[i], "--alex") == 0){
                alex_mode = true;
                printf("Verbose mode activated!\nBefore we can understand the codersbay programming language,\n"
                       "we have to know ... what is physics.\n On a warm summer evening in ancient greece....");
            }
            else if (strstr(argv[i], "--doris")){
                output_mode = *(argv[i]+8);
            }
        }
    }
    file = argv[argc-1];
    char* code = read_file(file);
    char* input = "";
    codersbay(code, input);
    return 0;
}

void usage_check(int argc){
    if(argc < 2){
        printf("Usage: bay <source.cbl>");
        exit(1);
    }
}

void codersbay(char* command_pointer, char* input) {
    int bracket_flag;
    int shift = 0;
    char data[DATASIZE] = {0};
    char* dp;
    dp = &data[DATASIZE / 2];
    char* command;

    while (*command_pointer+shift+1 != '\n' && *command_pointer != 0)
    {
        command = malloc(MAX_COMMAND_SIZE);
        get_next_name(command_pointer, command);
        if (strcmp(command, "mike") == 0) {
            if(alex_mode){
                char old_dp = *dp;
                dp++;
                get_info(command, old_dp, *dp);
            }
            else{
                dp++;
            }
        }
        else if(strcmp(command, "patricia") == 0){
            if(alex_mode){
                char old_dp = *dp;
                dp--;
                get_info(command, old_dp, *dp);
            }
            else{
                dp--;
            }
        }
        else if(strcmp(command, "andi") == 0){
            if(alex_mode){
                char old_dp = *dp;
                (*dp)++;
                get_info(command, old_dp, *dp);
            }
            else{
                (*dp)++;
            }
        }
        else if(strcmp(command, "hias") == 0){
            if(alex_mode){
                char old_dp = *dp;
                (*dp)--;
                get_info(command, old_dp, *dp);
            }
            else{
                (*dp)--;
            }
        }
        else if(strcmp(command, "franky") == 0){
            if(alex_mode){
                get_info(command, *dp, 0);
            }
            switch (output_mode) {
                case 'd': printf("%d", *dp); break;
                case 'x': printf("%x", *dp); break;
                default: printf("%c", *dp); break;
            }

        }
        else if(strcmp(command, "stefan") == 0){
            if(alex_mode){
                char old_dp = *dp;
                get_info(command, old_dp, *input);
            }
            *dp = *input++;
        }
        else if(strcmp(command, "phil") == 0){
            if(alex_mode){
                get_info(command, 0, 0);
            }
            if (!*dp) {
                bracket_flag = 1;
                while(bracket_flag){
                    char* loopname = malloc(MAX_COMMAND_SIZE);
                    loopname = get_next_name(command_pointer, loopname);
                    if (strcmp(loopname, "phil") == 0) {
                        bracket_flag++;
                    }
                    else if (strcmp(loopname, "oliver") == 0) {
                        bracket_flag--;
                    }
                    free(loopname);
                }
            }
        }
        else if(strcmp(command, "oliver") == 0){
            if(alex_mode){
                get_info(command, 0, 0);
            }
            if (*dp) {
                //Move Pointer to last phil
                command_pointer -= shift+1;

                bracket_flag = 1;
                while(bracket_flag){
                    command_pointer = move_ptr_previous(command_pointer);
                    char* loopname = malloc(MAX_COMMAND_SIZE);
                    loopname = get_next_name(command_pointer, loopname);
                    if (strcmp(loopname, "oliver") == 0){
                        bracket_flag++;
                    }
                    else if (strcmp(loopname, "phil") == 0){
                        bracket_flag--;
                    }
                    free(loopname);
                }
            }
        }
        free(command);
        command = malloc(MAX_COMMAND_SIZE);
        command = get_next_name(command_pointer, command);
        shift = (int)strlen(command);
        command_pointer+=shift+1;
        free(command);
    }

    printf("\n");
}

char* read_file(char* file_name)
{

    char* buffer = 0;
    long length;
    FILE* f = fopen (file_name, "rb");

    if (f)
    {
        fseek (f, 0, SEEK_END);
        length = ftell (f);
        fseek (f, 0, SEEK_SET);
        buffer = malloc (length);
        if (buffer)
        {
            fread (buffer, 1, length, f);
        }
        fclose(f);
        return buffer;
    }
    free(buffer);
    printf("File not found");
    exit(1);
}

char* get_next_name(char* ptr, char* command){
    int len = 0;
    while(*ptr != ' '){
        if(*ptr == 0){
            break;
        }
        command[len] = *ptr;
        len++; ptr++;
    }
    command+='\0';
    return command;
}

char* move_ptr_previous(char* ptr){
    ptr-=2;
    while(*ptr != ' '){
        ptr--;
    }
    ptr++;
    return ptr;
}