#ifndef SIGNAL_H
#define SIGNAL_H
#ifdef __cplusplus
extern "C" {
#endif

#define SIGABRT 6
#define SIGFPE 8
#define SIGILL 4
#define SIGINT 2
#define SIGSEGV 11
#define SIGTERM 15

typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);

int raise (int sig);

#ifdef __cplusplus
}
#endif
#endif // SIGNAL_H