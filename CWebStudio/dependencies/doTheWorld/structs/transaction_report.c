

struct DtwTransactionReport * dtw_constructor_transaction_report(){
    struct DtwTransactionReport *new_report = (struct DtwTransactionReport *)malloc(sizeof(struct DtwTransactionReport));
    new_report->write = dtw_constructor_string_array();
    new_report->modify = dtw_constructor_string_array();
    new_report->remove = dtw_constructor_string_array();
    new_report->represent = private_dtw_represent_transaction;
    new_report->free_transaction = private_dtw_free_transaction;
    return new_report;
}

void  private_dtw_represent_transaction(struct DtwTransactionReport *report){
    printf("Write:---------------------------------------\n");
    report->write->represent(report->write);
    printf("Modify:--------------------------------------\n");
    report->modify->represent(report->modify);
    printf("Remove:--------------------------------------\n");
    report->remove->represent(report->remove);
    puts("");
}

void  private_dtw_free_transaction(struct DtwTransactionReport *report){
    report->write->free_string_array(report->write);
    report->modify->free_string_array(report->modify);
    report->remove->free_string_array(report->remove);
    free(report);
}