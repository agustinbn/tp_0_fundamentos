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

int puntos = 0;

// UTILS

void agregar_puntos(int cantidad) { puntos += cantidad; }

void quitar_puntos(int cantidad) { puntos -= cantidad; }

// PREGUNTA 1

void pregunta_fundador() {
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
      agregar_puntos(100);
      es_correcta = true;
    } else if (respuesta == ALIEN || respuesta == MAGIOS ||
               respuesta == BURNS) {
      printf("Incorrecto. Intenta de nuevo.\n");
      quitar_puntos(20);
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

void pregunta_promesa_secreto() {
  char respuesta = '-';

  printf("¿Promete mantener en secreto la existencia de los Magios?\n");
  printf("[S] Si\n");
  printf("[N] No\n");

  while (!respuesta) {
    printf("Ingrese su respuesta: ");
    scanf(" %c", &respuesta);

    if (respuesta == SI) {
      printf("Correcto! %s promete mantener en secreto la existencia de los Magios.\n", MAGIOS_NAME);
      agregar_puntos(50);
      respuesta = true;
    } else if (respuesta == NO) {
      printf("Incorrecto. Intenta de nuevo.\n");
      quitar_puntos(300);
    } else {
      printf("Respuesta inválida. Por favor, ingrese una opción válida.\n");
    }
  }
  
}

int main() {
  pregunta_fundador();
  pregunta_promesa_secreto();
  return 0;
}