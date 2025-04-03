
function convert_to_number(str)
    local seq = {}
    for i=1,#str do
        local current_char = string.sub(str, i, i)
        local byte = string.byte(current_char)
        seq[i] = string.format("%d", byte)
    end 
    seq[#seq + 1] = 0
    return table.concat(seq, ",")
end

local function create_hydration()
    local text = 'unsigned char private_cweb_hydration_js_content[] = {'
    local file, size = darwin.dtw.list_files_recursively("bin/hydration", true);

    for i = 1, size do
        text = text ..convert_to_number(darwin.dtw.load_file(file[i]))
    end

    text = text .. ' };\n\n'

    darwin.dtw.write_file("src/hydratation/hydration/globals.hydration.c", text)
end

function create_globals()
    create_hydration()

    local html404_text = 'unsigned char private_cweb_404[] = {'
    local html500_text = 'unsigned char private_cweb_500[] = {'

    html404_text = html404_text ..convert_to_number(darwin.dtw.load_file("bin/404.html")) .. ' };\n\n'
    html500_text = html500_text .. convert_to_number(darwin.dtw.load_file("bin/500.html")) .. ' };\n\n'

    local text = html404_text .. html500_text

    darwin.dtw.write_file("src/server/server_functions/globals.not_found.c", text)
end
