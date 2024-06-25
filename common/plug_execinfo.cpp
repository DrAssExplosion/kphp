#include "common/plug_execinfo.h"


int backtrace (void **__array, int __size)
{
    if (__array && __size) {};

    return 1;
}


char **backtrace_symbols (void *const *__array, int __size)
{
    if (__array && __size) {};
    return nullptr;
}


void backtrace_symbols_fd (void *const *__array, int __size, int __fd)
{
    if (__array && __size && __fd) {};
}