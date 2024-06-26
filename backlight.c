#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lvgl/lvgl.h"


#define PWM_PATH "/sys/class/pwm/pwmchip1/"
#define PERIOD_NS 1000000
#define MIN_DUTY_CYCLE_NS 0
#define MAX_DUTY_CYCLE_NS 1000000

void backl_set(unsigned int lvl) {
    LV_LOG_USER("%d\n", lvl);
    if (lvl > 100)
        lvl = 100;

    if (lvl < 1)
        lvl = 1;

    int duty_cycle_ns = (MAX_DUTY_CYCLE_NS/100) * lvl;
    FILE *duty_cycle_file = fopen(PWM_PATH "/pwm0/duty_cycle", "w");
    if (!duty_cycle_file) {
        perror("Failed to open PWM duty cycle");
        return 1;
    }
    fprintf(duty_cycle_file, "%d", duty_cycle_ns);
    fclose(duty_cycle_file);
}

int backl_init() {
    LV_LOG_USER("backl_init()\n");

    FILE *pwm_export = fopen(PWM_PATH "/export", "w");
    if (!pwm_export) {
        perror("Failed to open PWM export");
        return 1;
    }
    fprintf(pwm_export, "0");
    fclose(pwm_export);

    FILE *period_file = fopen(PWM_PATH "/pwm0/period", "w");
    if (!period_file) {
        perror("Failed to open PWM period");
        return 1;
    }
    fprintf(period_file, "%d", PERIOD_NS);
    fclose(period_file);

    FILE *polarity_file = fopen(PWM_PATH "/pwm0/polarity", "w");
    if (!polarity_file) {
        perror("Failed to open PWM polarity");
        return 1;
    }
    fprintf(polarity_file, "%s", "normal");
    fclose(polarity_file);

    FILE *enable_file = fopen(PWM_PATH "/pwm0/enable", "w");
    if (!enable_file) {
        perror("Failed to open PWM enable");
        return 1;
    }
    fprintf(enable_file, "1");
    fclose(enable_file);

    //int direction = 1; // 1 for increasing duty cycle, -1 for decreasing
    int duty_cycle_ns = 0;

    // while (1) {
    //     duty_cycle_ns += 10000 * direction;
    //     if(duty_cycle_ns == MAX_DUTY_CYCLE_NS)
    //         direction = -1;
    //     else if(duty_cycle_ns == MIN_DUTY_CYCLE_NS)
    //         direction = 1; 

    //     FILE *duty_cycle_file = fopen(PWM_PATH "/pwm0/duty_cycle", "w");
    //     if (!duty_cycle_file) {
    //         perror("Failed to open PWM duty cycle");
    //         return 1;
    //     }
    //     fprintf(duty_cycle_file, "%d", duty_cycle_ns);
    //     fclose(duty_cycle_file);

    //     usleep(50000); // Adjust this value for desired breathing speed
    // }

    // FILE *pwm_unexport = fopen(PWM_PATH "/unexport", "w");
    // if (!pwm_unexport) {
    //     perror("Failed to open PWM unexport");
    //     return 1;
    // }
    // fprintf(pwm_unexport, "0");
    // fclose(pwm_unexport);
    duty_cycle_ns = 1000000/2;
    FILE *duty_cycle_file = fopen(PWM_PATH "/pwm0/duty_cycle", "w");
    if (!duty_cycle_file) {
        perror("Failed to open PWM duty cycle");
        return 1;
    }
    fprintf(duty_cycle_file, "%d", duty_cycle_ns);
    fclose(duty_cycle_file);

    return 0;
}