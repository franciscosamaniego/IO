#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char * dictionary[20] = {
    "gatos",
    "arbol",
    "genial",
    "tonto",
    "pibes",
    "audio",
    "casco",
    "raton",
    "lomas",
    "lomos",
    "perro",
    "loros",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
  };
  char *intentos;
  int r = rand() % 20;
  int j = 0;
  int c = 1;
  printf("%s\n", dictionary[r]);
  for (int i = 0; i < 5; i++) {
    scanf("%s\n", &intentos);
    while(c < argc) {
      j++;
      if(intentos[j] == dictionary[r][j]) {
        printf("Eureka\n");
        return 1;
      }
    }
    c++;
  }
  return 0;
}
