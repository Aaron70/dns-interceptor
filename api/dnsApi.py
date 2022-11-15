from flask import Flask
from flask import request
import json
app = Flask(__name__)

@app.route("/api/dns_resolver", methods=['POST']) # aquí especificamos que estos endpoints aceptan solicitudes POST y GET.
def dnsResolver():
    param = request.get_json().get("data")
    print(str(param))
    return str(param)
app.run(host='0.0.0.0')
