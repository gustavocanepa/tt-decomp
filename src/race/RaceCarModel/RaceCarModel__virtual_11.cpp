/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Model { char pad[0x18]; int state; };
extern "C" void func_003431F0(Model *);
struct Pair { int a,b; char pad[0x18]; Pair(int x,int y) { a=x; b=y; } };
struct Callback { void (*fn)(Model *); Model *object; Callback(void (*f)(Model *),Model *o) { fn=f; object=o; } };
extern "C" int func_00388F10(void);
extern "C" void func_0042F140(int, const Pair *, const Callback *, int);
extern "C" void RaceCarModel__virtual_11(Model *self,int arg) {
    if (self->state == 0) {
        Pair pair(func_00388F10(),0);
        func_0042F140(arg, &pair, &Callback(func_003431F0,self),1);
    }
}
