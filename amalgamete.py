from sys import exit
from os.path import join

def get_inclusion_dir(referencer_dir:str, line:str)->str or None:
    line = line.strip()
    if not line.startswith('#include'):
        return None
    
    if '"' in line:
        relative_file =  line.split('"')[1]
        return join(referencer_dir,relative_file)


def get_amalgamated_code(starter:str)->str:
 
    current_text = ''
    try:
        with open(starter) as f:
            #get current dir name
            current_dir = '/'.join(starter.split('/')[:-1])
            lines = f.readlines()
            for line in lines:
                ##trim line 
                file_to_include =  get_inclusion_dir(current_dir,line)
                if not file_to_include:
                   current_text += line
                   continue

                current_text += get_amalgamated_code(file_to_include)
                    
    except FileNotFoundError:
        print(f'FileNotFoundError: {starter}')
        exit(1)

    return current_text




def main():
    OUTPUT = 'YourOutput.h'
    STARTER  =f'YourProject/YourMainFile.h'
    amalgamated_code = get_amalgamated_code(STARTER)
    with open(OUTPUT,'w') as f:
        f.write(amalgamated_code)

if __name__ == '__main__':
    main()

