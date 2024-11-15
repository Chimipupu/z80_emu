/**
 * @file z80_instr.c
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief Z80命令セット 実装
 * @version 0.1
 * @date 2024-11-15
 * 
 * @copyright Copyright (c) 2024　ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#include "z80_instr.h"

static void nop(void);
static void halt(z80_t z80);
static void ind(z80_t z80);
static void indr(z80_t z80);
static void ini(z80_t z80);
static void inir(z80_t z80);

// NOP(なにもしない, 1サイクル)
static void nop(void)
{
    asm volatile ("nop");
}

// HALT (CPU停止, 4サイクル)
static void halt(z80_t z80)
{
    z80.halt_flag = TRUE;
    z80.cycle = 16;
}

// IND (イン・デクリメント, 16サイクル)
static void ind(z80_t z80)
{
    // TODO:(HL) ← (C) ... CレジスタのアドレスのI/Oポートの値をHLに
    z80.reg.bc.high--; // B ← B - 1
    z80.reg.hl.word--; // HL ← HL - 1
    z80.cycle = 16;
}

// INDR(B=0までINDR, 21サイクル※最終は16サイクル)
static void indr(z80_t z80)
{
    while (z80.reg.bc.high > 0)
    {
        ind(z80);
    }
}

// IND (イン・インクリメント, 16サイクル)
static void ini(z80_t z80)
{
    // TODO:(HL) ← (C) ... CレジスタのアドレスのI/Oポートの値をHLに
    z80.reg.bc.high--; // B ← B - 1
    z80.reg.hl.word++; // HL ← HL + 1
    z80.cycle = 16;
}

static void inir(z80_t z80)
{
    while (z80.reg.bc.high > 0)
    {
        indr(z80);
    }
}

void z80_decode_exec(z80_t z80, uint8_t instr)
{
    z80.instr.high = instr;

    switch (z80.instr.word)
    {
        case OPCODE_HALT:
            halt(z80);
            break;

        case OPCODE_IND:
            ind(z80);
            break;

        case OPCODE_INDR:
            indr(z80);
            break;

        case OPCODE_INI:
            ini(z80);
            break;

        case OPCODE_INIR:
            inir(z80);
            break;

        case OPCODE_NOP:
        default:
            nop();
            break;
    }
}