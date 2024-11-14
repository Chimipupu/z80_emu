/**
 * @file z80_mem.h
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief Z80メモリヘッダー
 * @version 0.1
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#ifndef Z80_MEM_H
#define Z80_MEM_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define __Z80_MEM_ROM_SIZE__    8192
#define __Z80_MEM_RAM_SIZE__    8192

void z80_mem_init(void);

#endif /* Z80_MEM_H */