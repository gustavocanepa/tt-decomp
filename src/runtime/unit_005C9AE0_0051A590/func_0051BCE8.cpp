struct Obj { char pad[16]; char *p; };

extern "C" void func_0051BCE8(Obj *o, const void *source) {
    __builtin_memcpy(o->p + 0x1460, source, 0x258);
}
