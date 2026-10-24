struct S { union { int bits; float f; } a; float v[2]; S() __asm__("func_003CEF08"); }; S::S() { a.bits=0; float *p=v; float f=a.f; p[0]=f; p[1]=f; }
