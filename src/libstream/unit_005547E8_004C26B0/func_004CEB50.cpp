/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Deactivates one sound object: when the 0x60 active flag is set, it tells the
   pool via func_004C1968 using the handle at 0x5C (that call also receives the
   argument struct itself), reports the self handle at 0x5C through
   func_004F41F0, then clears the 0x60 flag. Passing the pointer twice is what
   makes the original keep a copy of the incoming argument. */
struct Arg { char pad[0x58]; int other; int handle; };
struct Obj { char pad[0x5C]; int handle; int active; };
extern "C" void func_004C1968(int, Arg *);
extern "C" void func_004F41F0(int);
extern "C" void func_004CEB50(Obj *self, Arg *a) {
    if (self->active != 0) {
        func_004C1968(a->handle, a);
        func_004F41F0(self->handle);
        self->active = 0;
    }
}
