from typing import List

class FolderTestPresetConstructor:

    def __init__(
            self,
            folder:str,
            side_effect_folder:str =None,
            compiler='gcc',
            compilation_flags:List[str]=None,
            execution_flags:List[str]=None,
            print_values=True,
            use_valgrind=True,
            raise_warnings=True
    ):
        self._folder = folder
        self._side_effect_folder = side_effect_folder
        self._compiler =compiler
        self._compilation_flags = compilation_flags
        self._execution_flags = execution_flags
        self._print_values = print_values
        self._use_valgrind = use_valgrind
        self._raise_warnings = raise_warnings
