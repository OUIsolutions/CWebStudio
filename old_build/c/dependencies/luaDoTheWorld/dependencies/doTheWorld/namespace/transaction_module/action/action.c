
DtwActionTransactionModule newDtwActionTransactionModule(){
    DtwActionTransactionModule self = {0};
    self.newAction = newDtwActionTransaction;
    self.write_any = DtwActionTransaction_write_any;
    self.move_any = DtwActionTransaction_move_any;
    self.copy_any = DtwActionTransaction_copy_any;
    self.move_any_merging = DtwActionTransaction_move_any_merging;
    self.copy_any_merging = DtwActionTransaction_move_any_merging;
    self.delete_any = DtwActionTransaction_delete_any;
    self.convert_action_to_integer =DtwActionTransaction_convert_action_to_integer;
    self.convert_action_to_string = DtwActionTransaction_convert_action_to_string;
    self.commit = DtwActionTransaction_commit;
    self.represent = DtwActionTransaction_represent;
    self.free = DtwActionTransaction_free;
    return self;
}