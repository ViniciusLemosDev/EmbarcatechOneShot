#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED_BLUE 12
#define LED_RED 13
#define LED_GREEN 11
#define BUTTON 5

volatile bool button_pressed = false;

bool turn_off_callback(struct repeating_timer *t) {
    static int state = 0;
    if (state == 0) {
        gpio_put(LED_BLUE, 0);
        state++;
    } else if (state == 1) {
        gpio_put(LED_RED, 0);
        state++;
    } else if (state == 2) {
        gpio_put(LED_GREEN, 0);
        state = 0;
        button_pressed = false;
    }
    return false; // Não repetir
}

void button_callback(uint gpio, uint32_t events) {
    if (!button_pressed) {
        button_pressed = true;
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 1);
        gpio_put(LED_GREEN, 1);
        add_alarm_in_ms(3000, (alarm_callback_t)turn_off_callback, NULL, false);
        add_alarm_in_ms(6000, (alarm_callback_t)turn_off_callback, NULL, false);
        add_alarm_in_ms(9000, (alarm_callback_t)turn_off_callback, NULL, false);
    }
}

int main() {
    stdio_init_all();
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_callback);
    
    while (1) {
        sleep_ms(1000);
        printf("Sistema aguardando pressionamento do botão...\n");
    }
}