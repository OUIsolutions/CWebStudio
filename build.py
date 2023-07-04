

import CToolKit as ct
from os import listdir,remove



STARTER  = f'CWebStudio/CwebStudioMain.h'
ct.generate_amalgamated_code(STARTER,'CWebStudio.h')
