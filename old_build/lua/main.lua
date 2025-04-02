local function main()
    create_globals()

    local argv1 = clib.getargv(1)
    if argv1 == "global_files" then
        return
    end


    local src_sha = Generate_sha_from_folder_not_considering_empty_folders(LIB_FOLDER)
    local cache = NewCache(CACHE_POINT)
    local amalgamation_cache = cache.new_element("amalgamation", function()
        local license = dtw.load_file("LICENSE")
        license = "/*\n" .. license .. "*/\n"
        local content =  Generate_amalgamation_recursive(START_POINT)
        return license .. content .. license
    end).add_dependencie(src_sha)
    dtw.write_file(OUTPUT_SINGLE_FILE, amalgamation_cache.perform())

    Execute_all_tests()

    Create_examples()

    local readme = Create_readme()
    if readme then
        dtw.write_file("README.md", readme)
    end
end

main()
