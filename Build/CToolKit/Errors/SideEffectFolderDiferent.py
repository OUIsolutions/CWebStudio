

class SideEffectFolderDiferent(Exception):

    def __init__(self,side_effect_folder:str):
        self.mensage = side_effect_folder
        super().__init__(self.mensage)
