#include "boot.h"
#include "utils.h"
#include <stdio.h>

void simulate_boot(void) {
    print_color(COLOR_CYAN, "Bootloader loading...\n");
    sleep_ms(300);
    
    printf("Checking system memory");
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        sleep_ms(200);
    }
    printf(" [");
    print_color(COLOR_GREEN, "OK");
    printf("]\n");

    printf("Loading kernel modules");
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        sleep_ms(200);
    }
    printf(" [");
    print_color(COLOR_GREEN, "OK");
    printf("]\n");

    sleep_ms(200);
    print_color(COLOR_CYAN, "Handing over to kernel...\n\n");
    sleep_ms(400);
}
