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
function Generate_amalgamation_recursive(start_point, already_included_list)
    if already_included_list == nil then
        already_included_list = Created_already_included()
    end

    if not dtw.isfile(start_point) then
        clib.print(ANSI_RED .. "file " .. start_point .. " not found\n")
        clib.exit(1)
    end

    local real_path = clib.absolute_path(start_point)

    if already_included_list.is_included(real_path) then
        clib.print(ANSI_YELLOW .. "file " .. real_path .. " already included\n ")
        return ""
    end

    already_included_list.append(real_path)
    ---@type AMalgamationStateMachine
    local content = dtw.load_file(start_point)
    local state_machine = {
        content = content,
        size = clib.get_str_size(content),
        inside_string = false,
        waiting_include = false,
        string_buffer = "",
        final_text = "//path: " .. start_point .. "\n",
        is_start_string = false,
        index = 0,
        is_end_string = false,
        buffer = "",
        inside_coment = false,
        inside_multiline_coment = false,
        insde_single_coment = false,
        start_path = start_point,
        already_include = already_included_list
    }

    for i = 1, state_machine.size do
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

    clib.print(ANSI_GREEN .. "amalgamated: " .. start_point .. "\n")
    return state_machine.final_text
end
