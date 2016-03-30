#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

char* madlib(char* template, char* adjective, char* noun, char* verb) {    
    char *newString = malloc(strlen(template) + strlen(adjective) + strlen(noun) + strlen(verb));
    sprintf(newString, template, adjective, noun, verb);
    
    // printf("%s\n", newString);
    
    return newString;
}