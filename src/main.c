#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void codersbay(char* command_pointer, char *input);
char* read_file(char* file_name);
char* get_next_name(char* ptr);
char* move_ptr_previous(char* ptr);
void usage_check(int argc, char* argv[]);

int main(int argc, char *argv[]) {
    usage_check(argc, argv);
    char* code = read_file(argv[1]);
    char* input = "";
    codersbay(code, input);
    return 0;
}

void usage_check(int argc, char* argv[]){
    if(argc < 2){
        printf("Usage: bay <source.cbl>");
        exit(1);
    }
}

#define DATASIZE 1001
void codersbay(char* command_pointer, char* input) {
    int bracket_flag;
    int shift = 0;
    char data[DATASIZE] = {0};
    char *dp;
    dp = &data[DATASIZE / 2];
    char *command;

    while (*command_pointer+shift+1 != NULL && *command_pointer != 0)
    {
        command = get_next_name(command_pointer);
        if (strcmp(command, "mike") == 0) {
            dp++;
        }
        else if(strcmp(command, "patricia") == 0){
            dp--;
        }
        else if(strcmp(command, "andi") == 0){
            (*dp)++;
        }
        else if(strcmp(command, "hias") == 0){
            (*dp)--;
        }
        else if(strcmp(command, "franky") == 0){
            printf("%c", *dp);
        }
        else if(strcmp(command, "stefan") == 0){
            *dp = *input++;
        }
        else if(strcmp(command, "phil") == 0){
            if (!*dp) {
                bracket_flag = 1;
                while(bracket_flag){
                    char *loopname = get_next_name(command_pointer);
                    if (strcmp(loopname, "phil") == 0) {
                        bracket_flag++;
                    }
                    else if (strcmp(loopname, "oliver") == 0) {
                        bracket_flag--;
                    }
                }
            }
        }
        else if(strcmp(command, "oliver") == 0){
            if (*dp) {
                //Move Pointer to last phil
                command_pointer -= shift+1;

                bracket_flag = 1;
                while(bracket_flag){
                    command_pointer = move_ptr_previous(command_pointer);
                    char *loopname = get_next_name(command_pointer);
                    if (strcmp(loopname, "oliver") == 0){
                        bracket_flag++;
                    }
                    else if (strcmp(loopname, "phil") == 0){
                        bracket_flag--;
                    }
                }
            }
        }

        command = get_next_name(command_pointer);
        shift = strlen(command);
        command_pointer+=shift+1;
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

char* get_next_name(char* ptr){
    int len = 0;
    char name[10] = {0};
    while(*ptr != ' '){
        if(*ptr == NULL){
            break;
        }
        name[len] = *ptr;
        len++; ptr++;
    }
    name[len] = '\0';
    return name;
}

char* move_ptr_previous(char* ptr){
    ptr-=2;
    while(*ptr != ' '){
        ptr--;
    }
    ptr++;
    return ptr;
}