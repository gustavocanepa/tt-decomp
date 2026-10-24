/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Callback { int *(*fn)(int *, int, int, int, void *); int context; };
extern "C" void func_00447D00(void *, int) throw();
extern "C" int *func_00447EF0(int *ret, Callback *cb, int a, int b, void *obj) {
 if (cb->fn) cb->fn(ret, cb->context, a, b, obj);
 else { func_00447D00(obj,b); *ret=1; }
 return ret;
}
