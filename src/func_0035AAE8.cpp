struct Base{char pad[0x14];void*vt;Base() __asm__("func_0038E2B8");};struct S:Base{int a;unsigned b;int c,d;S() __asm__("func_0035AAE8");};extern char D_005D0D20[];
S::S(){vt=D_005D0D20;a=0;b=0x80e3b896u;c=0;d=0;}
