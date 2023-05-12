#ifndef TIME_H
#define TIME_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#define CLOCKS_PER_SEC 1

typedef uint64_t time_t;

typedef struct timespec {
    time_t  tv_sec;  /* Seconds */
    long    tv_nsec; /* Nanoseconds */
} timespec;

struct tm {
	int tm_sec;         /* seconds,  range 0 to 59          */
	int tm_min;         /* minutes, range 0 to 59           */
	int tm_hour;        /* hours, range 0 to 23             */
	int tm_mday;        /* day of the month, range 1 to 31  */
	int tm_mon;         /* month, range 0 to 11             */
	int tm_year;        /* The number of years since 1900   */
	int tm_wday;        /* day of the week, range 0 to 6    */
	int tm_yday;        /* day in the year, range 0 to 365  */
	int tm_isdst;       /* daylight saving time             */
};
typedef uint64_t clock_t;

char *asctime(const struct tm *timeptr);
clock_t clock(void);
char *ctime(const time_t *timer);
double difftime(time_t time1, time_t time2);
struct tm *gmtime(const time_t *timer);
struct tm *localtime(const time_t *timer);
time_t mktime(struct tm *timeptr);
size_t strftime(char *str, size_t maxsize, const char *format, const struct tm *timeptr);
time_t time(time_t *timer);

#ifdef __cplusplus
}
#endif
#endif // TIME_H