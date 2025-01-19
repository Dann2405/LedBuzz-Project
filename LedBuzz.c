#include <stdio.h>
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
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);

    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    gpio_init(BUZZER_A);
    gpio_set_dir(BUZZER_A, GPIO_OUT);

    gpio_init(BUZZER_B);
    gpio_set_dir(BUZZER_B, GPIO_OUT);

    // Inicializa a UART
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
}

int main()
{
    stdio_init_all();

    initialize_gpio();

    // Envia uma string de teste na UART
    uart_puts(UART_ID, "Olá, UART!\n");

    printf("Programa inicializado. Aguardando comandos...\n");

    return 0;
}