
local files = darwin.dtw.list_files_recursively("src",true)
for i=1,#files do
    local file = files[i]
    local filename = darwin.dtw.newPath(file)
    local name = filename.get_name()
    if darwin.dtw.starts_with(name,"fdeclare") then 
        darwin.dtw.remove_any(file)
    end 
end