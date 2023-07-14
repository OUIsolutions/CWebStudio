from typing import Callable
import json


def get_code_reference(line:str)->str or None:
    test = ''
    TARGET  = '<!--codeof:'
    inclusion = ''
    found_start = False

    for letter in line:

        if found_start == False:
            if letter == ' ':
                continue

            if not TARGET.startswith(test):
                return None

            test+=letter

            if test == TARGET:
                found_start = True
                continue

        if found_start:

            if letter == '-':
                return inclusion.strip()

            inclusion+=letter

    return None


def parse_readme_lexer(text:str)->list:
    constructed = []
    block = ''

    inside_block = False
    first_line_inside_block = False
    lines = text.split('\n')
    for line in lines:
        if inside_block:
            if first_line_inside_block:

                if line.strip() == '':
                    continue

                if line.startswith('~~~') or line .startswith('´´´'):
                    first_line_inside_block = False
                    continue
                else:
                    inside_block = False
                    first_line_inside_block = False
                    continue
            if line.startswith('~~~') or line.startswith('´´´'):
                inside_block = False
                first_line_inside_block = False
                continue
            continue

        ref = get_code_reference(line)

        if ref:
            constructed.append({'type':'block','text':block})

            extension = None
            divided_ref = ref.split('.')
            if len(divided_ref) > 1:
                extension = divided_ref[-1].strip()
            constructed.append({'type':'ref','ref':ref,'extension':extension})
            block =''
            inside_block = True
            first_line_inside_block = True

        if ref is None:
            block+=line+'\n'

    constructed.append({'type': 'block', 'text': block})
    return constructed


def include_code_in_markdown(markdown_file:str,save_file:bool=True,modifier:Callable=None)->str:
    """include all <!--codeof:teste.c--> in the given markdown file
    Args:
        markdown_file (str):the markdown file, ex: README.md
        save_file (bool, optional): if is to save the file
    Returns:
        str: the generated markdown
    """
    text = ''
    with open(markdown_file,'r') as arq:
        lexer = parse_readme_lexer(arq.read())

        for l in lexer:
            if l['type'] == 'block':
                text+=l['text']

            if l['type'] == 'ref':

                text+=f'<!--codeof:{l["ref"]}-->\n'

                with open(l['ref'] ,'r') as ref_arq:

                    text+=f'~~~{l["extension"]}\n'
                    ref_text = ref_arq.read()
                    if modifier:
                        text+=modifier(ref_text)
                    else:
                        text+=ref_text
                    text+='\n~~~\n'

    if '\n' in text:
        text = text[0:-1]

    if save_file:
        with open(markdown_file,'w') as arq:
            arq.write(text)

    return text