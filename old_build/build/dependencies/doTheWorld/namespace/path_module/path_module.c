
DtwPathModule newDtwPathModule(){
    DtwPathModule  self = {0};
    self.newPath = newDtwPath;
    self.changed =DtwPath_changed;
    self.get_full_name = DtwPath_get_full_name;
    self.get_name = DtwPath_get_name;
    self.get_extension = DtwPath_get_extension;
    self.get_path = DtwPath_get_path;
    self.get_dir = DtwPath_get_dir;
    self.get_total_dirs = DtwPath_get_total_dirs;
    self.get_sub_dirs_from_index = DtwPath_get_sub_dirs_from_index;
    self.insert_dir_at_index = DtwPath_insert_dir_at_index;
    self.remove_sub_dirs_at_index =  DtwPath_remove_sub_dirs_at_index;
    self.insert_dir_after= DtwPath_insert_dir_after;
    self.insert_dir_before = DtwPath_insert_dir_before;
    self.replace_dirs = DtwPath_replace_dirs;
    self.remove_sub_dirs_at = DtwPath_remove_sub_dirs_at;

    self.set_extension = DtwPath_set_extension;
    self.set_name = DtwPath_set_name;
    self.set_dir = DtwPath_set_dir;
    self.set_full_name =DtwPath_set_full_name;
    self.set_path = DtwPath_set_path;

    self.add_start_dir =DtwPath_add_start_dir;
    self.add_end_dir = DtwPath_add_end_dir;
    self.represent = DtwPath_represent;
    self.free = DtwPath_free;

    return self;
}