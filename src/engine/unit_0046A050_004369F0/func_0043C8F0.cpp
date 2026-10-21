typedef int s32;
typedef float f32;

struct Blk8 { s32 a; s32 b; };
struct P2 { s32 a; s32 b; };
struct Obj {
    s32 p0;
    char p4[8];
    void *pC;
    char p10[0xC];
    f32 p1C;
    char p20[0x194 - 0x20];
    struct Blk8 p194;
};
struct S;
struct Node { char p0[0xE8]; s32 pE8; };

extern "C" void func_0043AF18(void *, struct S *);
extern "C" void func_0043FE80(void *, struct S *, void *, s32, struct Obj *, f32);
extern "C" void func_00444378(s32, void *);
extern "C" void func_00568098(void *, void *, void *, void *);
extern "C" void func_00568140(void *, struct Node *);

extern "C" void func_0043C8F0(struct Obj *arg0, struct S *arg1, s32 arg2)
{
    char frame[0x6EC0];

    if (arg0->p0 != 0) {
        func_0043AF18(arg0->pC, arg1);
        func_0043FE80(frame, arg1, arg0->pC, arg2, arg0, arg0->p1C);
        *(struct Blk8 *)(frame + 0x6E90) = arg0->p194;
        *(struct Blk8 *)(frame + 0x6E80) = *(struct Blk8 *)(frame + 0x6E90);
        func_00444378(arg0->p0, frame);
        struct Node *n = *(struct Node **)(frame + 0x6E0C);
        ((struct P2 *)(frame + 0x6EA0))->b = n->pE8;
        ((struct P2 *)(frame + 0x6EB0))->b = (s32)n;
        func_00568098(frame + 0x6E90, frame + 0x5008, frame + 0x6EA0, frame + 0x6EB0);
        func_00568140(frame + 0x5008, *(struct Node **)(frame + 0x6E0C));
    }
}
