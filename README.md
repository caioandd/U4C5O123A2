# U4C5O123A - Clock e Temporizadores

## Materiais necessários
1) Microcontrolador Raspberry Pi Pico W.
2) 03 LEDs de cores vermelho, verde e azul (GPIOs 11, 12, 13).
3) 03 Resistores de 330 Ω.
4) Push-button (GPIO 5).

## Funcionalidades do programa

1) Aciona-se o botão A.
2) Os três LEDs ligam.
3) A cada 3000ms um dos LEDs é apagado até que todos estejam desligados.

## Características

1) Com o emprego da função add_alarm_in_ms(), a mudança de estado dos LEDs deve ser implementa em funções de call-back do temporizador, a exemplo da rotina
trabalhada na aula síncrona - turn_off_callback(). 
2) Após acionamento, apertar o botão não causa nenhuma interfêrencia na execução do programa enquanto os LEDs estiverem acesos.

## Ensaio

https://drive.google.com/file/d/1kMwB_ZdJZff6uovP9FYxVCKNaIUJLoFE/view?usp=sharing