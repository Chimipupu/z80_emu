/**
 * @file z80_instr.h
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief Z80命令セット ヘッダー
 * @version 0.1
 * @date 2024-11-15
 * 
 * @copyright Copyright (c) 2024　ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#ifndef Z80_INSTR_H
#define Z80_INSTR_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "z80_cpu.h"

#define OPCODE_NOP     0x0000  // NOP
#define OPCODE_HALT    0x7600  // HALT
#define OPCODE_IND     0xEDAA  // IND
#define OPCODE_INDR    0xEDBA  // INDR
#define OPCODE_INI     0xEDA2  // INI
#define OPCODE_INIR    0xEDB2  // INIR

void z80_intr_decode(z80_t z80, uint8_t instr);
void z80_intr_exec(z80_t z80);

#endif /* Z80_INSTR_H */