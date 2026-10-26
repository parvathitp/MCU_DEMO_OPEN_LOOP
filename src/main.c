/*
 * main.c
 *
 * S32K344 + MCSPTE1AK344
 * Application entry point.
 *
 * Layer flow:
 *      MAIN -> APPLICATION -> SERVICE -> EAL -> NXP RTD
 *
 * NOTE:
 * EAL is intentionally not implemented yet. For the current working stage,
 * Service functions call the same NXP RTD APIs directly. Later only the
 * Service implementation needs to be redirected to EAL.
 */

#include "init.h"
#include "app.h"

int main(void)
{
    software_init();
    APP_Init();

    while (1)
    {
        APP_MainFunction();
    }

    return 0;
}
