

---@type fun(index:number):string
getargv = getargv

---@type fun(msg:string |nil ):string
input = input


---@type fun(exitcode:number)
exit = exit

---@class Bin
---@field getbin fun(name:string):string
---@field isfile fun(name:string):boolean
---@field exist fun(name:string):boolean
---@field isdir fun(name:string):boolean
---@field list_files_recursively fun(start_path:string|nil):string[]
---@field list_files fun(start_path:string|nil):string[]
---@field list_all_recursively fun(start_path:string|nil):string[]
---@field list_all fun(start_path:string|nil):string[]
---@field list_dirs_recursively fun(start_path:string|nil):string[]
---@field list_dirs fun(start_path:string|nil):string[]

---@type Bin
bin = bin