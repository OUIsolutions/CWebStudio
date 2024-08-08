


typedef struct  DtwTree{
    int size;
     DtwTreePart **tree_parts;

}DtwTree;


 DtwTree *DtwTree_get_sub_tree(
     DtwTree *self,
    const char *path,
    bool copy_content
);

 DtwTreePart *DtwTree_find_tree_part_by_function(DtwTree *self,bool (*caller)(  DtwTreePart *part));


 DtwTree *DtwTree_map(DtwTree *self, DtwTreePart* (*caller)( DtwTreePart *part));


 DtwTree *DtwTree_filter(DtwTree *self,bool (*caller)(struct  DtwTreePart *part));


 DtwTreePart *DtwTree_find_tree_part_by_name( DtwTree *self, const char *name);
 DtwTreePart *DtwTree_find_tree_part_by_path( DtwTree *self, const char *path);

//listages
 DtwStringArray *DtwTree_list_files( DtwTree *self, const char *path,bool concat_path);

 DtwStringArray *DtwTree_list_dirs( DtwTree *self, const char *path,bool concat_path);

 DtwStringArray *DtwTree_list_all( DtwTree *self, const char *path,bool concat_path);

 DtwStringArray *DtwTree_list_files_recursively( DtwTree *self, const char *path,bool concat_path);

 DtwStringArray *DtwTree_list_dirs_recursively( DtwTree *self, const char *path,bool concat_path);

 DtwStringArray *DtwTree_list_all_recursively( DtwTree *self, const char *path,bool concat_path);


void DtwTree_remove_tree_part( DtwTree *self, int position);

void DtwTree_add_tree_part_copy( DtwTree *self,  DtwTreePart *tree_part);

void DtwTree_add_tree_part_getting_onwership( DtwTree *self,  DtwTreePart *tree_part);

void DtwTree_add_tree_part_referencing( DtwTree *self,  DtwTreePart *tree_part);

void DtwTree_free( DtwTree *self);
void DtwTree_represent( DtwTree *self);

void DtwTree_add_tree_parts_from_string_array(DtwTree *self,DtwStringArray *paths,DtwTreeProps props);

void DtwTree_add_tree_from_hardware(DtwTree *self,const char *path,DtwTreeProps props);

 DtwTreeTransactionReport * DtwTree_create_report( DtwTree *self);



void DtwTree_insecure_hardware_remove_tree( DtwTree *self);

void DtwTree_insecure_hardware_write_tree( DtwTree *self);

void DtwTree_hardware_commit_tree( DtwTree *self);

bool DtwTree_loads_json_tree( DtwTree *self, const char *content);

bool DtwTree_loads_json_tree_from_file( DtwTree *self, const char *path);

char * DtwTree_dumps_tree_json(DtwTree *self,DtwTreeProps  props);

void DtwTree_dumps_tree_json_to_file(DtwTree *self,const char *path,DtwTreeProps  props);

  DtwTree * newDtwTree();

