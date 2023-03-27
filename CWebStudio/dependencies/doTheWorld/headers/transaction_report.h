
struct DtwTransactionReport{
    struct DtwStringArray *write;
    struct DtwStringArray *modify;
    struct DtwStringArray *remove;
    void (*represent)(struct DtwTransactionReport *report);
    void (*free_transaction)(struct DtwTransactionReport *report);
};

struct DtwTransactionReport * dtw_constructor_transaction_report();
void  private_dtw_represent_transaction(struct DtwTransactionReport *report);
void  private_dtw_free_transaction(struct DtwTransactionReport *report);