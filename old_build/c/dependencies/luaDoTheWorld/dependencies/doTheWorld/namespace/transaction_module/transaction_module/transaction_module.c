

DtwTransactionModule newDtwTransactionModule(){
    DtwTransactionModule self = {0};
    self.newTransaction = newDtwTransaction;
    self.newTransaction_from_json = newDtwTransaction_from_json;
    self.newTransaction_from_json_file = newDtwTransaction_from_json_file;
    self.validate_json_transaction_file = dtw_validate_json_transaction_file;
    self.remove_from_index = DtwTransaction_remove_from_index;
    self.remove_from_source = DtwTransaction_remove_from_source;
    self.filter = DtwTransaction_filter;
    self.append_action = DtwTransaction_append_action;
    self.write_any = DtwTransaction_write_any;
    self.write_string = DtwTransaction_write_string;
    self.write_long = DtwTransaction_write_long;
    self.write_bool = DtwTransaction_write_bool;
    self.write_double = DtwTransaction_write_double;

    self.move_any_merging = DtwTransaction_move_any_merging;
    self.copy_any_merging = DtwTransaction_copy_any_merging;
    self.move_any = DtwTransaction_move_any;
    self.copy_any = DtwTransaction_copy_any;
    self.delete_any = DtwTransaction_delete_any;

    self.dumps_transaction_to_json = DtwTransaction_dumps_to_json;
    self.dumps_transaction_to_json_file = DtwTransaction_dumps_to_json_file;

    self.commit = DtwTransaction_commit;
    self.represent = DtwTransaction_represent;
    self.free =DtwTransaction_free;

    self.action = newDtwActionTransactionModule();
    self.json_error = newDtwJsonTransactionErrorModule();


    return self;
}
