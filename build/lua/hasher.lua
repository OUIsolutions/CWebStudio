
---@param folder string
---@return string
function Generate_sha_from_folder_not_considering_empty_folders(folder)
	local hasher = dtw.newHasher()
	local files,files_size = dtw.list_files_recursively(folder)
	for i=1,files_size do
	    local current_file = files[i]
	    local file_path = dtw.concat_path(folder,current_file)
	    local content = dtw.load_file(file_path)
		hasher.digest(current_file)
		hasher.digest(content)
	end
	local dirs,dirs_size = dtw.list_dirs_recursively(folder)
	for i=1,dirs_size do
	    local current_dir = dirs[i]
	    local dir_path = dtw.concat_path(folder,current_dir)
		local ignore,size= dtw.list_files_recursively(dir_path,false)
		if size > 0 then
			hasher.digest(current_dir)
		end
	end
	return hasher.get_value()
end
