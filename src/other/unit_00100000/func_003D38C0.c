typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;
typedef float f32; typedef double f64;
typedef int s128 __attribute__((mode(TI))); typedef unsigned int u128 __attribute__((mode(TI)));
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
/*
 * This header contains macros emitted by m2c in "valid syntax" mode,
 * which can be enabled by passing `--valid-syntax` on the command line.
 *
 * In this mode, unhandled types and expressions are emitted as macros so
 * that the output is compilable without human intervention.
 */

#ifndef M2C_MACROS_H
#define M2C_MACROS_H

/* Unknown types */
typedef s32 M2C_UNK;
typedef s8  M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;

/* Unknown field access, like `*(type_ptr) &expr->unk_offset` */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

/* Bitwise (reinterpret) cast */
#define M2C_BITWISE(type, expr) ((type)(expr))

/* Unaligned reads */
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)

/* Unhandled instructions */
#define M2C_ERROR(desc) (0)
#define M2C_TRAP_IF(cond) (0)
#define M2C_BREAK() (0)
#define M2C_SYNC() (0)
#define M2C_DCACHE_CLEAN(addr) (0)
#define M2C_DCACHE_INVALIDATE(addr) (0)
#define M2C_DCACHE_CLEAN_INVALIDATE(addr) (0)
#define M2C_DCACHE_BLOCK_SETZERO(addr) (0)
#define M2C_DCACHE_BLOCK_SETZERO_LOCKED(addr) (0)
#define M2C_ICACHE_INVALIDATE(addr) (0)
#define M2C_PREFETCH(addr) (0)
#define M2C_PREFETCH_STORE(addr) (0)

#define GLUE_F64(a, b) (0.0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define DMULT_HI(a, b) (0)
#define DMULTU_HI(a, b) (0)
#define CLZ(x) (0)
#define REVERSE_BITS(x) (0)
#define ROTATE_RIGHT(x, shift) (0)
#define ARM_RRX(x, carry) (0)
#define BSWAP32(x) (0)
#define BSWAP16(x) (0)
#define BSWAP16X2(x) (0)

/* Carry/overflow bits from partially-implemented instructions */
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)

/* Memcpy patterns */
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724

/* Sh2 control register loads/stores */
#define M2C_LOAD_SR() (0)
#define M2C_LOAD_GBR() (0)
#define M2C_LOAD_VBR() (0)
#define M2C_STORE_SR(a)
#define M2C_STORE_GBR(a)
#define M2C_STORE_VBR(a)

#define M2C_CMP_STR(a, b) (0)
#define M2C_TAS_B(a) (0)

#endif

s32 func_003BD100(s32);                             /* extern */
s32 func_003BD110(s32);                             /* extern */
s32 func_003BD120(s32);                             /* extern */
s32 func_003BD130(s32);                             /* extern */
s32 func_003BD140(s32);                             /* extern */
s32 func_003BD150(s32);                             /* extern */
s32 func_003BD1E0(s32);                             /* extern */
s32 func_003BD1F0(s32);                             /* extern */
s32 func_003BD200(s32);                             /* extern */
s32 func_003BD210(s32);                             /* extern */
s32 func_003BD408(s32);                             /* extern */
s32 func_003BD410(s32);                             /* extern */
M2C_UNK func_003BD558(s32 *, M2C_UNK, s32);         /* extern */
s32 func_003BD900(s32);                             /* extern */
s32 func_003BD910(s32);                             /* extern */
s32 func_003BD940(s32);                             /* extern */
s32 func_003BD950(s32);                             /* extern */
M2C_UNK func_003D25D8(M2C_UNK, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32 *, s32 *); /* extern */

void func_003D38C0(void *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    s32 sp50;
    s32 sp54;
    s32 sp58;
    s32 sp5C;
    s32 sp60;
    s32 sp64;
    s32 sp68;
    s32 sp6C;
    s32 sp70;
    s32 sp74;
    s32 sp78;
    s32 sp7C;
    s32 sp80;
    f32 temp_f20;
    f32 temp_f20_2;
    s32 temp_fp;
    s32 temp_fp_2;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 temp_s3;
    s32 temp_s3_2;
    s32 temp_s4;
    s32 temp_s4_2;
    s32 temp_s5;
    s32 temp_s5_2;
    s32 temp_s6;
    s32 temp_s6_2;
    s32 temp_s7;
    s32 temp_s7_2;

    sp58 = arg1;
    sp50 = func_003BD408(*M2C_FIELD(arg0, s32 **, 0x12C));
    sp54 = func_003BD410(*M2C_FIELD(arg0, s32 **, 0x12C));
    temp_f20 = M2C_FIELD(arg0, f32 *, 0x100);
    sp5C = func_003BD100(M2C_FIELD(arg0, s32 *, 0x120));
    sp60 = func_003BD120(M2C_FIELD(arg0, s32 *, 0x120));
    sp64 = func_003BD140(M2C_FIELD(arg0, s32 *, 0x120));
    sp68 = func_003BD900(M2C_FIELD(arg0, s32 *, 0x128));
    temp_s7 = func_003BD1E0(M2C_FIELD(arg0, s32 *, 0x120));
    temp_s5 = func_003BD200(M2C_FIELD(arg0, s32 *, 0x120));
    sp6C = func_003BD940(M2C_FIELD(arg0, s32 *, 0x128));
    temp_fp = func_003BD110(M2C_FIELD(arg0, s32 *, 0x120));
    temp_s6 = func_003BD130(M2C_FIELD(arg0, s32 *, 0x120));
    temp_s4 = func_003BD150(M2C_FIELD(arg0, s32 *, 0x120));
    temp_s3 = func_003BD910(M2C_FIELD(arg0, s32 *, 0x128));
    temp_s2 = func_003BD1F0(M2C_FIELD(arg0, s32 *, 0x120));
    temp_s1 = func_003BD210(M2C_FIELD(arg0, s32 *, 0x120));
    func_003D25D8(0, fparg0, fparg1, temp_f20, fparg2, arg1, sp5C, sp60, sp64, sp68, temp_s7, temp_s5, sp6C, temp_fp, temp_s6, temp_s4, temp_s3, temp_s2, temp_s1, func_003BD950(M2C_FIELD(arg0, s32 *, 0x128)), &sp50, &sp54);
    temp_f20_2 = M2C_FIELD(arg0, f32 *, 0x100);
    sp70 = func_003BD110(M2C_FIELD(arg0, s32 *, 0x120));
    sp74 = func_003BD130(M2C_FIELD(arg0, s32 *, 0x120));
    sp78 = func_003BD150(M2C_FIELD(arg0, s32 *, 0x120));
    sp7C = func_003BD910(M2C_FIELD(arg0, s32 *, 0x128));
    sp80 = func_003BD1F0(M2C_FIELD(arg0, s32 *, 0x120));
    temp_fp_2 = func_003BD210(M2C_FIELD(arg0, s32 *, 0x120));
    temp_s7_2 = func_003BD950(M2C_FIELD(arg0, s32 *, 0x128));
    temp_s6_2 = func_003BD100(M2C_FIELD(arg0, s32 *, 0x120));
    temp_s5_2 = func_003BD120(M2C_FIELD(arg0, s32 *, 0x120));
    temp_s4_2 = func_003BD140(M2C_FIELD(arg0, s32 *, 0x120));
    temp_s3_2 = func_003BD900(M2C_FIELD(arg0, s32 *, 0x128));
    temp_s2_2 = func_003BD1E0(M2C_FIELD(arg0, s32 *, 0x120));
    temp_s1_2 = func_003BD200(M2C_FIELD(arg0, s32 *, 0x120));
    func_003D25D8(1, fparg0, fparg1, temp_f20_2, fparg2, sp58, sp70, sp74, sp78, sp7C, sp80, temp_fp_2, temp_s7_2, temp_s6_2, temp_s5_2, temp_s4_2, temp_s3_2, temp_s2_2, temp_s1_2, func_003BD940(M2C_FIELD(arg0, s32 *, 0x128)), &sp54, &sp50);
    func_003BD558(M2C_FIELD(arg0, s32 **, 0x12C), 0, sp50);
    func_003BD558(M2C_FIELD(arg0, s32 **, 0x12C), 1, sp54);
}
