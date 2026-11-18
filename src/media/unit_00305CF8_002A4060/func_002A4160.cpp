/* compiler: ee-gcc2.96-stl */
#include <stl_tree.h>
typedef int s32;
typedef pair<const unsigned int, s32> Value;
typedef _Rb_tree_node<Value> Node;
typedef _Rb_tree_iterator<Value, const Value&, const Value*> It;
extern s32 D_0057C650;
extern "C" void hModule__findModuleValue(void *, void *, const void *);
extern "C" void func_002A4648(void *, const void *, const void *);
extern "C" It func_002A4970(const void *);
extern "C" It func_002A4980(const void *);
extern "C" void func_002BC0E0(void *, int);
extern "C" void func_002BC270(void *);
struct Handle { s32 p; Handle() { func_002BC270(this); } Handle(const Handle &); ~Handle() { func_002BC0E0(this, 2); } bool isNull() const { return p == 0; } };
extern "C" void func_002A4160(void *arg0, void **arg1, s32 *arg2) {
    if (*arg2 == D_0057C650) {
        const void *m = *arg1;
        for (It it = func_002A4970(m); it != func_002A4980(m); it++) {
            func_002A4648(arg0, &(*it).first, &(*it).second);
        }
        return;
    }
    Handle buf;
    hModule__findModuleValue(*arg1, &buf, arg2);
    if (!buf.isNull())
        func_002A4648(arg0, arg2, &buf);

}
