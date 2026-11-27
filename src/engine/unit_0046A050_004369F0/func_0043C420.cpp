#include "types.h"

struct Str;
struct Param;

struct Node {
    char pad0[0x8C];
    Node *next;
};

struct Obj {
    char pad0[0x24];
    Node *head;
};

extern "C" void func_0043C4C0(Obj *self, Param *p);
extern "C" Str *func_00444A30(Node *n);
extern "C" u32 func_004A8368(const char *s);
extern "C" s32 func_005507D8(Str *self, const char *s, u32 pos, u32 n);

extern "C" void func_0043C420(Obj *self, const char *s)
{
    Node *head = self->head;
    if (head != 0) {
        Node *cur = head;
        if (s != 0) {
            while (cur != 0) {
                Str *t = func_00444A30(cur);
                u32 n = func_004A8368(s);
                if (func_005507D8(t, s, 0, n) == 0) {
                    head = cur;
                    break;
                }
                cur = cur->next;
            }
        }
        func_0043C4C0(self, (Param *)head);
    }
}
