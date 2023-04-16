import requests
import base64

adress = 'http://localhost:8080/set?name=teste.png'

#send the bird to the adres

def send_file(element:bytes):
    #send directly the bytes
    #convert to base64
    #send the base64
    requests.post(adress, data=element,stream=True)
    print('request executed')


with open('bird.png', 'rb') as f:
    bird = f.read()
    send_file(bird)
  