/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob { long v[24]; };
struct Node { Blob data; char pad[12]; Node *next; };
extern "C" {
void func_004A4D68(void *);
void func_004A4DD8(void *);
Node *func_004C1EB0(char *);
void func_004AEB30(void *);
void *memcpy(void *, const void *, unsigned int);
}
static inline void copy(Blob *dst, const Blob *src) { __builtin_memcpy(dst, src, sizeof(Blob)); }
extern "C" void func_004C1C78(char *self, Blob *src) {
    void *lock = self + 0x2200;
    func_004A4D68(lock);
    Node *node = func_004C1EB0(self);
    if (node) {
        copy(&node->data, src);
        ++*(int *)(self + 0x68);
        node->next = 0;
        **(Node ***)(self + 0xE0) = node;
        *(Node ***)(self + 0xE0) = &node->next;
        func_004AEB30(self + 0x2230);
    }
    func_004A4DD8(lock);
}
