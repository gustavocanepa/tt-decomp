#include "types.h"

/* The base class; its constructor is func_0034F1D0 (named after it so __13func_0039A480
   resolves). The vptr sits after its 0x1C bytes of data. */
struct func_0034F1D0 {
    char pad[0x1C];
    func_0034F1D0();
    virtual ~func_0034F1D0();
};

/* A real C++ constructor: the compiler's own vptr store (_vt$21DirectivityMicrophone =
   D_0067E248) after the member initialisers gives the original's epilogue
   order (ld $s0 before ld $ra); the same stores written by hand in C hoist ld $ra. */
struct DirectivityMicrophone : func_0034F1D0 {
    s32 m20;
    f32 m24;
    DirectivityMicrophone();
    virtual ~DirectivityMicrophone();
};

DirectivityMicrophone::DirectivityMicrophone() : m20(0), m24(0x1.000000p+0f) {
}
