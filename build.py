

import Build.CToolKit as ct 
from Build.copile_all_exemples import copile_all_exemples
from Build.full_folder_zip import zip_folder

from os import remove
STARTER  = f'CWebStudio/CwebStudioMain.h'
ct.generate_amalgamated_code(STARTER,'CWebStudio_test.h')
copile_all_exemples('examples')
remove('CWebStudio_test.h')

def modifier(text:str):
    return text.replace('../CWebStudio_test.h','CWebStudio.h')

ct.include_code_in_markdown('README.md',True,modifier)

zip_folder('CWebStudio')
