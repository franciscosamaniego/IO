#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 200

int main(int argc, char *argv[]) {
  char *hash = argv[1];
  char *wordlist = argv[2];
  char buffer[MAXLINE];
  FILE *fp;
  FILE *temp;
  fp = fopen(wordlist, "r");
  while (fgets(buffer, MAXLINE, fp) != NULL) {
    temp = fopen("temp", "w");
    for (int i = 0; i < 200; i++) {
      if(buffer[i] == '\n')   buffer[i] = 0;
    }
    char command[100] = "md5sum <<< \"";
    strcat(command, buffer);
    strcat(command, "\" > temp");
    system(command);
    fclose(temp);
    //ya tenemos el hash en temp
    //vemos si coincide
    char hash_to_compare[33];
    char line_read[MAXLINE];
    temp = fopen("temp", "r");
    fgets(line_read, MAXLINE, temp);
    strncpy(hash_to_compare, line_read, 32);
    hash_to_compare[32] = 0;
    if(strcmp(hash, hash_to_compare) == 0)
    printf("Password encontrado! Es: %s\n", buffer);
    else
    printf("Password no matcheado\n");
    fclose(temp);
  }
  fclose(fp);
  return 0;
}
