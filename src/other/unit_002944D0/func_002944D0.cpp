/* push_back of a handle into the vector at +0x10 of an object (vector<Handle>::push_back inlined:
   copy-construct at finish, or _M_insert_aux func_00544468 when full), returning a copy of it. */
typedef int s32;

struct Handle {
    s32 p;
};

struct HandleVector {
    s32 pad;
    Handle *start;
    Handle *finish;
    Handle *end_of_storage;
};

struct Obj {
    char pad0[0x10];
    HandleVector vec;
};

extern "C" void func_002A7590(Handle *dst, Handle *src);
extern "C" void func_00544468(HandleVector *v, Handle *pos, Handle *x);

extern "C" Handle *func_002944D0(Handle *ret, Obj *self, Handle *x)
{
    HandleVector *v = &self->vec;
    if (v->finish != v->end_of_storage) {
        if (v->finish)
            func_002A7590(v->finish, x);
        v->finish++;
    } else {
        func_00544468(v, v->finish, x);
    }
    func_002A7590(ret, x);
    return ret;
}
