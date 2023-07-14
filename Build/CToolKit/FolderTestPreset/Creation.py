from typing import List
from os import listdir
from shutil import copytree,rmtree

from os.path import  isdir
from .Extras import FolderTestPresetExtras
from ..ComandLineExecution import ComandLineExecution
from ..comand_line_functions import execute_test_for_file




class FolderTestPressetCreation(FolderTestPresetExtras):

    def _execute_test_presset_creating_output(self, folder: str):
        self._rebase_side_effect_folder()

        execution_file = self._get_file_to_execute(folder)
        expected_file = self._get_expected_file(folder)


        generated_result: dict or ComandLineExecution = execute_test_for_file(
                file=execution_file,
                compiler=self._compiler,
                copilation_flags=self._compilation_flags,
                execution_flags=self._execution_flags,
                use_valgrind=self._use_valgrind,
                raise_warnings=self._raise_warnings
        )

        modified = False


        if self._side_effect_folder_changed():
            #verify if there is no test presseted
            if not isdir(f'{folder}/side_effect'):
                copytree(self._side_effect_folder, f'{folder}/side_effect')
                modified = True

        if expected_file is None:
            if isinstance(generated_result, ComandLineExecution):
                output = generated_result.output
            else:
                output = generated_result['output']

            with open(f'{folder}/expected.txt', 'w') as arq:
                arq.write(output)
            modified = True


        if modified:
            self._print_if_setted_to_print_creation(execution_file, True)
        else:
            self._print_if_setted_to_print_creation(execution_file, False)


    def _execute_loop_creating_expected(self, folder: str):
        self._print_if_seetted_to_print_folder(folder)

        elements: List[str] = listdir(folder)
        for e in elements:
            path = f'{folder}/{e}'

            if not isdir(path):
                continue

            if e.startswith('T_') :
                try:
                    self._execute_test_presset_creating_output(path)
                except Exception as ex:
                    self._print_if_setted_to_print_test(e, False)
                    raise ex
                continue

            self._execute_loop_creating_expected(path)

    def generate_ouptut(self):
        self._create_copy_side_effect_folder()
        try:
            self._execute_loop_creating_expected(self._folder)
        except Exception as e:
            self._rebase_side_effect_folder()
            rmtree('side_effect_copy', ignore_errors=True)
            raise e

        self._rebase_side_effect_folder()
        rmtree('side_effect_copy', ignore_errors=True)

