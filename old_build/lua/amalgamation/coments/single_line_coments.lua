

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

