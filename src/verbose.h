//
// Created by Michael Bockel on 24.11.22.
//

#include <stdio.h>

void get_info(char* command, char dp_old, char dp_new){
    if(strcmp(command, "mike") == 0){
        printf("\ncommand: mike -> old value: %i -> shift pointer right -> new value: %i\n", dp_old, dp_new);
    }
    else if(strcmp(command, "patricia") == 0){
        printf("\ncommand: patricia -> old value: %i -> shift pointer left -> new value: %i\n", dp_old, dp_new);
    }
    else if(strcmp(command, "andi") == 0){
        printf("\ncommand: andi -> old value: %i -> increment value by 1 -> new value: %i\n", dp_old, dp_new);
    }
    else if(strcmp(command, "hias") == 0){
        printf("\ncommand: hias -> old value: %i -> decrement value by 1 -> new value: %i\n", dp_old, dp_new);
    }
    else if(strcmp(command, "franky") == 0){
        printf("\ncommand: franky -> print value to console\n");
    }
    else if(strcmp(command, "stefan") == 0){
        printf("\ncommand: stefan -> old value: %i -> read input -> new value: %i\n", dp_old, dp_new);
    }
    else if(strcmp(command, "phil") == 0){
        printf("\ncommand: phil -> starting loop");
    }
    else if(strcmp(command, "oliver") == 0){
        printf("\ncommand: oliver -> ending loop ");
    }
    else{
        printf("Something strange is goint on");
    }
}