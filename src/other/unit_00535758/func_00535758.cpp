typedef float f32;

extern "C" f32 func_005357F8();

extern "C" f32 func_00535758(f32 fparg0, f32 fparg1) {
    return ((fparg1 - fparg0) * func_005357F8()) + fparg0;
}
