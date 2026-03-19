#include <stdbool.h>
#include <stdio.h>

const char JEBEDIAH = 'J';
const char *JEBEDIAH_NAME = "Jebediah Springfield";

const char ALIEN = 'A';
const char *ALIEN_NAME = "Los Aliens";

const char MAGIOS = 'S';
const char *MAGIOS_NAME = "Los Magios";

const char BURNS = 'B';
const char *BURNS_NAME = "Sr. Burns";

const char SI = 'S';
const char NO = 'N';

// PREGUNTA 1

void preguntar_fundador(int *puntaje) {
  char respuesta = '-';
  bool es_correcta = false;
  int intentos = 0;

  printf("¿Quién fundó realmente Springfield?\n");
  printf("[%c] %s\n", JEBEDIAH, JEBEDIAH_NAME);
  printf("[%c] %s\n", ALIEN, ALIEN_NAME);
  printf("[%c] %s\n", MAGIOS, MAGIOS_NAME);
  printf("[%c] %s\n", BURNS, BURNS_NAME);

  while (intentos < 3 && !es_correcta) {
    printf("Ingrese su respuesta: ");
    scanf(" %c", &respuesta);

    if (respuesta == JEBEDIAH) {
      printf("Correcto! %s es el fundador.\n", JEBEDIAH_NAME);
      *puntaje = *puntaje + 100;
      es_correcta = true;
    } else if (respuesta == ALIEN || respuesta == MAGIOS ||
               respuesta == BURNS) {
      printf("Incorrecto. Intenta de nuevo.\n");
      *puntaje = *puntaje - 20;
      intentos++;
      printf("Intentos restantes: %d\n", 3 - intentos);
    } else {
      printf("Respuesta inválida. Por favor, ingrese una opción válida.\n");
    }
  }

  if (intentos == 3 && !es_correcta) {
    printf("-RECHAZADO-\n");
  }
}

// PREGUNTA 2

void preguntar_promesa_secreto(int *puntaje) {
  char ingreso = '-';
  bool respuesta = false;

  printf("¿Promete mantener en secreto la existencia de los Magios?\n");
  printf("[S] Si\n");
  printf("[N] No\n");

  while (ingreso != SI && ingreso != NO) {
    printf("Ingrese su respuesta: ");
    scanf(" %c", &ingreso);

    if (ingreso == SI) {
      printf("Correcto! %s promete mantener en secreto la existencia de los "
             "Magios.\n",
             MAGIOS_NAME);
      *puntaje = 50;
      respuesta = true;
    } else if (ingreso == NO) {
      printf("Revelar el secreto de los Magios implica prácticamente la "
             "eliminación del aspirante.\n");
      *puntaje = -300;
    } else {
      printf("Respuesta inválida. Por favor, ingrese una opción válida.\n");
    }
  }

  if (ingreso == NO) {
    printf("-RECHAZADO-\n");
  }
}

void preguntar_edad(int *puntaje) {
  int edad = 0;

  while (edad <= 0) {
    printf("Ingrese su edad: ");
    scanf("%i", &edad);

    if (edad <= 0) {
      printf("Respuesta inválida. Por favor, ingrese una edad válida.\n");
    }
  }

  *puntaje = (edad * 2);
}

int main() {
  int puntajes[4];
  preguntar_fundador(&puntajes[0]);
  preguntar_promesa_secreto(&puntajes[1]);
  preguntar_edad(&puntajes[2]);
  printf("Puntaje 1: %d\n", puntajes[0]);
  printf("Puntaje 2: %d\n", puntajes[1]);
  printf("Puntaje 3: %d\n", puntajes[2]);
  return 0;
}