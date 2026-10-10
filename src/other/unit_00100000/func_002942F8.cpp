/* insert of a handle at the front of the vector at +0x10 of an object (vector<Handle>::insert(begin(), x)
   inlined: copy-construct at finish when there is room and the vector is empty, else _M_insert_aux
   func_00544468), returning a copy of it. The finish pointer is bumped through an integer lvalue: the
   original reloads it after the null test of the placement new, which needs the increment's load in a
   different alias set from the compare's (with one type, gcse reuses the compare's load on that path). */
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

extern "C" Handle *func_002942F8(Handle *ret, Obj *self, Handle *x)
{
    HandleVector *v = &self->vec;
    Handle *pos = v->start;
    if (v->finish != v->end_of_storage && pos == v->finish) {
        if (v->finish)
            func_002A7590(v->finish, x);
        *(s32 *)&v->finish += sizeof(Handle);
    } else {
        func_00544468(v, pos, x);
    }
    func_002A7590(ret, x);
    return ret;
}
