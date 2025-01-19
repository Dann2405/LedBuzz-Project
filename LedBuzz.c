#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

// Definições da UART
// Por padrão, a UART stdout é `uart0`, então usaremos a segunda
#define UART_ID uart1
#define BAUD_RATE 115200

// Usar os pinos 4 e 5 para UART1
// Os pinos podem ser alterados, veja a tabela de seleção de função GPIO no datasheet para informações sobre atribuições de GPIO
#define UART_TX_PIN 4
#define UART_RX_PIN 5

// Definindo os GPIOs
#define LED_VERMELHO 13
#define LED_AZUL 12
#define LED_VERDE 11
#define BUZZER_A 21
#define BUZZER_B 10

// Função de inicialização das GPIOs
void initialize_gpio() {

    //confugarção dos leds como saída
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);

    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    //configuração dos buzzers como saída
    gpio_init(BUZZER_A);
    gpio_set_dir(BUZZER_A, GPIO_OUT);

    gpio_init(BUZZER_B);
    gpio_set_dir(BUZZER_B, GPIO_OUT);

    // Inicializa a UART
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
}
// Funções para controle dos LEDs
void turn_on_led(int gpio) {
    gpio_put(LED_VERMELHO, gpio == LED_VERMELHO);
    gpio_put(LED_AZUL, gpio == LED_AZUL);
    gpio_put(LED_VERDE, gpio == LED_VERDE);
}

void turn_off_leds() {
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERDE, 0);
}

void turn_on_all_leds() {
    gpio_put(LED_VERMELHO, 1);
    gpio_put(LED_AZUL, 1);
    gpio_put(LED_VERDE, 1);
}

// Funções para controle dos buzzers
void buzzer_beep(int frequency, int duration, int buzzer_pin) {
    // Defina o comportamento do buzzer para emitir um som com a frequência e duração especificadas
    // Você pode usar um PWM ou outro método, dependendo de como o buzzer está conectado
    gpio_put(buzzer_pin, 1);  // Ativa o buzzer
    sleep_ms(duration);       // Mantém o som por um tempo
    gpio_put(buzzer_pin, 0);  // Desativa o buzzer
}

//função para ativação dos buzzers A ou B
void sound_pattern_1() {
    buzzer_beep(800, 200, BUZZER_A);  // Frequência 800Hz por 200ms no BUZZER_A
    sleep_ms(100);                    // Pausa entre os beeps
    buzzer_beep(800, 200, BUZZER_A);  // Frequência 800Hz por 200ms no BUZZER_A
}

void sound_pattern_2() {
    buzzer_beep(1000, 400, BUZZER_B); // Frequência 1000Hz por 400ms no BUZZER_B
    sleep_ms(50);                     // Pausa entre os beeps
    buzzer_beep(1200, 300, BUZZER_B); // Frequência 1200Hz por 300ms no BUZZER_B
}

// Função para processar comandos recebidos
void process_command(const char *command) {
    if (strcmp(command, "Vermelho") == 0) {
        turn_on_led(LED_VERMELHO);
    } else if (strcmp(command, "Azul") == 0) {
        turn_on_led(LED_AZUL);
    } else if (strcmp(command, "Verde") == 0) {
        turn_on_led(LED_VERDE);
    } else if (strcmp(command, "Branco") == 0) {
        turn_on_all_leds();
    } else if (strcmp(command, "Desligar") == 0) {
        turn_off_leds();
    } else if (strcmp(command, "BuzzerA") == 0) {
        sound_pattern_1(BUZZER_A);
    } else if (strcmp(command, "BuzzerB") == 0) {
        sound_pattern_2(BUZZER_B);
    } else {
        printf("Comando desconhecido: %s\n", command);
        return;
    }

    printf("Comando processado: %s\n", command);
}

int main()
{
    stdio_init_all();

    initialize_gpio();

    // Envia uma string de teste na UART
    uart_puts(UART_ID, "Olá, UART!\n");

    printf("Programa inicializado. Aguardando comandos...\n");

    char command[32];
    while (true) {
        // Lê o comando via UART
        if (uart_is_readable(UART_ID)) {
            int index = 0;
            while (index < sizeof(command) - 1) {
                int character = uart_getc(UART_ID);
                if (character != PICO_ERROR_TIMEOUT) {
                    command[index++] = (char)character;
                    if (character == '\n' || character == '\r') {
                        break;
                    }
                }
            }
            command[index] = '\0';
            if (index > 0) {
                process_command(command);
            }
        } else {
            if (scanf("%32s", command) == 1) {
                process_command(command);
            }
        }
    }

    return 0;
}