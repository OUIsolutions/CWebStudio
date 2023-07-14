from .Constructor import  FolderTestPresetConstructor

class FolderTestPressetPrints(FolderTestPresetConstructor):

    def _print_if_setted_to_print_test(self, element: str, passed: bool):
        if not self._print_values:
            return
        if passed:
            print('\033[92m' + f'\tpassed : {element}')
        else:
            print('\033[91m' + f'\tfail : {element}')

        print('\033[0m',end='')

    def _print_if_setted_to_print_creation(self, element: str, created: bool):
        if not self._print_values:
            return
        if created:
            print('\033[96m' + f'\tcreated: {element}')
        else:
            print('\033[94m' + f'\talready exist: {element}')

        print('\033[0m',end='')

    def _print_if_seetted_to_print_folder(self, folder: str):
        if self._print_values:
            print(f'folder :{folder}')

