/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ctx { char p0[0x38]; char *a38; char p1[4]; char *a40; char p2[0x74]; char *aB8; };
struct Node { short type,p2,p4,idx; };
struct Obj { Ctx *ctx; Node *node; };
extern "C" int func_00445798(char *, int);
extern "C" int func_00446010(char *, int);
extern "C" int func_004467C0(char *, int);
extern "C" int func_00444588(Obj *o, int x) {
 switch(o->node->type) {
 case 0: return func_00445798(o->ctx->a38+o->node->idx*24,x);
 case 1: return func_00446010(o->ctx->a40+o->node->idx*40,x);
 case 7: return func_004467C0(o->ctx->aB8+o->node->idx*24,x);
 default: return 0;
 }
}
