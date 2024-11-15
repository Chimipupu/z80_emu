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

#include "z80_mem.h"

typedef struct {
    // レジスタペア(AF,BC,DE,HL)
    // 裏レジスタ(AF',BC',DE',HL')
    union {
        struct {
            uint8_t high;
            uint8_t low;
        };
        uint16_t word;
    } af, bc, de, hl, af_s, bc_s, de_s, hl_s;

    uint8_t i;   // 割り込みベクトル
    uint8_t r;   // メモリリフレッシュ(DRAM用)
    uint16_t ix; // インデックスレジスタIX
    uint16_t iy; // インデックスレジスタIY
    uint16_t pc; // プログラムカウンタ
    uint16_t sp; // スタックポインタ
} z80_reg_t;

typedef struct {
    z80_reg_t reg;
    union {
        struct {
            uint8_t high;
            uint8_t low;
        };
        uint16_t word;
    } instr;
    uint8_t cycle;
    uint8_t halt_flag;
    uint8_t rom[__MEM_ROM_SIZE__];
    uint8_t ram[__MEM_RAM_SIZE__];
} z80_t;

#ifndef FALSE
#define FALSE           0x00
#endif
#ifndef TRUE
#define TRUE            0x01
#endif

// Z80 フラグレジスタ ビットマスク
#define Z80_FLG_S       0b10000000  // Sign flag
#define Z80_FLG_Z       0b01000000  // Zero flag
#define Z80_FLG_Y       0b00100000  // Reserved
#define Z80_FLG_H       0b00010000  // Half carry flag
#define Z80_FLG_X       0b00001000  // Reserved
#define Z80_FLG_PV      0b00000100  // Parity/Overflow flag
#define Z80_FLG_N       0b00000010  // Add/Subtract flag
#define Z80_FLG_C       0b00000001  // Carry flag)

static inline uint8_t GET_FLAG(uint8_t *p_flg_reg, uint8_t flag_mask)
{
    return (*p_flg_reg & flag_mask) ? 1 : 0;
}

static inline void SET_FLAG(uint8_t *p_flg_reg, uint8_t flag_mask, uint8_t set_claer)
{
    if (set_claer != FALSE) {
        *p_flg_reg |= flag_mask;
    } else {
        *p_flg_reg &= ~flag_mask;
    }
}

void z80_cpu_init(void);
void z80_cpu_main(void);

#endif /* Z80_CPU_H */