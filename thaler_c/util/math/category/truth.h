#define MUTT1(name, typename) \
    int (*name)(typename, int *)

#define MUTT2(name, typename) \
    int (*name)(typename, typename, int *)

