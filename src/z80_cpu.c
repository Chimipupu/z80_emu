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

#include "z80_instr.h"
#include "z80_mem.h"
#include "z80_cpu.h"

extern uint8_t g_rom[__Z80_MEM_ROM_SIZE__];
extern uint8_t g_ram[__Z80_MEM_RAM_SIZE__];
z80_t g_z80;

static void reg_init(void);
static uint8_t fetch_instr(void);
static void decode_instr(uint8_t intsr);
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
    g_z80.reg.af.word = 0x00;
    g_z80.reg.bc.word = 0x00;
    g_z80.reg.de.word = 0x00;
    g_z80.reg.hl.word = 0x00;

    // 裏レジスタ(AF',BC',DE',HL')
    g_z80.reg.af_s.word = 0x00;
    g_z80.reg.bc_s.word = 0x00;
    g_z80.reg.de_s.word = 0x00;
    g_z80.reg.hl_s.word = 0x00;

    // インデックスレジスタ(IX,IY)
    g_z80.reg.ix = 0x00;
    g_z80.reg.iy = 0x00;

    // I,R
    g_z80.reg.i = 0x00;
    g_z80.reg.r = 0x00;

    // PC,SP
    g_z80.reg.pc = 0x00;
    g_z80.reg.sp = 0xFF;

    // ROM, RAM
    g_z80.p_rom = &g_rom[0];
    g_z80.p_ram = &g_ram[0];

}

static uint8_t fetch_instr(void)
{
    uint8_t intsr = *g_z80.p_rom;
    g_z80.p_rom++;
    g_z80.pri_fetch = *g_z80.p_rom;
    g_z80.p_rom++;

    return intsr;
}

static void decode_instr(uint8_t intsr)
{
    z80_intr_decode(g_z80, intsr);
}

static void exec_instr(void)
{
    z80_intr_exec(g_z80);
}

void z80_cpu_init(void)
{
    reg_init();
    z80_mem_init();
}

void z80_cpu_main(void)
{
    uint8_t instr = fetch_instr();
    decode_instr(instr);
    exec_instr();
    dbg_cpu_print(&g_z80.reg);
}