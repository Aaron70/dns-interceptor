from flask import Flask
from flask import request
import json
import dnsApiFunctions as dnsFunct
import base64
app = Flask(__name__)

@app.route("/api/dns_resolver", methods=['POST']) # aquí especificamos que estos endpoints aceptan solicitudes POST y GET.
def dnsResolver():
    param = request.get_json().get("data")
    #test = dnsFunct.base64Encoder(str(param))
    #print (param)
    jsonDecoded = dnsFunct.base64Decoder(str(param))
    print ("Hola, es una prueba", jsonDecoded)
    dnsPackage = dnsFunct.socketUdp(jsonDecoded)
    print ("Res :", dnsPackage)
    encoded = base64.b64encode(dnsPackage)
    return encoded
app.run(host='0.0.0.0')
