typedef float f32;
f32 *func_003E5E18(f32 *a, f32 b);
f32 *func_003E5C98(f32 *arg0, f32 *arg1) {
    f32 pad[4];
    f32 tmp[4];
    *arg0 = *func_003E5E18(tmp, *arg1);
    return arg0;
}
