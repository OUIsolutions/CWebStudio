
function build_declaration()

    local MAX_CONNTENT = darwin.camalgamator.ONE_MB * 20
    local MAX_RECURSION = 100

    local lincense = "/* " .. darwin.dtw.load_file("LICENSE") .. " */ \n"


    local only_declare = darwin.camalgamator.generate_amalgamation("src/imports/imports.fdeclare.h", MAX_CONNTENT,
    MAX_RECURSION)
    only_declare = lincense .. only_declare
    darwin.dtw.write_file("release/CWebStudio.h", only_declare)

end
darwin.add_recipe({
    name="declaration",
    description="Builds the CWebStudio.h file with the declaration of the project",
    callback=build_declaration,
    outs={"release/CWebStudio.h"}
})