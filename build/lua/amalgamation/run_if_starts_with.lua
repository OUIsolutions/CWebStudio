
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
