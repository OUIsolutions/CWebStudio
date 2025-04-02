
typedef struct DtwTreeTransactionReport{
    DtwStringArray *write;
    DtwStringArray *modify;
    DtwStringArray *remove;

}DtwTreeTransactionReport;

struct DtwTreeTransactionReport * newDtwTreeTransactionReport();
void  DtwTreeTransactionReport_represent(struct DtwTreeTransactionReport *report);
void  DtwTreeTransactionReport_free(struct DtwTreeTransactionReport *report);