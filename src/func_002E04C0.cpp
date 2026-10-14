typedef float f32;
typedef int s32;

extern f32 D_00582AB8[];

extern "C" void func_002E04C0(f32 *arg0, f32 *arg1)
{
    f32 k0 = -D_00582AB8[0];
    f32 k1 = -D_00582AB8[1];
    f32 k2 = -D_00582AB8[2];

    f32 p = arg0[13];
    f32 q = arg0[14];
    f32 r = arg0[15];
    f32 s = arg0[16];

    ((s32 *)arg1)[3] = 0;
    ((s32 *)arg1)[7] = 0;
    ((s32 *)arg1)[11] = 0;

    f32 f11 = p * k0;
    f32 f9 = q * k1;
    f32 f14 = r * k2;
    f32 f0 = -((f11 + f9) + f14);

    arg1[0] = f0 + f11;
    arg1[1] = p * k1;
    arg1[2] = p * k2;
    arg1[4] = q * k0;
    arg1[5] = f0 + f9;
    arg1[6] = q * k2;
    arg1[8] = r * k0;
    arg1[9] = r * k1;
    arg1[10] = f0 + f14;
    arg1[12] = s * k0;
    arg1[13] = s * k1;
    arg1[14] = s * k2;
    arg1[15] = f0;
}
