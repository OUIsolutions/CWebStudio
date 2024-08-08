local function main()
    local src_sha = Generate_sha_from_folder_not_considering_empty_folders(LIB_FOLDER)
    local cache = NewCache(CACHE_POINT)



    local amalgamation_cache = cache.new_element("amalgamation", function()
        return Generate_amalgamation_recursive(START_POINT)
    end).add_dependencie(src_sha)
    local amalgamation_result = Generate_amalgamation_recursive(START_POINT)
    dtw.write_file(END_TEST_POINT, amalgamation_result)

    Execute_all_tests()
    Create_examples()
    local readme = Create_readme()
    if readme then
        dtw.write_file("README.md", readme)
    end
end

main()
