function Create_examples()
    local files, size = dtw.list_files(TESTS_FILES, true)
    for i = 1, size do
        local current = files[i]
        local name = dtw.newPath(current).get_name()
        local new_path = dtw.concat_path(EXAMPLES_FOLDER, name);
        local content = dtw.load_file(current)
        local new_content = clib.replace(content, "../", "")
        dtw.write_file(new_path, new_content)
    end
end
