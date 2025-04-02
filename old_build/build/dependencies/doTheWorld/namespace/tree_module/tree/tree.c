
DtwTreeModule newDtwTreeModule(){
    DtwTreeModule self = {0};
    self.newTree = newDtwTree;
    self.add_tree_part_by_copy = DtwTree_add_tree_part_copy;
    self.remove_tree_part  = DtwTree_remove_tree_part;
    self.add_tree_part_getting_owenership = DtwTree_add_tree_part_getting_onwership;
    self.add_tree_part_referencing = DtwTree_add_tree_part_referencing;
    self.add_tree_parts_from_string_array = DtwTree_add_tree_parts_from_string_array;
    self.get_sub_tree = DtwTree_get_sub_tree;
    self.add_tree_from_hardware = DtwTree_add_tree_from_hardware;
    self.find_tree_part_by_function = DtwTree_find_tree_part_by_function;
    self.filter = DtwTree_filter;
    self.map = DtwTree_map;

    self.list_files = DtwTree_list_files;
    self.list_dirs = DtwTree_list_dirs;
    self.list_all = DtwTree_list_all;

    self.list_files_recursively = DtwTree_list_files_recursively;
    self.list_dirs_recursively = DtwTree_list_dirs_recursively;
    self.list_all_recursively = DtwTree_list_all_recursively;

    self.find_tree_part_by_name = DtwTree_find_tree_part_by_name;
    self.find_tree_part_by_path = DtwTree_find_tree_part_by_path;

    self.create_report = DtwTree_create_report;
    self.loads_json_tree = DtwTree_loads_json_tree;
    self.loads_json_tree_from_file = DtwTree_loads_json_tree_from_file;
    self.dumps_json_tree = DtwTree_dumps_tree_json;
    self.dumps_json_tree_to_file = DtwTree_dumps_tree_json_to_file;

    self.represent = DtwTree_represent;
    self.insecure_hardware_remove_tree = DtwTree_insecure_hardware_remove_tree;
    self.insecure_hardware_write_tree = DtwTree_insecure_hardware_write_tree;
    self.hardware_commit_tree = DtwTree_hardware_commit_tree;
    self.free = DtwTree_free;
    self.transaction_report = newDtwTreeTransactionReportModule();
    self.part = newDtwTreePartModule();
    self.json_error = newDtwJsonTreeErrorModule();
    return self;
}