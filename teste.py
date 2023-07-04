import requests
text = ''
for x in range(11000):
    text+='v'
    
r = requests.get(f'http://localhost:5000/',headers={'a':text})

print(r.content)