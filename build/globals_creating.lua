local function create_hydration()
    local text = 'const char private_cweb_hydration_js_content[] = {'
    local file, size = dtw.list_files_recursively(HYDRATION_FOLDER, true);

    for i = 1, size do
        text = text .. clib.convert_to_hexa(dtw.load_file(file[i]))
    end

    text = text .. '0 };\n\n'

    --darwin.dtw.write_file("hydration/globals.hydration.c", text)
end

function create_globals()
    create_hydration()

    local html404_text = 'const char private_cweb_404[] = {'
    local html500_text = 'const char private_cweb_500[] = {'

    html404_text = html404_text .. clib.convert_to_hexa(dtw.load_file(HTML404_BIN)) .. '0 };\n\n'
    html500_text = html500_text .. clib.convert_to_hexa(dtw.load_file(HTML500_BIN)) .. '0 };\n\n'

    local text = html404_text .. html500_text

    darwin.dtw.write_file("src/server/server_functions/globals.not_found.c", text)
end
