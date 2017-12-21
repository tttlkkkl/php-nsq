#include <stdio.h>
#include <event2/bufferevent.h>  

const static char * NEW_LINE = "\n";
const static int MAX_BUF_SIZE = 128;

void nsq_subscribe(struct bufferevent *bev, const char *topic, const char *channel)
{
    char b[MAX_BUF_SIZE];
    size_t n;

    n = sprintf(b, "SUB %s %s%s", topic, channel, NEW_LINE);
    bufferevent_write(bev, b, n);  
}

void nsq_ready(struct bufferevent *bev, int count)
{
    char b[MAX_BUF_SIZE];
    size_t n;

    n = sprintf(b, "RDY %d%s", count, NEW_LINE);
    bufferevent_write(bev, b, n);  
}

void nsq_finish(struct bufferevent *bev, const char *id)
{
    char b[MAX_BUF_SIZE];
    size_t n;

    n = sprintf(b, "FIN %s%s", id, NEW_LINE);
    bufferevent_write(bev, b, n);  
}


void nsq_nop(struct bufferevent *bev)
{
    char b[MAX_BUF_SIZE];
    size_t n;
    n = sprintf(b, "NOP%s", NEW_LINE);
    bufferevent_write(bev, b, n);
}

void nsq_requeue(struct bufferevent *bev, const char *id, int timeout_ms)
{
    char b[MAX_BUF_SIZE];
    size_t n;

    n = sprintf(b, "REQ %s %d%s", id, timeout_ms, NEW_LINE);
    bufferevent_write(bev, b, n);  
}
