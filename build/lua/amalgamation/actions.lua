---@param state_machine AMalgamationStateMachine
function Verify_if_is_start_string_char(state_machine)
    if state_machine.inside_string == true then
        return
    end
    if state_machine.inside_coment then
        return
    end
    local last_char = clib.get_char(state_machine.content, state_machine.index - 1)
    if last_char == "'" then
        return
    end
    if last_char == "\\" then
        return
    end

    local current_char = clib.get_char(state_machine.content, state_machine.index)
    if current_char == '"' then
        state_machine.inside_string = true
        state_machine.index         = state_machine.index + 1
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
    local last_last_char = clib.get_char(state_machine.content, state_machine.index - 2)
    local last_char = clib.get_char(state_machine.content, state_machine.index - 1)
    local current_char = clib.get_char(state_machine.content, state_machine.index)
    local scape = last_char == '\\' and last_last_char ~= "\\"
    if current_char == '"' and scape == false then
        state_machine.inside_string = false
        state_machine.is_end_string = true
        state_machine.index = state_machine.index + 1
    end
end
