#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

const char JEBEDIAH = 'J';
const char ALIEN = 'A';
const char MAGIOS = 'S';
const char BURNS = 'B';
const char SI = 'S';
const char NO = 'N';

bool es_fundador_valido(char respuesta) {
  return respuesta == JEBEDIAH || respuesta == ALIEN || respuesta == MAGIOS ||
         respuesta == BURNS;
}

void preguntar_fundador(int *puntaje) {
  char respuesta = '-';
  bool es_correcta = false;
  int intentos = 0;
  int puntos = 0;

  printf("¿Quién fundó realmente Springfield?\n");
  printf("[%c] Jebediah Springfield\n", JEBEDIAH);
  printf("[%c] Los Aliens\n", ALIEN);
  printf("[%c] Los Magios\n", MAGIOS);
  printf("[%c] Sr. Burns\n", BURNS);

  while (intentos < 3 && !es_correcta) {
    printf("Ingrese su respuesta: ");
    scanf(" %c", &respuesta);

    if (respuesta == JEBEDIAH) {
      printf("Correcto! Jebediah Springfield es el fundador.\n");
      puntos = puntos + 100;
      es_correcta = true;
    } else if (es_fundador_valido(respuesta)) {
      printf("Incorrecto. Intenta de nuevo.\n");
      puntos = puntos - 20;
      intentos++;
      printf("Intentos restantes: %d\n", 3 - intentos);
    } else {
      printf("Respuesta inválida. Por favor, ingrese una opción válida.\n");
    }
  }

  if (intentos == 3 && !es_correcta) {
    printf("-RECHAZADO-\n");
  }

  *puntaje = puntos;
}

void preguntar_promesa_secreto(int *puntaje) {
  char ingreso = '-';
  bool promete = false;

  printf("¿Promete mantener en secreto la existencia de los Magios?\n");
  printf("[%c] Sí\n", SI);
  printf("[%c] No\n", NO);

  while (ingreso != SI && ingreso != NO) {
    printf("Ingrese su respuesta: ");
    scanf(" %c", &ingreso);

    if (ingreso == SI) {
      *puntaje = 50;
      promete = true;
    } else if (ingreso == NO) {
      *puntaje = -300;
    } else {
      printf("Respuesta inválida. Por favor, ingrese una opción válida.\n");
    }
  }

  if (!promete) {
    printf("-RECHAZADO-\n");
  }
}

bool es_fecha_valida(char *fecha) { return true; }

void preguntar_fecha_nacimiento(int *puntaje) {
  char *fecha = "";

  while (!es_fecha_valida(fecha)) {
    printf("Ingrese su fecha de nacimiento (yyyy/mm): ");
    scanf("%s", fecha);
  }

  *puntaje = 0;
}

void preguntar_sacrificio_donas(int *puntaje) {
  int respuesta = -1;
  int puntos = 0;

  printf("¿Cuántas donas estaría dispuesto a sacrificar para el Número Uno?\n");

  while (respuesta < 0 || respuesta > 12) {
    printf("Ingrese su respuesta: ");
    scanf("%i", &respuesta);

    if (respuesta < 0) {
      printf("Respuesta inválida. Por favor, ingrese un número válido.\n");
    }
  }

  if (respuesta == 0) {
    puntos = -100;
  } else if (respuesta >= 1 && respuesta <= 3) {
    puntos = 10;
  } else if (respuesta >= 4 && respuesta <= 6) {
    puntos = 40;
  } else if (respuesta >= 7 && respuesta <= 9) {
    puntos = 70;
  } else if (respuesta >= 10 && respuesta <= 12) {
    puntos = 120;
  }

  *puntaje = puntos;
}

int calcular_puntaje_total(int *puntajes) {
  int puntaje = 0;

  for (int i = 0; i < 4; i++) {
    puntaje += puntajes[i];
  }

  return puntaje;
}

void dar_resultado(int puntaje_total) {
  printf("Puntaje total: %d\n", puntaje_total);

  if (puntaje_total < 0) {
    printf("Con las repuestas brindadas, tu estado es: -RECHAZADO-\n");
  } else if (puntaje_total <= 150) {
    printf("Con las repuestas brindadas, tu estado es: -ASPIRANTE-\n");
  } else if (puntaje_total <= 250) {
    printf("Con las repuestas brindadas, tu estado es: -MAGIO NOVATO-\n");
  } else if (puntaje_total <= 349) {
    printf("Con las repuestas brindadas, tu estado es: -MAGIO-\n");
  } else {
    printf("Con las repuestas brindadas, tu estado es: -LIDER SUPREMO-\n");
  }
}

int main() {
  int puntajes[4];
  preguntar_fundador(&puntajes[0]);
  preguntar_promesa_secreto(&puntajes[1]);
  preguntar_fecha_nacimiento(&puntajes[2]);
  preguntar_sacrificio_donas(&puntajes[3]);
  int puntaje_total = calcular_puntaje_total(puntajes);
  dar_resultado(puntaje_total);
  return 0;
}