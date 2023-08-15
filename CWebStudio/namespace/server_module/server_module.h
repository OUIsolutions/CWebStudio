
typedef struct CwebSeverModule{
    void (*start)(struct  CwebSever *self);
    void (*free)(struct  CwebSever *self);
}CwebSeverModule;

CwebSeverModule newCwebSeverModule();