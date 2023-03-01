#define MUTA1(name, typename) \
    int (*name)(typename, typename *)

#define MUTA2(name, typename) \
    int (*name)(typename, typename, typename *)
