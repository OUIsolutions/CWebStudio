function install_dependencies()
    local hasher = darwin.dtw.newHasher()
    hasher.digest_folder_by_content("dependencies")
    local EXPECTED_SHA = '140d7c22f8eb9a9c006700dae358bfc0e77bfd54bffb76069d74c35010f107b4'
    if hasher.get_value() == EXPECTED_SHA then
        return
    end

    darwin.dtw.remove_any("dependencies")

    os.execute("mkdir -p dependencies")
    os.execute("curl -L https://raw.githubusercontent.com/DaveGamble/cJSON/refs/tags/v1.7.18/cJSON.c -o dependencies/cJSON.c")
    os.execute(
    "curl -L https://raw.githubusercontent.com/DaveGamble/cJSON/refs/tags/v1.7.18/cJSON.h -o dependencies/cJSON.h")

    os.execute("curl -L https://github.com/SamuelHenriqueDeMoraisVitrio/UniversalSocket/releases/download/v0.2.8/UniversalSocket.c -o dependencies/UniversalSocket.c")
    os.execute("curl -L https://github.com/SamuelHenriqueDeMoraisVitrio/UniversalSocket/releases/download/v0.2.8/UniversalSocket.h -o dependencies/UniversalSocket.h")

    os.execute("curl -L https://github.com/OUIsolutions/Universal-Garbage-Colector/releases/download/3.0.0/UniversalGarbage.c -o dependencies/UniversalGarbage.c")
    os.execute("curl -L https://github.com/OUIsolutions/Universal-Garbage-Colector/releases/download/3.0.0/UniversalGarbage.h -o dependencies/UniversalGarbage.h")   
    os.execute("curl -L https://github.com/OUIsolutions/CTextEngine/releases/download/3.0.000/CTextEngine.h -o dependencies/CTextEngine.h")
    os.execute("curl -L https://github.com/OUIsolutions/CTextEngine/releases/download/3.0.000/CTextEngine.c -o dependencies/CTextEngine.c")


    local new_hasher = darwin.dtw.newHasher()
    new_hasher.digest_folder_by_content("dependencies")
    print("new hasher is: " .. new_hasher.get_value())
end
