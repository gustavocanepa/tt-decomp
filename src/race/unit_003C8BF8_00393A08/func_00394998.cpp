struct S { char p[0x540]; void *aligned; char q[0x540]; int a,b; S() __asm__("func_00394998"); }; S::S() { aligned=(void *)(((unsigned int)this+15)&~15U); a=0; b=0; }
