#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint32_t reg = 0;
    printf("Register Address: %p\n", (void*)&reg);

    uint32_t *ptr = &reg;

    // Set bit 0 (e.g., Power On)
    *ptr |= (1U << 0);
    printf("After setting bit 0:  0x%08X\n", reg);

    // Set bit 4 (e.g., Error Flag)
    *ptr |= (1U << 4);
    printf("After setting bit 4:  0x%08X\n", reg);

    // Clear bit 0 (e.g., Power Off)
    *ptr &= ~(1U << 0);
    printf("After clearing bit 0: 0x%08X\n", reg);

    return 0;
}