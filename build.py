

import CToolKit as ct
from os import listdir,remove
from os.path import  isdir
from os import remove


def copile_all_exemples(folder:str):
    print(f'folder: {folder}')
    elements = listdir('exemples')

    for file in elements:
        filepath = f'{folder}/{file}'
        if isdir(filepath):
            copile_all_exemples(filepath)
        
        try:
            output =   ct.compile_project('gcc',filepath)
            remove(output)
            print(f'\tpassed:{filepath}')

        except Exception as e:
            try:
                remove(output)
            except:pass 
            print(f'\tfaluired:{filepath}')
            raise e 
        

STARTER  = f'CWebStudio/CwebStudioMain.h'
ct.generate_amalgamated_code(STARTER,'CWebStudio_test.h')
try:
    copile_all_exemples('exemples')
except Exception as e:
    raise e

def modifier(text:str):
    return text.replace('../CWebStudio_test.h','CWebStudio.h')

ct.include_code_in_markdown('README.md',True,modifier)

