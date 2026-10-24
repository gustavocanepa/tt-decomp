#include "types.h"
struct Node { Node *next; char pad[4]; };
struct Obj { char p0[8]; Node *head; };
extern "C" void func_002E0C60(void);
extern "C" s32 RigidBody__Update(Node *n, float f);
extern "C" void RigidBodyManager__remove(Obj *self, Node *cur, Node *prev);
extern "C" void RigidBodyManager__Update(Obj *self, float f) {
    Node *prev = 0;
    func_002E0C60();
    Node *cur = self->head;
    while (cur != 0) {
        Node *next = cur->next;
        if (RigidBody__Update(cur, f) == 0) {
            RigidBodyManager__remove(self, cur, prev);
        } else {
            prev = cur;
        }
        cur = next;
    }
}
