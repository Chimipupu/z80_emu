/**
 * @file z80_cpu.c
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief 
 * @version 0.1
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#include "z80_cpu.h"

z80_reg_t g_cpu_reg;

static void reg_init(void);
static void fetch_instr(void);
static void decode_instr(void);
static void exec_instr(void);
static void dbg_cpu_print(const z80_reg_t *p_reg);

static void dbg_cpu_print(const z80_reg_t *p_reg)
{
    printf("AF : 0x%04X (A: 0x%02X, F: 0x%02X)\n", p_reg->af.word, p_reg->af.high, p_reg->af.low);
    printf("BC : 0x%04X (B: 0x%02X, C: 0x%02X)\n", p_reg->bc.word, p_reg->bc.high, p_reg->bc.low);
    printf("DE : 0x%04X (D: 0x%02X, E: 0x%02X)\n", p_reg->de.word, p_reg->de.high, p_reg->de.low);
    printf("HL : 0x%04X (H: 0x%02X, L: 0x%02X)\n", p_reg->hl.word, p_reg->hl.high, p_reg->hl.low);

    printf("AF': 0x%04X (A': 0x%02X, F': 0x%02X)\n", p_reg->af_s.word, p_reg->af_s.high, p_reg->af_s.low);
    printf("BC': 0x%04X (B': 0x%02X, C': 0x%02X)\n", p_reg->bc_s.word, p_reg->bc_s.high, p_reg->bc_s.low);
    printf("DE': 0x%04X (D': 0x%02X, E': 0x%02X)\n", p_reg->de_s.word, p_reg->de_s.high, p_reg->de_s.low);
    printf("HL': 0x%04X (H': 0x%02X, L': 0x%02X)\n", p_reg->hl_s.word, p_reg->hl_s.high, p_reg->hl_s.low);

    printf("I : 0x%02X\n", p_reg->i);
    printf("R : 0x%02X\n", p_reg->r);

    printf("IX : 0x%04X\n", p_reg->ix);
    printf("IY : 0x%04X\n", p_reg->iy);

    printf("PC : 0x%04X\n", p_reg->pc);
    printf("SP : 0x%04X\n", p_reg->sp);
}

static void reg_init(void)
{
    // ぺアレジスタ(AF,BC,DE,HL)
    g_cpu_reg.af.word = 0x00;
    g_cpu_reg.bc.word = 0x00;
    g_cpu_reg.de.word = 0x00;
    g_cpu_reg.hl.word = 0x00;

    // 裏レジスタ(AF',BC',DE',HL')
    g_cpu_reg.af_s.word = 0x00;
    g_cpu_reg.bc_s.word = 0x00;
    g_cpu_reg.de_s.word = 0x00;
    g_cpu_reg.hl_s.word = 0x00;

    // インデックスレジスタ(IX,IY)
    g_cpu_reg.ix = 0x00;
    g_cpu_reg.iy = 0x00;

    // I,R
    g_cpu_reg.i = 0x00;
    g_cpu_reg.r = 0x00;

    // PC,SP
    g_cpu_reg.pc = 0x00;
    g_cpu_reg.sp = 0xFF;
}

static void fetch_instr(void)
{
    // TODO:
}

static void decode_instr(void)
{
    // TODO:
}

static void exec_instr(void)
{
    // TODO:
}

void z80_cpu_init(void)
{
    // TODO:
    z80_mem_init();
}

void z80_cpu_main(void)
{
    fetch_instr();
    decode_instr();
    exec_instr();
    dbg_cpu_print(&g_cpu_reg);
}