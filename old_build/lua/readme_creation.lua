

---@param content string
---@param index number
local function is_codeof_at_point(content,index)
    local codeof_size = clib.get_str_size(CODEOF_TEXT)
    local content_size = clib.get_str_size(content)
    if index + codeof_size >= content_size then
    	return false
    end

    local buffer = ""
    for i=index,index + codeof_size -1 do
    	buffer = buffer..clib.get_char(content,i)
    end

    return buffer == CODEOF_TEXT

end


---@return string |nil
function Create_readme()
    local content = dtw.load_file("build/INTERNAL.md")
    if content == nil then
    	clib.print("intenal readme not found\n")
    	clib.exit(1)
        return
    end

    local i = 1
    local size = clib.get_str_size(content)
    local codeof_size = clib.get_str_size(CODEOF_TEXT)

    local colecting = false
    local final_text = ""
    local path = ""
    while i < size do

        if is_codeof_at_point(content,i) then
            colecting = true
            i = i + codeof_size+1
        end
        local is_end_char = clib.get_char(content,i) == "\n"

        if colecting and not  is_end_char   then
            path = path..clib.get_char(content,i)
        end

        if colecting ==false then
        	final_text = final_text..clib.get_char(content,i)
        end

        if colecting and is_end_char then
            path = clib.trim(path)
        	local file_content = dtw.load_file(path)
        	if file_content == nil then

        		clib.print(ANSI_RED.."file ("..path..") not found\n")
        		clib.exit(1)
        	end

            local extension = dtw.newPath(path).get_extension()
            final_text = final_text.."\n~~~"..extension.."\n"..file_content.."\n~~~\n"
            colecting = false
            path =""
        end




    	i = i + 1
    end
    return final_text

end