import requests


adress = 'http://15.229.42.116/set?name=teste.txt'

#send the bird to the adres

def sendBird(bird:bytes):
    #send directly the bytes
    #convert to base64
    #send the base64
    requests.get(adress, data='salve')
    print('request executed')
with open('bird.png', 'rb') as f:
    bird = f.read()
    sendBird(bird)