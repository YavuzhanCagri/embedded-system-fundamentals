# 02 - Bit Status Testing & Volatile Qualifier

This module demonstrates how to inspect specific hardware flags (polling/bit testing) within status registers and explores the necessity of the `volatile` qualifier in embedded systems.

## Concepts Covered

* **Bit Testing / Polling (`CHECK_BIT`)**: Isolating and evaluating single-bit flags using bitwise AND masking (`(reg & (1U << n)) != 0`) without altering register state.
* **Hardware Status Flags**: Modeling real-world peripheral event flags such as Transmission Complete (`TX_COMPLETE`), Reception Ready (`RX_READY`), and Error states (`ERROR_FLAG`).
* **The `volatile` Qualifier**: Preventing compiler optimizations from caching memory-mapped register reads into CPU registers, ensuring direct physical access on every evaluation.
* **Flag Clearing (Acknowledgment)**: Safely deactivating handled event flags using bitwise clear operations to avoid redundant processing.

## Build and Run

### Option 1: Standalone GCC
Run from this folder (`02_bit_status_and_volatile`):

```bash
gcc -Wall -Wextra -std=c99 main.c -o bit_status_sim
./bit_status_sim
```
### Option 2: CMake (From project root)
```bash
cmake -B build
cmake --build build --target module_02
./build/module_02
```
### Expected Output
```text
=== Module 02: Bit Status Testing & Volatile Qualifier ===

Initial Status Register : 0x00
[OK] TX Complete bit is clear (not ready yet).

--> Hardware Event: Setting TX_COMPLETE bit (Bit 0)...
Updated Status Register : 0x01
[OK] Hardware flag detected: TX buffer is empty, ready for next byte.

--> Hardware Event: Incoming data received, setting RX_READY bit (Bit 1)...
Updated Status Register : 0x03
[DATA] New byte available in buffer. Reading and clearing flag...
Status Register after RX clear: 0x01

--> Hardware Event: Setting ERROR_FLAG bit (Bit 7)...
Updated Status Register : 0x81
[ALERT] Hardware error detected! Resetting error flag...
Status Register after clear: 0x01
```

