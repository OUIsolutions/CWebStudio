import requests
text = ''
for x in range(3000):
    text+='w'
    
r = requests.get(f'http://localhost:5001/?z={text}')

print(r.content)