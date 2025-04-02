
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
