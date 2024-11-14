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

uint8_t g_rom[__Z80_MEM_ROM_SIZE__] = {0};
uint8_t g_ram[__Z80_MEM_RAM_SIZE__] = {0};

void z80_mem_init(void)
{
    memset(&g_rom[0], 0xFF, sizeof(g_rom));
    memset(&g_ram[0], 0xFF, sizeof(g_ram));
}