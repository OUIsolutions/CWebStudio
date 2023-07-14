

def convert_num(num:str)->str:
    return int(num.replace(',',''))





def parse_block_line_based_on_key(text:str,key:str)->dict:
    if key not in text:
        return {'bytes':0,'blocks':0}
    
    target = text.split(key)[1]
    elements = target.split(' ')

    return {
        'bytes':convert_num(elements[1]),
        'blocks':convert_num(elements[4])
    }


def extract_output(text:str):
    target = text.split('Command:')[1]
    return target.split('==')[2]

    
def parse_heap_usage(text:str)->dict:
    target = text.split('total heap usage')[1]
    positions = target.split(' ')
    return {
        'allocs':convert_num(positions[1]),
        'frees':convert_num(positions[3]),
        'bytes allocated': convert_num(positions[5])
    }
    
    
def parse_valgrind_result(text:str)->dict:
    
    result  = {
        'output': extract_output(text),
        'in use at exit':parse_block_line_based_on_key(text,'in use at exit:'),
        'definitely lost':parse_block_line_based_on_key(text,'definitely lost:'),
        'indirectly lost':parse_block_line_based_on_key(text,'indirectly lost:'),
        'possibly lost':parse_block_line_based_on_key(text,'possibly lost:'),
        'still reachable':parse_block_line_based_on_key(text,'still reachable:'),
        'suppressed':parse_block_line_based_on_key(text,' suppressed:'),
        'heap usage': parse_heap_usage(text)
    }
    
    return result

    