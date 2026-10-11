struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };

struct Shape { int handle; };
struct Node { int pad; Shape *shape; int pad8[2]; };
struct Part { int pad; unsigned short node; char pad6[0x3A]; };
struct Model { char pad[0x1C]; Part *parts; int pad20; Node *nodes; };
struct Body { char pad[0xCC]; Model *model; };
struct Inner { int pad; Body *body; };
struct Car { Inner *inner; };

extern "C" void func_00378768(int handle, Vec2 *out);
extern "C" void func_003AA3E8(Vec3 *out, Inner *inner, const Vec3 *v, int i);

extern "C" float func_00318F30(Car *c, int i) {
    Vec3 r;
    Vec3 w;
    Vec3 *pw = &w;
    Vec2 v;
    Model *m = c->inner->body->model;
    Part *p = &m->parts[i];
    Node *n = &m->nodes[p->node];
    func_00378768(n->shape->handle, &v);
    pw->x = v.x;
    pw->y = 0.0f;
    pw->z = v.y;
    func_003AA3E8(&r, c->inner, pw, i);
    return r.x;
}
