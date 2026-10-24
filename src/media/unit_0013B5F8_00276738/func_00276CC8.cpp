/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_002774B0(void *, void *, float *, float *);
extern "C" void func_00205DF0(void *, float, float);
struct Obj { char pad[0xF0]; void *child; };
extern "C" void func_00276CC8(Obj *self, void *component) {
    float position[2];
    if (component) {
        func_002774B0(self, component, &position[0], &position[1]);
        func_00205DF0(self->child, position[0], position[1]);
    }
}
