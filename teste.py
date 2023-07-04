import requests
text = ''
for x in range(900):
    text+='r'
    
r = requests.get(f'http://localhost:5002/',headers={text:text})

print(r.content)