#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/clocks.h"

#define led_red 13
#define led_blue 12
#define led_green 11
#define botao_a 5

void componentes();

int64_t turn_off_callback(alarm_id_t id, void *user_data){
    if (gpio_get(led_red)==1 && gpio_get(led_blue)==1 && gpio_get(led_green)==1){
      gpio_put(led_red, false);
    }
    else if (gpio_get(led_red)==0 && gpio_get(led_blue)==1 && gpio_get(led_green)==1){
      gpio_put(led_red, false);
      gpio_put(led_green, false);
    }
    else if (gpio_get(led_red)==0 && gpio_get(led_blue)==1 && gpio_get(led_green)==0){
      gpio_put(led_red, false);
      gpio_put(led_green, false);
      gpio_put(led_blue, false);
    }
  return 0;
}

int main(){
    stdio_init_all();
    componentes();

    while (true){
        if (!gpio_get(botao_a) && gpio_get(led_red)==0 && gpio_get(led_blue)==0 && gpio_get(led_green)==0){
            // Liga todos os LEDs
            gpio_put(led_red, true);
            gpio_put(led_green, true);
            gpio_put(led_blue, true);

            add_alarm_in_ms(3000, turn_off_callback, NULL, false); // Desliga LED vermelho
            add_alarm_in_ms(6000, turn_off_callback, NULL, false); // Desliga LED verde
            add_alarm_in_ms(9000, turn_off_callback, NULL, false); // Desliga LED azul
        }
        sleep_ms(100); //Aliviar processamento
    }
    return 0;
}

//Inicialização de LEDs
void componentes(){
    gpio_init(led_red);
    gpio_init(led_blue);
    gpio_init(led_green);
    gpio_init(botao_a);

    gpio_set_dir(led_red, GPIO_OUT);
    gpio_set_dir(led_blue, GPIO_OUT);
    gpio_set_dir(led_green, GPIO_OUT);
    gpio_set_dir(botao_a, GPIO_IN);

    gpio_pull_up(botao_a);
}