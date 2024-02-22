

import Build.CToolKit as ct 
from Build.copile_all_exemples import copile_all_exemples
from Build.full_folder_zip import zip_folder

from os import remove
STARTER  = f'src/one.c'
ct.generate_amalgamated_code(STARTER,'CWebStudio.h')

copile_all_exemples('examples')


def modifier(text:str):
    return text.replace('../CWebStudio.h','CWebStudio.h')
ct.include_code_in_markdown('README.md',True,modifier)

