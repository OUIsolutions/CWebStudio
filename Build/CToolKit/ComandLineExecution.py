from .Errors.ExecutionError import ExecutionError
import subprocess


class ComandLineExecution:
    def __init__(self, command: str):
        """Execute the given comands
        Args:
            command (str):the comand to execute
        Raises:
            ExecutionError: if happen some execution error
        """
        self.status_code, self.output = subprocess.getstatusoutput(command)

        if self.status_code != 0:
            raise ExecutionError(self.output, self.status_code)
