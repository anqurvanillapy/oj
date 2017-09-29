#include <stdio.h>
#include <unistd.h>
#include <setjmp.h>
#include <ucontext.h>

void
think()
{
    printf("thinking w/o eating...\n");
    sleep(1);
}

void
infini_while()
{
    while (1) think();
}

void
infini_do_while()
{
    do { think(); } while (1);
}

void
infini_for()
{
    for (;;) think();
}

void
infini_label()
{
loop:
    think();
    goto loop;
}

void
infini_setjmp()
{
    static jmp_buf buf;
    setjmp(buf);
    think();
    longjmp(buf, 0);
}

void
infini_ucontext()
{
    ucontext_t ctx;
    getcontext(&ctx);
    think();
    setcontext(&ctx);
}

int
main()
{
    // infini_while();
    // infini_do_while();
    // infini_for();
    // infini_label();
    // infini_setjmp();
    infini_ucontext();
    return 0;
}
