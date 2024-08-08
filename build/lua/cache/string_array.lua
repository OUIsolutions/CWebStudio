
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