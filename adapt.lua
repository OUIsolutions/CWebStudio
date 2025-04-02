
local files = darwin.dtw.list_files_recursively("src/config",true)

for i=1,#files do
    local current = files[i]
    local path = darwin.dtw.newPath(current)
    
    local name = path.get_name()
    
    if darwin.dtw.ends_with(name,".h") then
        path.set_name("macros."..name)        
    end

    local new_path = path.get_full_path()
    print("Renaming "..current.." to "..new_path)
    darwin.dtw.move_any_overwriting(current,new_path)
end 