struct Req {
    void *buf;
    int size;
    int done;
    int pad;
    long long flags;
    short unit;
    char mode;
    char busy;
    int retries;
    int error;
};

extern "C" void func_00576AF8(Req *r, void *buf, int size)
{
    if (buf == 0)
        r->mode = 4;
    else
        r->mode = 0;
    r->buf = buf;
    r->size = size;
    r->unit = 0x20;
    r->flags = 0x11;
    r->retries = 6;
    r->busy = 0;
    r->done = 0;
    r->error = 0;
}
