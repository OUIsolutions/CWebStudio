from .ComandLineWarning import ComandLineWarning


class ValgrindLeak(ComandLineWarning):

    
    def __init__(self, message: str,valgrind_status:dict  ):
        super().__init__(str(message))
        self.valgrind_status = valgrind_status
     
