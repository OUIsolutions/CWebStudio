local function main()
    local src_sha = Generate_sha_from_folder_not_considering_empty_folders(LIB_FOLDER)
    local cache = NewCache(CACHE_POINT)
    local amalgamation_cache = cache.new_element("amalgamation", function()
        return Generate_amalgamation_recursive(START_POINT)
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
