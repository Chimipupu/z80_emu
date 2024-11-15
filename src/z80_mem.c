/**
 * @file z80_mem.c
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief Z80メモリ 実装
 * @version 0.1
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#include "z80_mem.h"

void z80_mem_init(uint8_t *p_rom, uint8_t *p_ram)
{
    memset(p_rom, 0xFF, __MEM_ROM_SIZE__);
    memset(p_ram, 0xFF, __MEM_RAM_SIZE__);
}