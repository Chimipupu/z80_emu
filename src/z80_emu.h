/**
 * @file z80_emu.h
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief Z80エミュレータ ヘッダー
 * @version 0.1
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#ifndef Z80_EMU_H
#define Z80_EMU_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "z80_cpu.h"

void z80_emu_init(void);
void z80_emu_main(void);

#endif /* Z80_EMU_H */