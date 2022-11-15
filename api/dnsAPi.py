from flask import Flask
from flask import request
import json
import dnsApiFunctions as dnsFunct
app = Flask(__name__)

@app.route("/api/dns_resolver", methods=['POST']) # aquí especificamos que estos endpoints aceptan solicitudes POST y GET.
def dnsResolver():
    param = request.get_json().get("data")
    #test = dnsFunct.base64Encoder(str(param))
    jsonDecoded = dnsFunct.base64Decoder(str(param))
    dnsPackage = dnsFunct.socketUdp(jsonDecoded)
    return dnsPackage
app.run(host='0.0.0.0')
