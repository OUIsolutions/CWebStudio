


function convert_to_number(str)
    local seq = {}
    for i=1,#str do
        local current_char = string.sub(str, i, i)
        local byte = string.byte(current_char)
        
        seq[i] = byte
    end 
    return table.concat(seq, ",")
end

local function create_hydration()
    local text = 'unsigned char private_cweb_hydration_js_content[] = {'
    local file, size = darwin.dtw.list_files_recursively("bin/hydration", true);

    for i = 1, size do
        local current_file = file[i]
        local current_content = darwin.dtw.load_file(current_file)

        text = text ..convert_to_number(current_content)..','
    end

    text = text .. '0};\n\n'

    darwin.dtw.write_file("src/hydratation/hydration/globals.hydration.c", text)
end

function create_globals()
    create_hydration()

    local html404_text = 'unsigned char private_cweb_404[] = {'
    local html500_text = 'unsigned char private_cweb_500[] = {'
    local bin_404 = darwin.dtw.load_file("bin/404.html")
    local bin_500 = darwin.dtw.load_file("bin/500.html")
    html404_text = html404_text ..convert_to_number(bin_404) .. ',0};\n\n'
    html500_text = html500_text .. convert_to_number(bin_500) .. ',0};\n\n'

    local text = html404_text .. html500_text

    darwin.dtw.write_file("src/server/server_functions/globals.not_found.c", text)
end


function src_build()
    create_globals()
    local content = darwin.mdeclare.transform_dir({
        dir="src",
        startswith="fdefine",
        endswith=".c",
    })

    darwin.dtw.write_file("src/fdeclare.all.h", content)
    darwin.silverchain.remove("src/fdeclare.all.h")

    darwin.silverchain.generate({
        src = "src",
        tags = { "dep_declare", "macros", "types", "fdeclare","globals", "dep_define","fdefine" },
        project_short_cut = "CWebStudio",
        implement_main = false
    })
end 

darwin.add_recipe({
    name="dir_project",
    description="Builds the src, with embed vars and perform silverchain organization",
    callback=src_build,
    outs={}
})