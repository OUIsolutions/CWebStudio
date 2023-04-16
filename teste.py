import requests
import base64

adress = 'http://15.229.42.116/set?name=teste.png'

#send the bird to the adres

def send_file(element:bytes):
    #send directly the bytes
    #convert to base64
    #send the base64
    element_in_base64 = base64.b64encode(element)
    requests.post(adress, data=element_in_base64)
    print('request executed')


with open('PySchema.png', 'rb') as f:
    bird = f.read()
    send_file(bird)
  