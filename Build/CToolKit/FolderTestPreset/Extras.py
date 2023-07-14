
from .Print import FolderTestPressetPrints
from os import listdir

from os.path import isdir,isfile
import os
import shutil
from shutil import rmtree,copytree
from .folder_hash import are_folders_equal

class FolderTestPresetExtras(FolderTestPressetPrints):

    def _get_expected_file(self, folder: str):
        elements = listdir(folder)
        for e in elements:
            if isdir(e):
                continue

            if e.startswith('expected'):
                return f'{folder}/{e}'


    def _get_file_to_execute(self, folder: str):
        c_file = f'{folder}/exec.c'
        cpp_file = f'{folder}/exec.cpp'

        if isfile(c_file):
            return c_file

        if isfile(cpp_file):
            return cpp_file

        raise FileNotFoundError(f'could not locate an exec.c or exec.cpp in {folder}')


    def _create_copy_side_effect_folder(self):
        if self._side_effect_folder is None:
            return
        rmtree('side_effect_copy', ignore_errors=True)
        copytree(self._side_effect_folder,'side_effect_copy')




    def _side_effect_folder_changed(self)->bool:
        return not are_folders_equal(self._side_effect_folder,'side_effect_copy')



    def _rebase_side_effect_folder(self):
        rmtree(self._side_effect_folder,ignore_errors=True)
        copytree(f'side_effect_copy',self._side_effect_folder)














