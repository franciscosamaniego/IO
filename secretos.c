//cifra archivos usando
// cifrado tipo cesar
//primer arg nombre de archivos
//segundo arg cantidad de desplazamieto


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // char buffer[2000] = "";
  char line[250] = "";
  char *filename = argv[1];
  int shift = atoi(argv[2]);
  FILE *fp;
  FILE *temp_file;
  fp = fopen(filename, "r");
  temp_file = fopen("temp.txt", "a");
  while(fgets(line, 250, fp) != NULL) {
    // strcat(line, "\n");
    // strcat(buffer, line);
    fprintf(temp_file, "%s", line);
  }
  fclose(fp);
  fclose(temp_file);
  temp_file = fopen("temp.txt", "r");
  fp = fopen(filename, "w");
  while(fgets(line, 250, temp_file) != NULL) {
    // cifrar;
    for(int i = 0; i < 250; i++) {
        if(line[i] >= 'a' && line[i] <= 'z')
        line[i] = (((line[i] - 'a') + shift) % 26) + 'a';
        else if (line[i] >= 'A' && line[i] <= 'Z')
        line[i] = (((line[i] - 'A') + shift) % 26) + 'A';
    }
    fprintf(fp, "%s", line);
  }
  system("rm temp.txt");
  return 0;
}
