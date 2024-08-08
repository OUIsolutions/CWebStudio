-- path:lua/amalgamation/actions.lua


---@param state_machine AMalgamationStateMachine
 function Verify_if_is_start_string_char(state_machine)
	if state_machine.inside_string == true then
		return
	end
    if state_machine.inside_coment then
    	return
    end
    local last_char = clib.get_char(state_machine.content,state_machine.index-1)
    if last_char == "'" then
    	return
    end

    local current_char = clib.get_char(state_machine.content,state_machine.index)
    if current_char == '"'  then
    	state_machine.inside_string  = true
    	state_machine.index = state_machine.index + 1
    end

end

---@param state_machine AMalgamationStateMachine
 function Verify_if_is_end_string_char(state_machine)

    if state_machine.inside_string == false then
    	return
    end
    if state_machine.inside_coment then
    	return
    end
    local last_last_char = clib.get_char(state_machine.content,state_machine.index-2)
    local last_char = clib.get_char(state_machine.content,state_machine.index-1)
    local current_char = clib.get_char(state_machine.content,state_machine.index)
    local scape = last_char == '\\' and last_last_char ~="\\"
    if current_char == '"' and scape == false  then
    	state_machine.inside_string = false
    	state_machine.is_end_string = true
        state_machine.index = state_machine.index + 1

    end
end


-- path:lua/amalgamation/amalgamation.lua

---@class AMalgamationStateMachine
---@field content string
---@field size number
---@field inside_string boolean
---@field waiting_include boolean
---@field string_buffer string
---@field final_text string
---@field index number
---@field is_end_string boolean
---@field buffer string
---@field inside_coment boolean
---@field inside_multiline_coment boolean
---@field insde_single_coment boolean
---@field start_path string
---@field already_include StringArray

---@param start_point string
---@param already_included_list  StringArray | nil
---@return string
  function Generate_amalgamation_recursive(start_point,already_included_list)

    if already_included_list == nil then
    	already_included_list = Created_already_included()
    end

    if not dtw.isfile(start_point)  then
    	clib.print(ANSI_RED.."file "..start_point.." not found\n")
    	clib.exit(1)
    end

    local start_point_sha = dtw.generate_sha_from_file(start_point)
    if already_included_list.is_included(start_point_sha) then
    	clib.print(ANSI_YELLOW.."file "..start_point.." already included\n ")
    	return ""
    end

    already_included_list.append(start_point_sha)
    ---@type AMalgamationStateMachine
    local content = dtw.load_file(start_point)
    local state_machine ={
         content = content,
         size = clib.get_str_size(content),
         inside_string = false,
         waiting_include = false,
         string_buffer = "",
         final_text = "//path: "..start_point.."\n",
         is_start_string=false,
         index=0,
         is_end_string = false,
         buffer="",
         inside_coment = false,
         inside_multiline_coment=false,
         insde_single_coment=false,
         start_path = start_point,
         already_include =already_included_list
    }

    for i=1,state_machine.size do
        state_machine.index = state_machine.index + 1
        Verify_if_is_start_string_char(state_machine)
        Verify_if_is_end_string_char(state_machine)
        Include_char_to_string_buffer(state_machine)
        Include_buffer_to_final(state_machine)
        Multiline_coment_start(state_machine)
        Multiline_coment_end(state_machine)
        Single_line_coment_start(state_machine)
        Single_line_coment_end(state_machine)
        Is_include_point(state_machine)
        Anulate_inclusion(state_machine)
        Make_recursive_call(state_machine)
        Include_char_to_final(state_machine)

    end

   clib.print(ANSI_GREEN.."amalgamated: "..start_point.."\n")
   return state_machine.final_text
end

-- path:lua/amalgamation/coments/multiline_coments.lua


---@param state_machine AMalgamationStateMachine
 function Multiline_coment_start(state_machine)

    if state_machine.inside_string then
    	return
    end
    if state_machine.inside_coment then
    	return
    end


    if Point_starts_with(state_machine,"/*") then
    	state_machine.index = state_machine.index + clib.get_str_size("/*")
    	state_machine.inside_coment = true
    	state_machine.inside_multiline_coment = true
    end

end
---@param state_machine AMalgamationStateMachine
 function Multiline_coment_end(state_machine)


    if not state_machine.inside_multiline_coment then
    	return
    end

    if Point_starts_with(state_machine,"*/") then
    	state_machine.index = state_machine.index + clib.get_str_size("/*")
    	state_machine.inside_coment = false
    	state_machine.inside_multiline_coment = false
    end

end


-- path:lua/amalgamation/coments/single_line_coments.lua


---@param state_machine AMalgamationStateMachine
 function Single_line_coment_start(state_machine)

    if state_machine.inside_string then
    	return
    end
    if state_machine.inside_coment then
    	return
    end



    if Point_starts_with(state_machine,"\n//") then
    	state_machine.index = state_machine.index + clib.get_str_size("\n//")
    	state_machine.inside_coment = true
    	state_machine.insde_single_coment = true
    end

end
---@param state_machine AMalgamationStateMachine
 function Single_line_coment_end(state_machine)


    if not state_machine.insde_single_coment then
    	return
    end

    if clib.get_char(state_machine.content,state_machine.index) == '\n' then
    	state_machine.index = state_machine.index +1
    	state_machine.inside_coment = false
    	state_machine.insde_single_coment = false
    end

end


-- path:lua/amalgamation/run_if_starts_with.lua

---@param state_machine AMalgamationStateMachine
---@param str string
function Point_starts_with(state_machine,str)
    local element_size = clib.get_str_size(str)
    if state_machine.index + element_size >= state_machine.size then
    	return false
    end
    local buffer = ""
    for i=state_machine.index,state_machine.index + element_size -1 do
        buffer = buffer..clib.get_char(state_machine.content,i)
    end
 --   clib.print(buffer.."\n")
    if buffer == str then
        return true
    end
    return false
end

-- path:lua/amalgamation/states.lua
---@param state_machine AMalgamationStateMachine
function Include_char_to_final(state_machine)
    if state_machine.waiting_include then
        return
    end
    if state_machine.inside_string then
        return
    end
    if state_machine.inside_coment then
        return
    end

    local current_char = clib.get_char(state_machine.content, state_machine.index)
    if not current_char then
        return
    end


    state_machine.final_text = state_machine.final_text .. current_char
end

---@param state_machine AMalgamationStateMachine
function Include_buffer_to_final(state_machine)
    if state_machine.waiting_include then
        return
    end

    if not state_machine.is_end_string then
        return
    end

    state_machine.final_text = state_machine.final_text .. '"' .. state_machine.buffer .. '"'
    state_machine.is_end_string = false
    state_machine.buffer = ""
end

---@param state_machine AMalgamationStateMachine
function Is_include_point(state_machine)
    if state_machine.inside_string then
        return
    end

    if state_machine.inside_coment then
        return
    end
    if Point_starts_with(state_machine, "#include") then
        state_machine.index = state_machine.index + clib.get_str_size("#include")
        state_machine.waiting_include = true
    end
end

---@param state_machine AMalgamationStateMachine
function Include_char_to_string_buffer(state_machine)
    if not state_machine.inside_string then
        return
    end
    if not clib.get_char(
            state_machine.content,
            state_machine.index
        ) then
        clib.print(state_machine.buffer)
    end

    state_machine.buffer = state_machine.buffer .. clib.get_char(
        state_machine.content,
        state_machine.index
    )
end

---@param state_machine AMalgamationStateMachine
function Make_recursive_call(state_machine)
    if not state_machine.waiting_include then
        return
    end
    if not state_machine.is_end_string then
        return
    end

    local dir = dtw.newPath(state_machine.start_path).get_dir()
    local full_path = dtw.concat_path(dir, state_machine.buffer)
    --clib.print("calling "..full_path.." from"..state_machine.start_path.."\n")
    local acumulated = Generate_amalgamation_recursive(full_path, state_machine.already_include)
    state_machine.final_text = state_machine.final_text .. acumulated .. "\n"
    state_machine.buffer = ""
    state_machine.is_end_string = false
    state_machine.waiting_include = false
end

---@param state_machine AMalgamationStateMachine
function Anulate_inclusion(state_machine)
    if not state_machine.waiting_include then
        return
    end
    if state_machine.inside_string then
        return
    end

    if clib.get_char(state_machine.content, state_machine.index) == "<" then
        state_machine.final_text = state_machine.final_text .. "#include "
        state_machine.waiting_include = false
    end
end

-- path:lua/c_types.lua


---@class Clib
---@field load_string fun(path:string):string
---@field get_char fun(path:string,i:number):string
---@field print fun(value:boolean | string | number)
---@field get_str_size fun(value:string): number
---@field get_time fun():number
---@field exit fun(status:number):number
---@field system_with_status fun(comand:string):number
---@field system_with_string fun(comand:string):string
---@field indexof fun(content:string,comparation:string):number
---@field out_extension fun():string
---@field replace fun(content:string,target:string,value_to_replace:string):string
---@field trim fun(content:string):string

---@type Clib
clib = clib

-- path:lua/cache/cache.lua

---@param function_name string
---@param resource_path DtwResource
---@param callback fun():string
---@return CacheCallback
local function new_cache_element(function_name,resource_path,callback)

    local self = {
        resource_path  = resource_path,
        callback = callback,
        hasher = dtw.newHasher()
    }
    self.hasher.digest(function_name)

    self.add_dependencie = function (element)
    	   self.hasher.digest(element)
    	   return self
    end

    self.perform = function ()
        local sha = self.hasher.get_value()
        local sha_resource = resource_path.sub_resource(sha)
        local possible_element = sha_resource.get_string()
        if possible_element then
        	return possible_element
        end
        local result = self.callback()
        if result == nil then
        	result = ""
        end
        sha_resource.set_value(result)
        sha_resource.commit()
        return result
    end
    return self;

end

---@param path string
---@return Cache
function NewCache(path)


    local self = {
        resource_path = dtw.newResource(path)
    }

    self.new_element =function (function_name,callback)
        return new_cache_element(function_name,self.resource_path,callback)
    end
    return self;
end

-- path:lua/cache/cache_type.lua


---@class CacheCallback
---@field hasher DtwHasher
---@field callback fun():string or nil
---@field add_dependencie fun(dependencie:string):CacheCallback
---@field perform fun():string


---@class Cache
---@field new_element fun(function_name:string,callback:fun():string | nil):CacheCallback
-- path:lua/cache/string_array.lua

---@class StringArray
---@field size number
---@field elements string[]
---@field append fun(element:string)
---@field is_included fun(element:string):boolean

---@return StringArray
function  Created_already_included()
	local self  = {
	    size = 0,
	    elements = {}
	}

	self.append = function (element)
	    self.size = self.size +1
        self.elements[self.size] = element
	end

	self.is_included = function (element)
		for i=1,self.size do
			if self.elements[i] == element then
				return true
			end
		end
		return false
	end
	return self

end
-- path:lua/colors.lua
ANSI_RED = "\x1b[31m"
ANSI_GREEN = "\x1b[32m"
ANSI_YELLOW = "\x1b[33m"
ANSI_BLUE = "\x1b[34m"
ANSI_MAGENTA= "\x1b[35m"
ANSI_CYAN= "\x1b[36m"
ANSI_RESET ="\x1b[0m"
-- path:lua/config.lua
START_POINT        = "src/one.c"
DECLARATION_POINT  = "src/declaration.h"
DEFINITION_POINT   = "src/definition.c"
LINUX_COMPILER     = "gcc"
WINDOWS_COMPILER   = "x86_64-w64-mingw32-gcc"
RELEASE_FOLDER     = "release"

CACHE_POINT        = ".cache"
OUTPUT_SINGLE_FILE = "CWebStudio.h"
LIB_FOLDER         = "src"
EXAMPLES_FOLDER    = "exemples"
TESTS_FILES        = "tests"

-- path:lua/examples.lua
function Create_examples()
    local files, size = dtw.list_files(TESTS_FILES)
    for i = 1, size do
        local current = files[i]
        local name = dtw.newPath(current).get_name()
        local new_path = dtw.concat_path(EXAMPLES_FOLDER, name);
        dtw.copy_any_overwriting(current, new_path)
    end
end

-- path:lua/hasher.lua

---@param folder string
---@return string
function Generate_sha_from_folder_not_considering_empty_folders(folder)
	local hasher = dtw.newHasher()
	local files,files_size = dtw.list_files_recursively(folder)
	for i=1,files_size do
	    local current_file = files[i]
	    local file_path = dtw.concat_path(folder,current_file)
	    local content = dtw.load_file(file_path)
		hasher.digest(current_file)
		hasher.digest(content)
	end
	local dirs,dirs_size = dtw.list_dirs_recursively(folder)
	for i=1,dirs_size do
	    local current_dir = dirs[i]
	    local dir_path = dtw.concat_path(folder,current_dir)
		local ignore,size= dtw.list_files_recursively(dir_path,false)
		if size > 0 then
			hasher.digest(current_dir)
		end
	end
	return hasher.get_value()
end

-- path:lua/lua_do_the_world_type.lua


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


---@class DtwTree
---@field newTreePart_empty fun ():DtwTreePart
---@field newTreePart_loading fun ():DtwTreePart
---@field get_tree_part_by_index fun(index:number):DtwTreePart
---@field insecure_hardware_write_tree fun():DtwTree
---@field insecure_hardware_remove fun():DtwTree
---@field commit fun():DtwTree
---@field get_size fun():number
---@field get_tree_part_by_name fun(name:string):DtwTreePart
---@field get_tree_part_by_path fun(name:string):DtwTreePart
---@field find fun(callback: fun(part:DtwTreePart):boolean):DtwTreePart
---@field count fun(callback: fun(part:DtwTreePart):boolean):number
---@field map fun(callback: fun(part:DtwTreePart):any):any[]
---@field each fun(callback: fun(part:DtwTreePart))
---@field dump_to_json_string fun():string
---@field dump_to_json_file fun():DtwTree

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
---@field insert_dir_at_index fun(index:number,dir:string):DtwPath
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
---@field each fun(callbac: fun(value:DtwActionTransaction))
---@field map fun(callbac: fun(value:DtwActionTransaction):any):any[]
---@field find fun(callbac: fun(value:DtwActionTransaction):boolean):DtwActionTransaction
---@field count fun(callbac: fun(value:DtwActionTransaction):boolean):number
---@field __index fun(index:number):DtwActionTransaction
---@field get_action fun(index:number):DtwActionTransaction
---@field commit fun():DtwTransaction


---@class DtwSchema
---@field add_primary_keys fun(values:string | string[])
---@field sub_schema fun(values:string | string[])

---@class DtwResource
---@field schema_new_insertion fun():DtwResource
---@field dangerous_remove_prop fun(primary_key:string)
---@field dangerous_rename_prop fun(primary_key:string ,new_name:string)
---@field get_resource_matching_primary_key fun(primary_key: string,  value:string | number | boolean | Dtwblobs | DtwResource ):DtwResource
---@field get_resource_by_name_id fun(id_name:string)
---@field schema_list fun(): DtwResource[]
---@field schema_each fun(callback:fun(value:DtwResource))
---@field schema_find fun(callback:fun(value:DtwResource):boolean):DtwResource
---@field schema_map fun(callback:fun(value:DtwResource):any)
---@field schema_count fun(callback:fun(value:DtwResource):boolean):number
---@field sub_resource fun(str:string) :DtwResource
---@field sub_resource_next fun(str:string) :DtwResource
---@field sub_resource_now fun(str:string) :DtwResource
---@field sub_resource_now_in_unix fun(str:string) :DtwResource
---@field __index fun(str:string) : number ,DtwResource
---@field get_value fun():string | number | boolean | nil | string
---@field get_string fun():string | nil
---@field get_number fun(): number | nil
---@field get_bool fun(): boolean | nil
---@field set_value fun(value:string | number | boolean | string | DtwResource )
---@field commit fun()  apply the modifications
---@field lock fun() lock the resource from other process
---@field unlock fun()
---@field unload fun() unload the content
---@field get_path_string fun() :string
---@field each fun(callback :fun(element:DtwResource))
---@field set_extension fun(extension:string)
---@field list fun(): DtwResource[]
---@field destroy fun()
---@field set_value_in_sub_resource fun(key:string ,value:string | number | boolean | string | DtwResource )
---@field get_value_from_sub_resource fun(key:string):string | number | boolean | nil | string
---@field newSchema fun():DtwSchema


---@class DtwModule
---@field copy_any_overwriting fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field copy_any_merging   fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field move_any_overwriting fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field move_any_merging fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field remove_any fun(src:string):boolean returns true if the operation were ok otherwise false
---@field base64_encode_file fun(src:string):string transform file into base64
---@field base64_encode fun(value:string | number | boolean | string):string transform content into base64
---@field base64_decode fun(value:string): string | string retransform base64 into normal value
---@field list_files fun(src:string,concat_path:boolean|nil):string[],number
---@field list_dirs fun(src:string,concat_path:boolean|nil):string[],number
---@field list_all fun(src:string,concat_path:boolean|nil):string[],number
---@field list_files_recursively fun(src:string,concat_path:boolean|nil):string[],number
---@field list_dirs_recursively fun(src:string,concat_path:boolean|nil):string[],number
---@field list_all_recursively fun(src:string,concat_path:boolean|nil):string[],number
---@field load_file fun(src:string):string | string
---@field write_file fun(src:string,value:string | number | boolean | DtwTreePart | DtwResource | DtwActionTransaction)
---@field is_blob fun(value:any):boolean returns if a value is a blob
---@field newResource fun(src:string):DtwResource
---@field generate_sha fun(value:string | number | boolean | string):string
---@field generate_sha_from_file fun(src:string):string
---@field generate_sha_from_folder_by_content fun(src:string):string
---@field generate_sha_from_folder_by_last_modification fun(src:string):string
---@field newHasher fun():DtwHasher
---@field isdir fun(path:string):boolean
---@field isfile fun(path:string):boolean
---@field isfile_blob fun(path:string):boolean
---@field newTransaction fun():DtwTransaction
---@field newTransaction_from_file fun():DtwTransaction
---@field newTransaction_from_json_string fun():DtwTransaction
---@field newPath fun(path:string):DtwPath
---@field newTree fun():DtwTree
---@field newTree_from_hardware fun(path:string):DtwTree
---@field concat_path fun(path1:string,path2:string):string
---@field starts_with fun(comparation:string,prefix:string):boolean
---@field ends_with fun(comparation:string,sulfix:string):boolean



---@type DtwModule
dtw = dtw
-- path:lua/readme_creation.lua


---@param content string
---@param index number
local function is_codeof_at_point(content,index)
    local codeof_size = clib.get_str_size(CODEOF_TEXT)
    local content_size = clib.get_str_size(content)
    if index + codeof_size >= content_size then
    	return false
    end

    local buffer = ""
    for i=index,index + codeof_size -1 do
    	buffer = buffer..clib.get_char(content,i)
    end

    return buffer == CODEOF_TEXT

end


---@return string |nil
function Create_readme()
    local content = dtw.load_file("build/INTERNAL.md")
    if content == nil then
    	clib.print("intenal readme not found\n")
    	clib.exit(1)
        return
    end

    local i = 1
    local size = clib.get_str_size(content)
    local codeof_size = clib.get_str_size(CODEOF_TEXT)

    local colecting = false
    local final_text = ""
    local path = ""
    while i < size do

        if is_codeof_at_point(content,i) then
            colecting = true
            i = i + codeof_size+1
        end
        local is_end_char = clib.get_char(content,i) == "\n"

        if colecting and not  is_end_char   then
            path = path..clib.get_char(content,i)
        end

        if colecting ==false then
        	final_text = final_text..clib.get_char(content,i)
        end

        if colecting and is_end_char then
            path = clib.trim(path)
        	local file_content = dtw.load_file(path)
        	if file_content == nil then

        		clib.print(ANSI_RED.."file ("..path..") not found\n")
        		clib.exit(1)
        	end

            local extension = dtw.newPath(path).get_extension()
            final_text = final_text.."\n~~~"..extension.."\n"..file_content.."\n~~~\n"
            colecting = false
            path =""
        end




    	i = i + 1
    end
    return final_text

end
-- path:lua/test.lua
---@param file string
---@param compiler string
local function execute_c_tests(file, compiler)
    local result = clib.system_with_status(compiler .. " " .. file)
    if result ~= 0 then
        clib.print(ANSI_RED .. "file " .. file .. "not passed in gcc")
        clib.exit(1)
    end
end

function Execute_all_tests()
    local files, size = dtw.list_files(TESTS_FILES)
    for i = 1, size do
        local current = files[i]
        execute_c_tests(current, "gcc")
        execute_c_tests(current, "g++")
    end
end

local function main()
    local src_sha = Generate_sha_from_folder_not_considering_empty_folders(LIB_FOLDER)
    local cache = NewCache(CACHE_POINT)



    local amalgamation_cache = cache.new_element("amalgamation", function()
        return Generate_amalgamation_recursive(START_POINT)
    end).add_dependencie(src_sha)
    local amalgamation_result = Generate_amalgamation_recursive(START_POINT)
    dtw.write_file(END_TEST_POINT, amalgamation_result)

    Execute_all_tests()
    Create_examples()
    local readme = Create_readme()
    if readme then
        dtw.write_file("README.md", readme)
    end
end

main()

