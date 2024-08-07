function Create_examples()
    local files, size = dtw.list_files(TESTS_FILES)
    for i = 1, size do
        local current = files[i]
        local name = dtw.newPath(current).get_name()
        local new_path = dtw.concat_path(EXAMPLES_FOLDER, name);
        dtw.copy_any_overwriting(current, new_path)
    end
end
