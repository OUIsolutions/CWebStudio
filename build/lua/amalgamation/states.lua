

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

    local current_char = clib.get_char(state_machine.content,state_machine.index)
    if not current_char then
    	return
    end


 	state_machine.final_text =  state_machine.final_text..current_char


end

---@param state_machine AMalgamationStateMachine
 function Include_buffer_to_final(state_machine)

    if state_machine.waiting_include then
    	return
    end

    if not state_machine.is_end_string then
    	return
    end

    state_machine.final_text = state_machine.final_text..'"'..state_machine.buffer..'"'
    state_machine.is_end_string = false
    state_machine.buffer = ""

end

---@param state_machine AMalgamationStateMachine
 function Is_include_point(state_machine)

    if  state_machine.inside_string then
    	return
    end

    if state_machine.inside_coment then
    	return
    end
    if Point_starts_with(state_machine,"#include") then
       	state_machine.index = state_machine.index + clib.get_str_size("#include")
       	state_machine.waiting_include = true
    end
end


---@param state_machine AMalgamationStateMachine
 function Include_char_to_string_buffer(state_machine)

    if not state_machine.inside_string then
        return
    end
    state_machine.buffer = state_machine.buffer..clib.get_char(state_machine.content,state_machine.index)

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
	local full_path = dtw.concat_path(dir,state_machine.buffer)
	--clib.print("calling "..full_path.." from"..state_machine.start_path.."\n")
    local acumulated = Generate_amalgamation_recursive(full_path,state_machine.already_include)
    state_machine.final_text= state_machine.final_text.. acumulated.."\n"
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

    if clib.get_char(state_machine.content,state_machine.index) == "<" then
       state_machine.final_text = state_machine.final_text.."#include "
       state_machine.waiting_include = false
    end

end

