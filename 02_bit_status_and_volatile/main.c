#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* Bit manipulation macros */
#define BIT(x)              (1U << (x))
#define SET_BIT(reg, bit)   ((reg) |= BIT(bit))
#define CLEAR_BIT(reg, bit) ((reg) &= ~BIT(bit))
#define CHECK_BIT(reg, bit) (((reg) & BIT(bit)) != 0)

/* Simulated Hardware Status Register Flags */
#define STATUS_TX_COMPLETE_BIT  (0U) /* Bit 0: Transmission complete */
#define STATUS_RX_READY_BIT     (1U) /* Bit 1: Data received and ready */
#define STATUS_ERROR_FLAG_BIT   (7U) /* Bit 7: Hardware error encountered */

int main(void) {
    /*
     * Simulated Memory-Mapped Status Register.
     * Declared as 'volatile' to prevent compiler from caching read operations.
     */
    volatile uint8_t status_register = 0x00;

    printf("=== Module 02: Bit Status Testing & Volatile Qualifier ===\n\n");
    printf("Initial Status Register : 0x%02X\n", status_register);

    /* 1. Bit Status Check on Initial Value */
    if (CHECK_BIT(status_register, STATUS_TX_COMPLETE_BIT)) {
        printf("[FAIL] TX was reported complete prematurely!\n");
    } else {
        printf("[OK] TX Complete bit is clear (not ready yet).\n");
    }

    /* 2. Simulating Hardware Event: TX transmission completes */
    printf("\n--> Hardware Event: Setting TX_COMPLETE bit (Bit 0)...\n");
    SET_BIT(status_register, STATUS_TX_COMPLETE_BIT);
    printf("Updated Status Register : 0x%02X\n", status_register);

    /* 3. Re-evaluating Status */
    if (CHECK_BIT(status_register, STATUS_TX_COMPLETE_BIT)) {
        printf("[OK] Hardware flag detected: TX buffer is empty, ready for next byte.\n");
    }

    /* 4. Simulating Incoming Data (RX Ready) */
    printf("\n--> Hardware Event: Incoming data received, setting RX_READY bit (Bit 1)...\n");
    SET_BIT(status_register, STATUS_RX_READY_BIT);
    printf("Updated Status Register : 0x%02X\n", status_register);

    if (CHECK_BIT(status_register, STATUS_RX_READY_BIT)) {
        printf("[DATA] New byte available in buffer. Reading and clearing flag...\n");
        CLEAR_BIT(status_register, STATUS_RX_READY_BIT);
        printf("Status Register after RX clear: 0x%02X\n", status_register);
    }

    /* 5. Simulating an Error Flag and Resetting It */
    printf("\n--> Hardware Event: Setting ERROR_FLAG bit (Bit 7)...\n");
    SET_BIT(status_register, STATUS_ERROR_FLAG_BIT);
    printf("Updated Status Register : 0x%02X\n", status_register);

    if (CHECK_BIT(status_register, STATUS_ERROR_FLAG_BIT)) {
        printf("[ALERT] Hardware error detected! Resetting error flag...\n");
        CLEAR_BIT(status_register, STATUS_ERROR_FLAG_BIT);
        printf("Status Register after clear: 0x%02X\n", status_register);
    }

    return 0;
}