

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

