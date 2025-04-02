

---@class CacheCallback
---@field hasher DtwHasher
---@field callback fun():string or nil
---@field add_dependencie fun(dependencie:string):CacheCallback
---@field perform fun():string


---@class Cache
---@field new_element fun(function_name:string,callback:fun():string | nil):CacheCallback