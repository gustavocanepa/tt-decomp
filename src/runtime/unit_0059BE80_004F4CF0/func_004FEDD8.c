/* compiler: ee-gcc2.9-991111 */
extern int func_004FE530(void *, int, int, void *, int, void *, int,
                       void (*)(void *), void *);
extern int func_004FB898(int);

/* Retry failed RPC submissions with a capped exponential delay. The return
 * value reports failure, rather than returning the RPC routine's error code. */
unsigned int func_004FEDD8(void *client, int command, int mode,
    void *send, int send_size, void *receive, int receive_size,
    void (*callback)(void *), void *callback_argument, int no_retry)
{
    int attempt = 0;
    int delay_scale = 1;
    unsigned int failed;
    do {
        failed = func_004FE530(client, command, mode, send,
            send_size, receive, receive_size, callback, callback_argument) < 0;
        if (!failed || no_retry)
            break;
        func_004FB898(delay_scale * 1000);
        if (delay_scale < 127)
            delay_scale *= 2;
        ++attempt;
    } while (attempt < 101);
    return failed;
}
