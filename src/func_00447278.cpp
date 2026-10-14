struct Info { char pad[0xA]; unsigned short flag; };
struct Inner { char pad[4]; Info *info; char pad2[0x48]; int limit; };
struct Node { Node *next; int pad; Inner *data; };
struct Iter { Node *cur; Node *end; };
extern "C" void func_0043B268(void *);
extern "C" void func_0043B320(void *);
extern "C" void func_0043B388(void *);
extern "C" void func_00444378(Inner *, void *);

extern "C" Node *func_00447278(void *a0, void *a1, int a2, Node *cur, Node *end) {
    Iter it;
    it.cur = cur;
    it.end = end;
    Node **pe = &it.end;
    while (it.cur != *pe) {
        if (a2 < it.cur->data->limit) return it.cur;
        unsigned short f = it.cur->data->info->flag;
        if (f) func_0043B268(a1);
        func_00444378(it.cur->data, a1);
        if (f) {
            func_0043B320(a1);
            Node *nx = it.cur->next;
            it.cur = nx;
            it.cur = func_00447278(a0, a1, f, nx, it.end);
            func_0043B388(a1);
        } else {
            it.cur = it.cur->next;
        }
    }
    return it.end;
}
