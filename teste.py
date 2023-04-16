import requests
import base64

adress = 'http://15.229.42.116/set'

#send the bird to the adres

def sendBird(bird:bytes):
    #send directly the bytes
    #convert to base64
    in_base64 = base64.b64encode(bird)
    #send to the server
    r = requests.post(adress, data = in_base64)
    
with open('bird.png', 'rb') as f:
    bird = f.read()
    sendBird(bird)