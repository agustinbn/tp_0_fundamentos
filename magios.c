#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

const char JEBEDIAH = 'J';
const char ALIEN = 'A';
const char MAGIOS = 'S';
const char BURNS = 'B';

const int MAX_INTENTOS = 3;
const int PUNTOS_CORRECTA_FUNDADOR = 100;
const int PUNTOS_INCORRECTA_FUNDADOR = 20;

const char SI = 'S';
const char NO = 'N';
const int PUNTOS_PROMESA_SECRETA_SI = 50;
const int PUNTOS_PROMESA_SECRETA_NO = -300;

const int PUNTOS_0_DONAS = -100;
const int PUNTOS_3_DONAS = 10;
const int PUNTOS_6_DONAS = 40;
const int PUNTOS_9_DONAS = 70;
const int PUNTOS_12_DONAS = 120;

const int PUNTOS_RECHAZADO = 0;
const int PUNTOS_ASPIRANTE = 150;
const int PUNTOS_MAGIO_NOVATO = 250;
const int PUNTOS_MAGIO = 349;

const int ANIO_MINIMO = 1926;
const int ANIO_ACTUAL = 2026;
const int MES_ACTUAL = 3;
const int EDAD_MINIMA = 18;

/*
 * Pre: -
 * Post: devuelve true si respuesta es una de las opciones válidas.
 */
bool es_fundador_valido(char respuesta) {
  return respuesta == JEBEDIAH || respuesta == ALIEN || respuesta == MAGIOS ||
         respuesta == BURNS;
}

/*
 * Pre: -.
 * Post: agrega o quita puntos segun la respuesta. Si se agotan 3
 *      intentos sin acertar, imprime -RECHAZADO- y termina el programa.
 */
void preguntar_fundador(int *puntaje, bool *terminar_programa) {
  char respuesta = '-';
  bool es_correcta = false;
  int intentos = 0;
  int puntos = 0;

  printf("¿Quién fundó realmente Springfield?\n");
  printf("[%c] Jebediah Springfield\n", JEBEDIAH);
  printf("[%c] Los Aliens\n", ALIEN);
  printf("[%c] Los Magios\n", MAGIOS);
  printf("[%c] Sr. Burns\n", BURNS);

  while (intentos < MAX_INTENTOS && !es_correcta) {
    printf("Ingrese su respuesta: ");
    scanf(" %c", &respuesta);

    if (respuesta == JEBEDIAH) {
      printf("Correcto! Jebediah Springfield es el fundador.\n");
      puntos += PUNTOS_CORRECTA_FUNDADOR;
      es_correcta = true;
    } else if (es_fundador_valido(respuesta)) {
      printf("Incorrecto. Intenta de nuevo.\n");
      puntos -= PUNTOS_INCORRECTA_FUNDADOR;
      intentos++;
      printf("Intentos restantes: %d\n", MAX_INTENTOS - intentos);
    } else {
      printf("Respuesta inválida. Por favor, ingrese una opción válida (%c, "
             "%c, %c o %c).\n",
             JEBEDIAH, ALIEN, MAGIOS, BURNS);
    }
  }

  if (intentos == MAX_INTENTOS && !es_correcta) {
    printf("-RECHAZADO-\n");
    *terminar_programa = true;
  }

  *puntaje = puntos;
}

/*
 * Pre: -.
 * Post: agrega o quita puntos segun la respuesta.
 */
void preguntar_promesa_secreto(int *puntaje) {
  char ingreso = '-';

  printf("¿Promete mantener en secreto la existencia de los Magios?\n");
  printf("[%c] Sí\n", SI);
  printf("[%c] No\n", NO);

  while (ingreso != SI && ingreso != NO) {
    printf("Ingrese su respuesta: ");
    scanf(" %c", &ingreso);

    if (ingreso == SI) {
      *puntaje = PUNTOS_PROMESA_SECRETA_SI;
    } else if (ingreso == NO) {
      *puntaje = PUNTOS_PROMESA_SECRETA_NO;
    } else {
      printf("Respuesta inválida. Por favor, ingrese una opción válida (%c o "
             "%c).\n",
             SI, NO);
    }
  }
}

/*
 * Pre: la fecha es un string.
 * Post: devuelve true si la fecha cumple el formato yyyy/m o yyyy/mm y es
 * valida.
 */
bool es_fecha_valida(char *fecha) {
  if (strlen(fecha) < 6 || strlen(fecha) > 7) {
    return false;
  }

  if (fecha[4] != '/') {
    return false;
  }

  int anio = 0;
  int mes = 0;

  char extra = '\0';
  if (sscanf(fecha, "%4d/%2d%c", &anio, &mes, &extra) != 2) {
    return false;
  }

  if (anio <= 0 || mes <= 0) {
    return false;
  }

  if (anio < ANIO_MINIMO || (anio == ANIO_MINIMO && mes < MES_ACTUAL) ||
      anio > ANIO_ACTUAL || (anio == ANIO_ACTUAL && mes > MES_ACTUAL)) {
    return false;
  }

  if (mes < 1 || mes > 12) {
    return false;
  }

  return true;
}

/*
 * Pre: la fecha es un string de 7 caracteres.
 * Post: devuelve la edad del usuario segun la fecha de nacimiento.
 */
int calcular_edad(char *fecha) {
  int anio = 0;
  int mes = 0;
  sscanf(fecha, "%4d/%2d", &anio, &mes);

  int edad = ANIO_ACTUAL - anio;
  int meses_restantes = MES_ACTUAL - mes;

  if (meses_restantes < 0) {
    edad--;
  }

  return edad;
}

/*
 * Pre: -.
 * Post: agrega una cantidad de puntos especifica segun la fecha de nacimiento
 * del usuario.
 */
void preguntar_fecha_nacimiento(int *puntaje, bool *terminar_programa) {
  char fecha[8] = "";

  while (!es_fecha_valida(fecha)) {
    printf("Ingrese su fecha de nacimiento (yyyy/m o yyyy/mm): ");
    scanf("%7s", fecha);

    if (!es_fecha_valida(fecha)) {
      printf(
          "Fecha inválida. Por favor, ingrese una fecha en formato válido:\n");
      printf(
          "- El año debe tener exactamente 4 dígitos (por ejemplo, 1999).\n");
      printf("- El mes debe tener 1 o 2 dígitos entre 1 y 12.\n");
      printf("- Ambos números deben ser positivos.\n");
      printf("- El formato debe ser yyyy/m o yyyy/mm (ejemplo: 2005/7 o "
             "2005/11).\n");
      printf("- No puede ser anterior a 1926/03 ni posterior a 2026/03.\n");
    }
  }

  int edad = calcular_edad(fecha);

  if (edad < EDAD_MINIMA) {
    printf("-RECHAZADO-\n");
    *terminar_programa = true;
    return;
  }

  *puntaje = edad * 2;
}

/*
 * Pre: -
 * Post: agrega una cantidad de puntos especifica segun la cantidad de donas que
 * ingrese el usuario.
 */
void preguntar_sacrificio_donas(int *puntaje) {
  int respuesta = -1;
  int puntos = 0;

  printf("¿Cuántas donas estaría dispuesto a sacrificar para el Número Uno?\n");

  while (respuesta < 0 || respuesta > 12) {
    printf("Ingrese su respuesta: ");
    scanf("%i", &respuesta);

    if (respuesta < 0 || respuesta > 12) {
      printf(
          "Respuesta inválida. Por favor, ingrese un número válido (0-12).\n");
    }
  }

  if (respuesta == 0) {
    puntos = PUNTOS_0_DONAS;
  } else if (respuesta <= 3) {
    puntos = PUNTOS_3_DONAS;
  } else if (respuesta <= 6) {
    puntos = PUNTOS_6_DONAS;
  } else if (respuesta <= 9) {
    puntos = PUNTOS_9_DONAS;
  } else if (respuesta <= 12) {
    puntos = PUNTOS_12_DONAS;
  }

  *puntaje = puntos;
}

/*
 * Pre: la variable puntajes tiene 4 elementos.
 * Post: devuelve la suma de los 4 items de la variable puntajes.
 */
int calcular_puntaje_total(int puntajes[4]) {
  int puntaje = 0;

  for (int i = 0; i < 4; i++) {
    puntaje += puntajes[i];
  }

  return puntaje;
}

/*
 * Pre: -
 * Post: imprime el estado segun la cantidad de puntos obtenida.
 */
void dar_resultado(int puntajes[4]) {
  int puntaje_total = calcular_puntaje_total(puntajes);

  if (puntaje_total < PUNTOS_RECHAZADO) {
    printf("Con las respuestas brindadas, tu estado es: -RECHAZADO-\n");
  } else if (puntaje_total <= PUNTOS_ASPIRANTE) {
    printf("Con las respuestas brindadas, tu estado es: -ASPIRANTE-\n");
  } else if (puntaje_total <= PUNTOS_MAGIO_NOVATO) {
    printf("Con las respuestas brindadas, tu estado es: -MAGIO NOVATO-\n");
  } else if (puntaje_total <= PUNTOS_MAGIO) {
    printf("Con las respuestas brindadas, tu estado es: -MAGIO-\n");
  } else {
    printf("Con las respuestas brindadas, tu estado es: -LIDER SUPREMO-\n");
  }
}

int main() {
  int puntajes[4] = {0, 0, 0, 0};
  bool terminar_programa = false;
  preguntar_fundador(&puntajes[0], &terminar_programa);
  if (terminar_programa) {
    return 0;
  }
  preguntar_promesa_secreto(&puntajes[1]);
  preguntar_fecha_nacimiento(&puntajes[2], &terminar_programa);
  if (terminar_programa) {
    return 0;
  }
  preguntar_sacrificio_donas(&puntajes[3]);
  dar_resultado(puntajes);
  return 0;
}