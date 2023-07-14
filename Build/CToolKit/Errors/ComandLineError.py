

class ComandLineError(Exception):

    def __init__(self, message: str, status_code: int):
        self.status_code = status_code
        self.message = message

    def __str__(self):
        text = f'Mensage: {self.message}\n'
        text += f'Status Code: {self.status_code}\n'
        return text


