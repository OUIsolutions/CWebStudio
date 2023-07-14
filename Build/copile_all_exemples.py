

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