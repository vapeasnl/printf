#include "main.h"
/**
 * init_params - clears
 * @params: params struct
 * @ap: argument pointer
 * Return: void
*/
void init_params(params_t *params)
{
    params->unsign = 0;

    params->pflag = 0;
    params->sflag = 0;
    params->hflag = 0;
    params->zflag = 0;
    params->mflag = 0;

    params->width = 0;
    params->precision = 0;

    params->h_mod = 0;
    params->l_mod = 0;
}
