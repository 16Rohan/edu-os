#include "utils.h"
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void sleep_ms(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

void print_color(const char *color_code, const char *text) {
    printf("%s%s%s", color_code, text, COLOR_RESET);
}
