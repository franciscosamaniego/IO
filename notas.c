//app para tomar notas

#include <stdio.h>

int main(void) {
  int choice;
  FILE * fp;
  int c;
  char nota[100] = "";
  while (1) {
    printf("Hola, soy la app de notas\n");
    printf("1) Ver notas\n");
    printf("2) Agregar notas\n");
    printf("3) Borrar todas las notas\n");
    printf("4) Salir\n");
    printf("Elegi algo\n");
    scanf("%d", &choice);
    c = getchar();
    switch (choice) {
      case 1:
      fp = fopen("notas.txt", "r");
      printf("-------NOTAS-------\n");
      while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
      }
      printf("-------FIN---------\n");
      fclose(fp);
      break;
    case 2:
      fp = fopen("notas.txt", "a");
      printf("Que queres anotar?\n");
      fgets(nota, 100, stdin);
      fprintf(fp, "%s", nota);
      fclose(fp);
      break;
    case 3:
      fp = fopen("notas.txt", "w");
      fclose(fp);
      break;
    case 4:
    return 0;
      break;
    default:
      printf("Opcion incorrecta\n");
    }
  }
  return 0;
}
