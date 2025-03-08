function install_dependencies()
    local hasher = darwin.dtw.newHasher()
    hasher.digest_folder_by_content("dependencies")
    local EXPECTED_SHA = '76163fc7939200269ecdb2d9cbf817fbf715503cad34355557a944cd0485d1ed'
    if hasher.get_value() == EXPECTED_SHA then
        return
    end

    darwin.dtw.remove_any("dependencies")
    os.execute("mkdir dependencies")
    os


    local new_hasher = darwin.dtw.newHasher()
    new_hasher.digest_folder_by_content("dependencies")
    print("new hasher is: " .. new_hasher.get_value())
end
