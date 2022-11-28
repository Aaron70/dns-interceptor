from flask import Flask
from flask import request
import json
import dnsApiFunctions as dnsFunct
import base64
import os
app = Flask(__name__)

@app.route("/api/dns_resolver", methods=['POST']) #Especifica que los endpoints aceptan solicitudes POST y GET.
def dnsResolver():
    param = request.get_json().get("data")
    jsonDecoded = dnsFunct.base64Decoder(str(param))
    dns = os.environ.get("DNS_IP")
    dnsPackage = dnsFunct.socketUdp(jsonDecoded,dns)
    encoded = base64.b64encode(dnsPackage)
    return encoded
app.run(host='0.0.0.0')
