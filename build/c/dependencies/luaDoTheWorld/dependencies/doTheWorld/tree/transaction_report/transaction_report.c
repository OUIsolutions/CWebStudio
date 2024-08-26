

struct DtwTreeTransactionReport * newDtwTreeTransactionReport(){
    struct DtwTreeTransactionReport *new_report = (struct DtwTreeTransactionReport *)malloc(sizeof(struct DtwTreeTransactionReport));
    new_report->write = newDtwStringArray();
    new_report->modify = newDtwStringArray();
    new_report->remove = newDtwStringArray();
    return new_report;
}

void  DtwTreeTransactionReport_represent(struct DtwTreeTransactionReport *report){
    printf("Write:---------------------------------------\n");
    DtwStringArray_represent(report->write);
    printf("Modify:--------------------------------------\n");
    DtwStringArray_represent(report->modify);
    printf("Remove:--------------------------------------\n");
    DtwStringArray_represent(report->remove);
    puts("");
}

void  DtwTreeTransactionReport_free(struct DtwTreeTransactionReport *report){
    DtwStringArray_free(report->write);
    DtwStringArray_free(report->modify);
    DtwStringArray_free(report->remove);
    free(report);
}