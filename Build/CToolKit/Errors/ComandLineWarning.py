

class ComandLineWarning(Exception):

    def __init__(self, message: str):
        self.status_code = 0
        self.message = message

    def __str__(self):
        text = f'Mensage: {self.message}\n'
        return text

