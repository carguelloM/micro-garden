#define F_CPU 16000000UL
#define BAUD 9600
#define UBRR_VAL ((F_CPU / (16UL * BAUD)) - 1)

#include <avr/io.h>
#include <util/delay.h>

static void uart_init(void) {
    UBRR0H = (uint8_t)(UBRR_VAL >> 8);
    UBRR0L = (uint8_t)(UBRR_VAL);
    UCSR0B = (1 << TXEN0);          // enable transmitter
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8N1
}

static void uart_putc(char c) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}

static void uart_puts(const char *s) {
    while (*s) uart_putc(*s++);
}

int main(void) {
    uart_init();

    while (1) {
        uart_puts("Hello World\r\n");
        _delay_ms(1000);
    }
}
