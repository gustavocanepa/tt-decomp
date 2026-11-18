/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x60]; char *data; };
extern "C" void func_002E8590(void *, int *) throw();
extern "C" void func_002E8EE0(Obj *self, int *out) {
    __builtin_memcpy((char *)out + *out, self->data, 0x4994);
    *out += 0x4994;
    func_002E8590((char *)self + 8, out);
}
