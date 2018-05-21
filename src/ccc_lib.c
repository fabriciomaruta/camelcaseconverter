
#include "ccc_lib.h"
#include <string.h>
#include <ctype.h>

void camelcase_to_underline(char *input, char *output) {
  int i = 0, j = 0, flag = 0;
  while(input[i] !='\0'){
    if(input[i]>= 65 && input[i]<=90){
      flag++;
    }
    i++;
  }
  i = 0;
  if(flag <=1){
    strcpy(output, input);
    return;
  }
  while(input[i] != '\0'){
    if(input[i] >= 65 && input[i]<=90){
        input[i] = tolower(input[i]);
      if(i != 0){
        output[j] = '_';
        j++;
      }
    }
    output[j] = input[i];
    i++;
    j++;
  }
  return;
}

void underline_to_camelcase(char *input, char *output) {
  int i=0, j=0;
  while(input[i] != '\0'){
    while(input[i] != '_'){
      if(i==0){
        output[j] = toupper(input[i]);
        i++;
        j++;
      }
      else if(input[i] == '\0'){
        return;
      }
      output[j] = input[i];
      i++;
      j++;
    }
    i++;
    output[j] = toupper(input[i]);
    j++;
    i++;

  }
  return;
}
