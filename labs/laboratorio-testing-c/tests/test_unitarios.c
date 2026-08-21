#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/* ═══════════════════════════════════════════════════════════════════════════
 *  TESTS ESCRITOS — ya funcionan, son el punto de partida
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_carrito_nuevo(void) {
    printf("\n[carrito nuevo]\n");
    Carrito c;
    carrito_init(&c);
    ASSERT_IGUAL(0, carrito_contar(&c));
}

void test_agregar_uno(void) {
    printf("\n[agregar un producto]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    ASSERT_IGUAL(1, carrito_agregar(&c, p));   /* devuelve 1 = exito */
    ASSERT_IGUAL(1, carrito_contar(&c));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE A — Agregar el siguiente test (ver README.md, Parte 4)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_total_precio_unitario(void) {
    printf("\n[total: un producto, cantidad 1]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    carrito_agregar(&c, p);
    ASSERT_IGUAL(350, carrito_total(&c));
}


/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE B — Completar los blancos (ver README.md, Parte 5)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_total_con_cantidad(void) {
    printf("\n[total: un producto, cantidad 2]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 2};  /* 350 x 2 = 700 */
    carrito_agregar(&c, p);
    ASSERT_IGUAL(700, carrito_total(&c));  /* <-- completar el valor esperado */
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE C — Escribir un test propio (ver README.md, Parte 7)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_carrito_lleno(void){
    printf("\n[el carrito esta lleno]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Galletitas", 300, 1};
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    ASSERT_IGUAL(0, carrito_agregar(&c,p));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  EJERCITACION EXTRA — E1
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_buscar_primer_producto(void) {
    printf("\n[buscar primer producto]\n");
    Carrito c;
    carrito_init(&c);

    Producto p = {"Pan", 200, 1};
    carrito_agregar(&c, p);

    ASSERT_IGUAL(0, carrito_buscar(&c, "Pan"));
}

void test_buscar_producto(void) {
    printf("\n[buscar un producto]\n");
    Carrito c;
    carrito_init(&c);

    Producto p1 = {"Pan", 200, 1};
    Producto p2 = {"Leche", 350, 2};

    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);

    ASSERT_IGUAL(1, carrito_buscar(&c, "Leche"));
}

void test_buscar_inexistente(void) {
    printf("\n[buscar producto inexistente]\n");
    Carrito c;
    carrito_init(&c);

    Producto p = {"Pan", 200, 1};
    carrito_agregar(&c, p);

    ASSERT_IGUAL(-1, carrito_buscar(&c, "Leche"));
}


/* ═══════════════════════════════════════════════════════════════════════════
 *  main
 * ═══════════════════════════════════════════════════════════════════════════ */

int main(void) {
    printf("=== Tests unitarios ===");
    test_carrito_nuevo();
    test_agregar_uno();
    test_total_precio_unitario(); 
    test_total_con_cantidad();    
    test_carrito_lleno();
    //test ejercitacion extra 1
    test_buscar_primer_producto();   
    test_buscar_producto();    
    test_buscar_inexistente(); 
    RESUMEN();
    return EXIT_CODE();
}
