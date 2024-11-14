/**
 * @file z80_cpu.h
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief Z80エミュレータ ヘッダー
 * @version 0.1
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#ifndef Z80_CPU_H
#define Z80_CPU_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    union {
        struct {
            uint8_t high;
            uint8_t low;
        };
        uint16_t word;
    } af, bc, de, hl, af_s, bc_s, de_s, hl_s;

    uint8_t i;
    uint8_t r;
    uint16_t ix;
    uint16_t iy;
    uint16_t pc;
    uint16_t sp;
} z80_reg_t;

void z80_cpu_init(void);
void z80_cpu_main(void);

#endif /* Z80_CPU_H */