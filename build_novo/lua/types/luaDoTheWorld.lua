
---@class DtwFork
---@field sleep_time number
---@field kill fun()
---@field is_alive fun():boolean
---@field wait fun(milliseconds:number)

---@class DtwLocker
---@field lock fun(element:string):boolean
---@field unlock fun(element:string):DtwLocker


---@class DtwRandonizer
---@field set_seed fun(seed:number):DtwRandonizer
---@field set_time_seed fun(seed:number):DtwRandonizer
---@field generate_token fun(size:number):DtwRandonizer
---@field generate_num fun(size:number):number

---@class DtwTreeProps
---@field include_content boolean | nil
---@field include_content_data boolean | nil
---@field include_hardware_data boolean | nil
---@field include_ignored_elements boolean | nil
---@field mimify_json boolean | nil
---@field include_path_attributes boolean | nil

---@class DtwTreePart
---@field path DtwPath
---@field get_value fun():string
---@field set_value fun(value:string | number | boolean | DtwTreePart | DtwResource | DtwActionTransaction)
---@field hardware_remove fun(as_transaction:boolean|nil):DtwTreePart
---@field hardware_write fun(as_transaction:boolean|nil):DtwTreePart
---@field hardware_modify fun(as_transaction:boolean|nil):DtwTreePart
---@field get_sha fun():string
---@field is_blob fun():boolean
---@field unload fun():DtwTreePart
---@field load fun():DtwTreePart
---@field content_exist_in_hardware fun():boolean
---@field content_exist fun():boolean

---@class DtwTree
---@field newTreePart_empty fun (path:string):DtwTreePart
---@field newTreePart_loading fun (path:string):DtwTreePart
---@field get_tree_part_by_index fun(index:number):DtwTreePart
---@field insecure_hardware_write_tree fun():DtwTree
---@field insecure_hardware_remove fun():DtwTree
---@field commit fun():DtwTree
---@field get_size fun():number
---@field get_tree_part_by_name fun(name:string):DtwTreePart
---@field get_tree_part_by_path fun(name:string):DtwTreePart
---@field add_tree_from_hardware fun(path:string,props:DtwTreeProps | nil):DtwTreePart
---@field list fun(): DtwTreePart[] ,number
---@field find fun(callback: fun(part:DtwTreePart):boolean):DtwTreePart
---@field count fun(callback: fun(part:DtwTreePart):boolean):number
---@field map fun(callback: fun(part:DtwTreePart):any):any[]
---@field each fun(callback: fun(part:DtwTreePart))
---@field filter fun(callback:fun(part:DtwTreePart):boolean):DtwTreePart[],number
---@field dump_to_json_string fun(props:DtwTreeProps | nil):string
---@field dump_to_json_file fun(file:string,props:DtwTreeProps | nil):DtwTree


---@class DtwPath
---@field path_changed fun():boolean
---@field add_start_dir fun(start_dir:string):DtwPath
---@field add_end_dir_method fun (end_dir:string):DtwPath
---@field changed fun():boolean
---@field get_dir fun():string
---@field get_extension fun():string
---@field get_name fun():string
---@field get_only_name fun():string
---@field get_full_path fun():string
---@field set_name fun(new_name:string) DtwPath
---@field set_only_name fun(new_name:string) DtwPath
---@field set_extension fun(extension:string):DtwPath
---@field set_dir fun(dir:string):DtwPath
---@field set_path fun(path:string):DtwPath
---@field replace_dirs fun(old_dir:string,new_dir:string):DtwPath
---@field get_total_dirs fun():number
---@field get_sub_dirs_from_index fun(start:number,end:number):string
---@field insert_dir_at_index fun(dir:string,index:number):DtwPath
---@field remove_sub_dir_at_index fun(start:number,end:number):DtwPath
---@field insert_dir_after fun(point:string, dir:string):DtwPath
---@field insert_dir_before fun(point:string, dir:string):DtwPath
---@field remove_dir_at fun(point:string):DtwPath
---@field unpack fun():string[],number



---@class DtwHasher
---@field digest fun(value:string | number | boolean | string ):DtwHasher
---@field digest_file fun(source:string):DtwHasher
---@field digest_folder_by_content fun(source:string):DtwHasher
---@field digest_folder_by_last_modification fun(source:string):DtwHasher
---@field get_value fun():string

---@class DtwActionTransaction
---@field get_type_code fun():number
---@field get_type fun():string
---@field get_content fun():string
---@field set_content fun()
---@field get_source fun():string
---@field get_dest fun():string
---@field set_dest fun():string


---@class DtwTransaction
---@field write fun(src :string , value:string | number | boolean | string | DtwResource ):DtwTransaction
---@field remove_any fun(src:string):DtwTransaction
---@field copy_any fun(src:string,dest:string):DtwTransaction
---@field move_any fun(src:string,dest:string):DtwTransaction
---@field dump_to_json_string fun():string
---@field dump_to_json_file fun(src:string):DtwTransaction
---@field list fun(): DtwActionTransaction[] ,number
---@field each fun(callbac: fun(value:DtwActionTransaction))
---@field map fun(callbac: fun(value:DtwActionTransaction):any):any[],number
---@field find fun(callbac: fun(value:DtwActionTransaction):boolean):DtwActionTransaction
---@field count fun(callbac: fun(value:DtwActionTransaction):boolean):number
---@field filter fun(callback:fun(part:DtwActionTransaction):boolean):DtwActionTransaction[],number
---@field __index fun(index:number):DtwActionTransaction
---@field get_action fun(index:number):DtwActionTransaction
---@field commit fun():DtwTransaction


---@class DtwSchema
---@field add_primary_keys fun(values:string | string[])
---@field sub_schema fun(values:string | string[]):DtwSchema
---@field set_value_name fun(name:string):DtwSchema
---@field set_index_name fun(name:string):DtwSchema


---@class DtwDatabaseSchema
---@field sub_schema fun(values:string | string[]):DtwSchema
---@field set_value_name fun(name:string):DtwSchema
---@field set_index_name fun(name:string):DtwSchema


---@class DtwResourceListaage
---@field resources DtwResource[] | nil
---@field size number | nil
---@field error string | nil



---@class DtwResource
---@field schema_new_insertion fun():DtwResource
---@field dangerous_remove_prop fun(primary_key:string):DtwResource
---@field dangerous_rename_prop fun(primary_key:string ,new_name:string) :DtwResource
---@field get_resource_matching_primary_key fun(primary_key: string,  value:string | number | boolean | Dtwblobs | DtwResource ):DtwResource
---@field get_resource_by_name_id fun(id_name:string)  DtwResource | nil
---@field list fun(): DtwResource[] ,number
---@field each fun(callback :fun(element:DtwResource))
---@field find fun(callback:fun(value:DtwResource):boolean):DtwResource
---@field map fun(callback:fun(value:DtwResource):any):any[],number
---@field count fun(callback:fun(value:DtwResource):boolean):number
---@field filter fun(callback:fun(value:DtwResource):boolean):DtwResource[],number
---@field schema_list fun(): DtwResource[]
---@field schema_each fun(callback:fun(value:DtwResource))
---@field schema_find fun(callback:fun(value:DtwResource):boolean):DtwResource
---@field schema_map fun(callback:fun(value:DtwResource):any):any[],number
---@field schema_count fun(callback:fun(value:DtwResource):boolean):number
---@field schema_filter fun(callback:fun(value:DtwResource):boolean):DtwResource[],number
---@field sub_resource fun(str:string) :DtwResource
---@field sub_resource_next fun(str:string | nil) :DtwResource
---@field sub_resource_now fun(str:string | nil) :DtwResource
---@field sub_resource_random fun(str:string | nil) :DtwResource
---@field sub_resource_now_in_unix fun(str:string | nil) :DtwResource
---@field __index fun(str:string) : number ,DtwResource
---@field get_value fun():string | number | boolean | nil | string
---@field get_string fun():string | nil
---@field get_type fun():string
---@field get_number fun(): number | nil
---@field get_bool fun(): boolean | nil
---@field set_value fun(value:string | number | boolean | string | DtwResource ):boolean
---@field commit fun()  apply the modifications
---@field lock fun() boolean
---@field unlock fun():DtwResource
---@field unload fun() unload the content 
---@field get_path_string fun() :string
---@field set_extension fun(extension:string)
---@field destroy fun():DtwResource
---@field set_value_in_sub_resource fun(key:string ,value:string | number | boolean | string | DtwResource )
---@field try_set_value_in_sub_resource fun(key:string ,value:string | number | boolean | string | DtwResource ):boolean,string | nil
---@field get_value_from_sub_resource fun(key:string):string | number | boolean | nil | string
---@field newDatabaseSchema fun():DtwDatabaseSchema
---@field try_newSchema fun():boolean,string | DtwSchema
---@field try_rename fun(new_name:string):boolean,string | nil
---@field rename fun(new_name:string)
---@field try_set_value fun(value:string | number | boolean | string | DtwResource ):boolean,string | nil
---@field try_destroy fun():boolean,string | nil
---@field try_schema_new_insertion fun():boolean,string | DtwResource
---@field try_get_resource_by_name_id fun(id_name:string) :boolean,string | DtwResource
---@field try_dangerous_rename_prop fun(primary_key:string ,new_name:string):boolean,string | nil
---@field try_dangerous_remove_prop fun(primary_key:string):boolean,string | nil
---@field try_sub_resource fun(name:string):boolean,string | DtwResource
---@field try_sub_resource_next fun(name:string):boolean,string | DtwResource
---@field try_sub_resource_now fun(name:string):boolean,string | DtwResource
---@field try_sub_resource_now_in_unix fun(name:string):boolean,string | DtwResource
---@field try_sub_resource_random fun(name:string):boolean,string | DtwResource
---@field try_schema_list fun():DtwResourceListaage
---@field get_transaction fun():DtwTransaction


---@class DtwModule
---@field copy_any_overwriting fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field copy_any_merging   fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field move_any_overwriting fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field move_any_merging fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field remove_any fun(src:string):boolean returns true if the operation were ok otherwise false
---@field base64_encode_file fun(src:string):string transform file into base64 
---@field base64_encode fun(value:string | number | boolean | string):string transform content into base64
---@field base64_decode fun(value:string): string | string retransform base64 into normal value
---@field list_files fun(src:string,concat_path:boolean):string[],number
---@field list_dirs fun(src:string,concat_path:boolean):string[],number
---@field list_all fun(src:string,concat_path:boolean):string[],number
---@field list_files_recursively fun(src:string,concat_path:boolean):string[],number
---@field list_dirs_recursively fun(src:string,concat_path:boolean):string[],number
---@field list_all_recursively fun(src:string,concat_path:boolean):string[],number
---@field load_file fun(src:string):string | string
---@field write_file fun(src:string,value:string | number | boolean | DtwTreePart | DtwResource | DtwActionTransaction)
---@field is_blob fun(value:any):boolean returns if a value is a blob
---@field newResource fun(src:string):DtwResource
---@field generate_sha fun(value:string | number | boolean | string):string
---@field generate_sha_from_file fun(src:string):string
---@field generate_sha_from_folder_by_content fun(src:string):string
---@field generate_sha_from_folder_by_last_modification fun(src:string):string
---@field newHasher fun():DtwHasher
---@field isdir fun(file:string):boolean
---@field isfile fun(file:string):boolean
---@field isfile_blob fun(file:string):boolean
---@field newTransaction fun():DtwTransaction
---@field new_transaction_from_file fun(file:string):DtwTransaction
---@field new_transaction_from_string fun(content:string):DtwTransaction
---@field try_new_transaction_from_file fun(file:string):boolean,DtwTransaction |string
---@field try_new_transaction_from_string fun(content:string):boolean, DtwTransaction | string
---@field newPath fun(path:string):DtwPath
---@field newTree fun():DtwTree
---@field newTree_from_hardware fun(path:string,props:DtwTreeProps | nil):DtwTree
---@field newTree_from_json_file fun(path:string):DtwTree
---@field newTree_from_json_string fun (content:string):DtwTree
---@field try_newTree_from_json_file fun(path:string):DtwTree
---@field try_newTree_from_json_string fun (content:string):DtwTree
---@field concat_path fun(path1:string,path2:string):string
---@field starts_with fun(comparation:string,prefix:string):boolean
---@field ends_with fun(comparation:string,sulfix:string):boolean
---@field newRandonizer fun():DtwRandonizer
---@field newFork fun(callback:fun()):DtwFork
---@field newLocker fun():DtwLocker
---@field get_entity_last_modification_in_unix fun(entity:string):number | nil
---@field get_entity_last_modification fun(entity:string):string | nil

---@type DtwModule
dtw = dtw