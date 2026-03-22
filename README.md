## Trabajo Práctico Nº 0 - Prueba de Iniciación de los Magios

Los Magios son una antigua sociedad secreta que opera en las sombras de Springfield. A lo largo de los años han ejercido su influencia sobre distintos aspectos de la ciudad mediante rituales misteriosos, decisiones arbitrarias y una gran cantidad de donas.

Recientemente, la logia abrió una nueva convocatoria para aceptar nuevos miembros. Homero Simpson decidió postularse y, como cualquier aspirante, deberá atravesar la Prueba de Iniciación Magia.

Para determinar si una persona es digna de ingresar a la sociedad secreta, los Magios realizan una serie de preguntas rituales. Según las respuestas obtenidas, se calculará un puntaje de dignidad magística que determinará si el aspirante puede formar parte de la logia o no.

## Requisitos

- Compilador **GCC** con soporte para **C99** (por ejemplo, el que trae Xcode Command Line Tools en macOS, o `gcc` en Linux).

## Compilar

Desde la raíz del proyecto:

```bash
gcc magios.c -Wall -Werror -Wconversion -std=c99 -o magios
```

| Opción         | Rol breve                                        |
| -------------- | ------------------------------------------------ |
| `-Wall`        | Activa advertencias útiles del compilador.       |
| `-Werror`      | Trata las advertencias como errores.             |
| `-Wconversion` | Avisa conversiones implícitas que pueden fallar. |
| `-std=c99`     | Usa el estándar C99 (coincide con el código).    |
| `-o magios`    | Genera el ejecutable con nombre `magios`.        |

Si la compilación termina sin mensajes, se creó el binario `magios` en el directorio actual.

## Ejecutar

```bash
./magios
```

No recibe argumentos por línea de comandos: responde en la consola cuando el programa lo pida (letras para opciones múltiple y números donde corresponda).

## Limpiar

Para borrar solo el ejecutable generado:

```bash
rm magios
```

## Catedra

Este trabajo práctico corresponde a la materia **Fundamentos de Programación**, dictada en la **Cátedra Méndez**.

Para más información sobre la cursada y los contenidos, se puede consultar el sitio oficial:  
https://fundamendez.com.ar/
