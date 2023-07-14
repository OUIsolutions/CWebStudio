import json
from typing import List
def trim_lines(text:str)->List[str]:
    lines = text.split('\n')
    striped = list(map(lambda x: x.strip(),lines))
    return list(filter(lambda x: x != '' , striped))

def sanitize_value(filename:str,content:str=None)->dict or str or List[str]:

    if filename.endswith('.json'):
        return json.loads(content)

    if 'not_trim' in filename:
        return content

    return trim_lines(content)

