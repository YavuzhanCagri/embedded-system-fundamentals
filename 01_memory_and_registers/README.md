# 01 - Memory Inspection & Register Bit Manipulation

This module demonstrates direct memory inspection and hardware register simulation using pointers and bitwise operations in C.

## Concepts Covered
- **Stack Memory Inspection:** Observing physical memory addresses with `&` and `%p`.
- **Direct Register Access:** Reading and writing simulated control registers via pointers (`*ptr`).
- **Bit Setting:** Activating flags without overwriting existing data using `*ptr |= (1U << n)`.
- **Bit Clearing:** Deactivating target flags using mask inversion and bitwise AND via `*ptr &= ~(1U << n)`.

## Build and Run
```bash
gcc -Wall -Wextra -std=c99 main.c -o register_sim
./register_sim

Expected Output

Register Address: 0x16f57b01c
After setting bit 0:  0x00000001
After setting bit 4:  0x00000011
After clearing bit 0: 0x00000010