/**
 * @file z80_emu.c
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief Z80エミュレータ 実装
 * @version 0.1
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#include "z80_emu.h"

void z80_emu_init(void)
{
    z80_cpu_init();
}

void z80_emu_main(void)
{
    // while (1)
    {
        z80_cpu_main();
    }
}

int main(int argc, char **argv)
{
    z80_emu_init();
    printf("Z80 Emu by Chimi(https://github.com/Chimipupu)\n");
    z80_emu_main();

    return 0;
}