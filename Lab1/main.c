/**
 *  main.c
 *  Lab1
 *
 *  Created by Paulo Passos on 31/08/16.
 *  Copyright © 2016 Paulo da Cunha Passos - 10/0118577. All rights reserved.
 */

/* Inclusoes do compilador */
#include <stdio.h>
#include <stdlib.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

/* Inclusoes de modulo de definicao */
//#include "grafo.h"
#include "testa_grafo.h"

int main() {
    CU_pSuite pSuite = NULL;
    
    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    
    /*Cria uma suite que conterá todos os testes*/
    pSuite = CU_add_suite("Teste do Modulo Grafo", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    /* add the tests to the suite */
    /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
    if ((NULL == CU_add_test(pSuite, "Testa criaGrafo", testaCriaGrafo)) ||
        (NULL == CU_add_test(pSuite, "Testa constroiGrafo", testaConstroiGrafo)) ||
        (NULL == CU_add_test(pSuite, "Testa retornaNomeGrafo", testaRetornaNomeGrafo)) ||
        (NULL == CU_add_test(pSuite, "Testa destroiGrafo", testaDestroiGrafo)) ||
        (NULL == CU_add_test(pSuite, "Testa zeraGrafo", testaZeraGrafo)) ||
        (NULL == CU_add_test(pSuite, "Testa retornaNo", testaRetornaNo)) ||
        (NULL == CU_add_test(pSuite, "Testa adicionaVertice", testaAdicionaVertice)) ||
        (NULL == CU_add_test(pSuite, "Testa removeVertice", testaRemoveVertice)) ||
        (NULL == CU_add_test(pSuite, "Testa retornaAresta", testaRetornaAresta)) ||
        (NULL == CU_add_test(pSuite, "Testa adicionaAresta", testaAdicionaAresta)) ||
        (NULL == CU_add_test(pSuite, "Testa removeAresta", testaRemoveAresta)) ||
        (NULL == CU_add_test(pSuite, "Testa retornaValorVertice", testaRetornaValorVertice)) ||
        (NULL == CU_add_test(pSuite, "Testa mudarValorVertice", testaMudaValorVertice)) ||
        (NULL == CU_add_test(pSuite, "Testa retornaValorAresta", testaRetornaValorAresta)) ||
        (NULL == CU_add_test(pSuite, "Testa mudarValorAresta", testaMudaValorAresta)) ||
        (NULL == CU_add_test(pSuite, "Testa vizinhos", testaVizinhos)) ||
        (NULL == CU_add_test(pSuite, "Testa adjacente", testaAdjacente))
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    // Run all tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");
    
     
     // Run all tests using the console interface
     /* CU_console_run_tests(); */
    
    /* Clean up registry and return */
    CU_cleanup_registry();
    return CU_get_error();
    
}



