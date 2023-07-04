import requests
text = ''
for x in range(5000):
    text+='w'
    
r = requests.get(f'http://localhost:5001/{text}')

print(r.content)