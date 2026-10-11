typedef float f32;
f32 *func_003E5C78(f32 *a, f32 b);
f32 *func_003E5E38(f32 *arg0, f32 *arg1) {
    f32 pad[4];
    f32 tmp[4];
    *arg0 = *func_003E5C78(tmp, *arg1);
    return arg0;
}
