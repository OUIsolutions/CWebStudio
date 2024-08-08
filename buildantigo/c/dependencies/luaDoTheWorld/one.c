
#include <inttypes.h>

#include "dependecies.h"

#include "declaration.h"
#include "definition.h"


void start_lua_props(LuaCEmbed *l){
    LuaCEmbed_add_callback(l,LOAD_FILE,load_file);
    LuaCEmbed_add_callback(l,WRITE_FILE,write_file);
    LuaCEmbed_add_callback(l,COPY_ANY_OVERWRITING,copy_any_overwriting);
    LuaCEmbed_add_callback(l,COPY_ANY_MERGING,copy_any_merging);
    LuaCEmbed_add_callback(l,MOVE_ANY_OVERWRITING,move_any_overwriting);
    LuaCEmbed_add_callback(l,MOVE_ANY_MERGING,move_any_merging);
    LuaCEmbed_add_callback(l,REMOVE_ANY,remove_any);
    LuaCEmbed_add_callback(l,LIST_FILES,list_files);
    LuaCEmbed_add_callback(l,LIST_FILES_RECURSIVELY,list_files_recursively);
    LuaCEmbed_add_callback(l,LIST_DIRS,list_dirs);
    LuaCEmbed_add_callback(l,LIST_DIRS_RECURSIVELY,list_dirs_recursively);
    LuaCEmbed_add_callback(l,LIST_ALL,list_all);
    LuaCEmbed_add_callback(l,LIST_ALL_RECURSIVELY,list_all_recursively);
    LuaCEmbed_add_callback(l,BBASE_64_ENCODE_FILE,base64_encode_file);
    LuaCEmbed_add_callback(l,BBASE_64_ENCODE,base64_encode);
    LuaCEmbed_add_callback(l,BBASE_64_DECODE,base64_decode);
    LuaCEmbed_add_callback(l,GENERATE_SHA,generate_sha);
    LuaCEmbed_add_callback(l,GENERATE_SHA_FROM_FILE,generate_sha_from_file);
    LuaCEmbed_add_callback(l, NEW_RESOURCE, create_resource);
    LuaCEmbed_add_callback(l,IS_BLOB_FUNC,is_blob);
    LuaCEmbed_add_callback(l,IS_DIR_FUNC,is_dir);
    LuaCEmbed_add_callback(l,IS_FILE_FUNC,is_file);
    LuaCEmbed_add_callback(l, IS_FILE_BLOB, is_blob_file);
    LuaCEmbed_add_callback(l,NEW_HASHER,create_hasher);
    LuaCEmbed_add_callback(l,GENERATE_SHA_FROM_FOLDER_BY_CONTENT,generate_sha_from_folder_by_content);
    LuaCEmbed_add_callback(l,GENERATE_SHA_FROM_FOLDER_BY_LAST_MODIFICATION,generate_sha_from_folder_by_last_modification);
    LuaCEmbed_add_callback(l, NEW_TRANSACTION, transaction_new_transaction);
    LuaCEmbed_add_callback(l,NEW_TRANSACTION_FROM_JSON_STRING,create_empty_transaction_from_json_string);
    LuaCEmbed_add_callback(l,NEW_TRANSACTION_FROM_JSON_FILE,create_empty_transaction_from_json_file);
    LuaCEmbed_add_callback(l,NEW_PATH,create_path);
    LuaCEmbed_add_callback(l,NEW_TREE,create_empty_tree);
    LuaCEmbed_add_callback(l,CONCAT_PATH,concat_path);
    LuaCEmbed_add_callback(l,NEW_TREE_FROM_HARWARE,create_tree_fro_hardware);
    LuaCEmbed_add_callback(l,STARTS_WITH,starts_with);
    LuaCEmbed_add_callback(l,ENDS_WITH,ends_with);
}

int load_luaDoTheWorld(lua_State *state){
    
    

    LuaCEmbed * l  = newLuaCEmbedLib(state);
    start_lua_props(l);

    return LuaCembed_perform(l);
}

