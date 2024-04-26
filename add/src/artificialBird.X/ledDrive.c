/*
 * File:   ledDrive.c
 * Author: tamag
 *
 * Created on 2024/02/12, 18:59
 */

#include "headers/ledDrive.h"

#include <stdio.h>
#include <stdlib.h>

#ifndef CPPUTEST
#include "mcc_generated_files/system/system.h"
#endif
/*
 * variable
 */

/*
 * functions
 */

/**
 ** @brief Doxygen の動作確認用の関数
 **
 ** @details Doxygen の動作確認用の関数
 ** @param a
 ** @return a
 */
int ledDrive(void) {
#ifdef CPPUTEST
    printf("mock");
#else
    OUT1_Toggle();
#endif
}
