import requests
text = ''
for x in range(3000):
    text+='c'
    
r = requests.get(f'http://localhost:5000/?a={text}')

print(r.content)