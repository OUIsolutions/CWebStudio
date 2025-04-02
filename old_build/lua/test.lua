---@param file string
---@param compiler string
local function execute_c_tests(file, compiler)
    local result = clib.system_with_status(compiler .. " " .. file)
    if result ~= 0 then
        clib.print(ANSI_RED .. "file " .. file .. " not passed in gcc\n")
        clib.exit(1)
    end
end

function Execute_all_tests()
    local files, size = dtw.list_files(TESTS_FILES, true)
    for i = 1, size do
        local current = files[i]
        execute_c_tests(current, "gcc")
        execute_c_tests(current, "g++")
        clib.print(ANSI_GREEN .. current .. " passed \n")
    end
end
