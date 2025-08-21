
function build_definition()
    local MAX_CONNTENT = darwin.camalgamator.ONE_MB * 20
    local MAX_RECURSION = 100

    local lincense = "/* " .. darwin.dtw.load_file("LICENSE") .. " */ \n"

    local onefile = darwin.camalgamator.generate_amalgamation("src/one.c", MAX_CONNTENT, MAX_RECURSION)
    onefile = lincense .. onefile

    darwin.dtw.write_file("release/CWebStudioOne.c", onefile)

end 
darwin.add_recipe({
    name="onefile",
    description="Builds the CWebStudioOne.c file with all the dependencies inside",
    callback=build_definition,
    outs={"release/CWebStudioOne.c"}
})