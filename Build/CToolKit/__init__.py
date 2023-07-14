
from .amalgamation import  generate_amalgamated_code
from .ComandLineExecution import ComandLineExecution
from .comand_line_functions import compile_project_by_command
from .comand_line_functions import compile_project
from .comand_line_functions import test_binary_with_valgrind
from .comand_line_functions import execute_test_for_file
from .FolderTestPreset.FolderTestPreset import FolderTestPreset

from .Errors.CopilationError import CopilationError
from .Errors.CopilationWarning import CopilationWarning
from .Errors.ExecutionError import ExecutionError
from .Errors.ValgrindError import ValgrindError
from .Errors.ValgrindLeak import ValgrindLeak
from .Errors.NotExpectedResult import NotExpectedResult

from .readme_converter import include_code_in_markdown