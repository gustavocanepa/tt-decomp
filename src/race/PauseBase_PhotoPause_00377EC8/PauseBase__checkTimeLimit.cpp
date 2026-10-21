struct Obj { int count, limit; };
extern "C" int PauseBase__checkTimeLimit(Obj *self) {
    if (self->limit != 0 && ++self->count > self->limit) return 1;
    return 0;
}
